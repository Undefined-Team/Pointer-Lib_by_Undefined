#include "ud_pointer.h"

void    ud_ptr_free_ctr(void **ptr, size_t depth)
{
    if (depth--) for (void **ptr_tmp = ptr; *ptr_tmp;) ud_ptr_free(*ptr_tmp++, depth);
    ud_ut_free(ptr);
}