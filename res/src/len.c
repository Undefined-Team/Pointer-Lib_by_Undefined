#include "ud_pointer.h"

size_t  ud_ptr_len_ctr(void **ptr)
{
    if (!ptr) return 0;
    size_t  len = 0;
    void    *end_flag = ud_ptr_end_flag();
    while (*ptr++ || *ptr != end_flag) ++len;
    return len;
}