#include "inner_head.h"

int main() {
    int extension_type = 1;
    int found_extension_type = 2;
    // CHECK-MESSAGES: [[@LINE+1]]: warning : kirin feature test rule: [SecH_Cxx_Test_main]
    POSIX_ENSURE(found_extension_type == extension_type, S2N_ERR_INVALID_PARSED_EXTENSIONS);
}