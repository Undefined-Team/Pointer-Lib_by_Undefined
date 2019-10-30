#include "ud_pointer.h"

void    **ud_ptr_init_ctr(size_t len)
{
    void    **ptr;
    ud_ut_prot_malloc(ptr = ud_ut_malloc((len + 1) * sizeof(void *)));
    ptr[len] = NULL;
    return ptr;
}