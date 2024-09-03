typedef enum {
    S2N_ERR_OK,
    S2N_ERR_INVALID_PARSED_EXTENSIONS
} s2n_error;

#define TO_STRING(s) #s
#define STRING_(s) TO_STRING(s)
#define STRING__LINE__ STRING_(__LINE__)

#define _S2N_DEBUG_LINE     "Error encountered in " __FILE__ ":" STRING__LINE__

const char *s2n_debug_str;
int s2n_errno;

#define _S2N_ERROR( x )     do { s2n_debug_str = _S2N_DEBUG_LINE; s2n_errno = ( x ); s2n_calculate_stacktrace(); } while (0)

#define POSIX_BAIL(error)                                     do { _S2N_ERROR((error)); return -1; } while (0)

#define __S2N_ENSURE( cond, action ) do {if ( !(cond) ) { action; }} while (0)

int s2n_calculate_stacktrace(void)
{
    return -1;
}

/**
 * Ensures the `condition` is `true`, otherwise the function will `POSIX_BAIL` with `error`
 */
#define POSIX_ENSURE(condition, error)                        __S2N_ENSURE((condition), POSIX_BAIL(error))
