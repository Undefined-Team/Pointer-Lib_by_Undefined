#include "ud_pointer.h"

void    **ud_ptr_init_flag_ctr(size_t len)
{
    void    **ptr;
    ud_ut_prot_malloc(ptr = ud_ut_malloc((len + 2) * sizeof(void *)));
    ptr[len] = NULL;
    ptr[len + 1] = ud_ptr_end_flag();
    return ptr;
}

void    **ud_ptr_init_ctr(size_t len)
{
    void    **ptr;
    ud_ut_prot_malloc(ptr = ud_ut_malloc((len + 1) * sizeof(void *)));
    ptr[len] = NULL;
    return ptr;
}