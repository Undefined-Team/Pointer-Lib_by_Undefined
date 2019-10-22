#ifndef UD_POINTER_H
# define UD_POINTER_H

// Lib
#include <stdlib.h>
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define    ud_ptr_set(type, ...) ({ type *ptr; type in_val[] = {__VA_ARGS__}; type *in_val_tmp = in_val; size_t len = sizeof(in_val) / sizeof(type); ptr = ud_ptr_init(type, len); type *p_ptr = ptr; for (ud_ut_count i = 0; i < len; ++i) *p_ptr++ = *in_val_tmp++; ptr; })
/*
# define    ud_ptr_set(type, ...) \
    ({ \
        type *ptr; \
        type in_val[] = {__VA_ARGS__}; \
        type *in_val_tmp = in_val; \
        size_t len = sizeof(in_val) / sizeof(type); \
        ptr = ud_ptr_init(type, len); \
        type *p_ptr = ptr; \
        for (ud_ut_count i = 0; i < len; ++i) *p_ptr++ = *in_val_tmp++; \
        ptr; \
    })
*/

# define    ud_ptr_fp(ptr, function, ...)   ({ if (ptr) while (*ptr) function(*ptr++, __VA_ARGS__); })

# define    ud_ptr_cpy(type, ptr)           (type *)ud_ptr_cpy_ctr((void **)ptr)
# define    ud_ptr_len(ptr)                 ud_ptr_len_ctr((void **)ptr)
# define    ud_ptr_init(type, len)          (type *)ud_ptr_init_ctr(len)
# define    ud_ptr_free(ptr, depth)         ud_ptr_free_ctr((void**)ptr, depth)

// Structures

// Prototypes
size_t      ud_ptr_len_ctr(void **ptr);
void        **ud_ptr_init_ctr(size_t len);
void        **ud_ptr_cpy_ctr(void **src);

#endif
