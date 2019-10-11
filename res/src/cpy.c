#include "ud_pointer.h"

void    **ud_ptr_cpy(void **src)
{
    if (!src) return NULL;
    size_t  len = ud_ptr_len(src);
    void    **dst = ud_ptr_init(len);
    ud_mem_cpy(&dst, &src, len);
    dst[len] = NULL;
    return dst;
}