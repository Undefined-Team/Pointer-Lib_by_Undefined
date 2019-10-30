#include "ud_pointer.h"

void    ud_ptr_rm_idx_ctr(void ***ptr_i, size_t index, int depth)
{
    void **ptr = *ptr_i;
    if (!ptr) return ;
    size_t ptr_len = ud_ptr_len(ptr);
    if (index >= ptr_len) return ;
    size_t type_size = sizeof(void*);
    void **new_ptr = ud_ut_malloc(type_size * ptr_len);
    void **new_ptr_tmp = new_ptr;
    void **ptr_tmp = ptr;
    ud_mem_cpy_rds(new_ptr_tmp, ptr_tmp, type_size * index);
    if (depth >= 0 && *ptr_tmp) ud_ptr_free(*ptr_tmp, depth);
    ++ptr_tmp;
    ud_mem_cpy_rds(new_ptr_tmp, ptr_tmp, type_size * (ptr_len - index));
    ud_ut_free(ptr);
    *ptr_i = new_ptr;
}