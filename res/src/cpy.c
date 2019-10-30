#include "ud_pointer.h"

void    **ud_ptr_cpy_ctr(void **src)
{
    if (!src) return NULL;
    size_t  len = ud_ptr_len(src);
    void    **dst = ud_ptr_init(void *, len);
    ud_mem_cpy(dst, src, ++len * sizeof(void*));
    return dst;
}