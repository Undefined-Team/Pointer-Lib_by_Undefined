#include "ud_pointer.h"

size_t  ud_ptr_len_ctr(void **ptr)
{
    if (!ptr) return 0;
    size_t  len = 0;
    while (*ptr++) ++len;
    return len;
}