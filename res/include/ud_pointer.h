#ifndef UD_POINTER_H
# define UD_POINTER_H

// Lib
#include <stdlib.h>
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define    ud_ptr_set(type, ...)   ({ type ptr; type in_val[] = {__VA_ARGS__}; size_t len = sizeof(in_val) / sizeof(type); ptr = ud_ptr_init(len); type p_ptr = ptr; for (ud_ut_count i = 0; i < len; ++i, ++p_ptr) *p_ptr = in_val[i]; ptr; })
/*
# define    ud_ptr_set(type, ...) \
    ({ \
        type ptr; \
        type in_val[] = {__VA_ARGS__}; \
        size_t len = sizeof(in_val) / sizeof(type); \
        ptr = ud_ptr_init(len); \
        type p_ptr = ptr; \
        for (ud_ut_count i = 0; i < len; ++i, ++p_ptr) *p_ptr = in_val[i]; \
        ptr; \
    })
*/

// Structures

// Prototypes
size_t      ud_ptr_len(void **ptr);
void        **ud_ptr_init(size_t len);
void        **ud_ptr_cpy(void **src)

#endif
