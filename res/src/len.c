#include "ud_pointer.h"

void    ud_ptr_len(void **ptr)
{
    size_t  len = 0;
    while (*ptr++) ++len;
    return len;
}