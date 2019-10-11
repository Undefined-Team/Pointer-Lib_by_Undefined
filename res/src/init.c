#include "ud_pointer.h"

void    **ud_ptr_init(size_t len)
{
    void **ptr = malloc((len + 1) * sizeof(void *));
    ptr[len] = NULL;
    return ptr;
}