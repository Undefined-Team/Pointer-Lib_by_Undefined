#ifndef UD_POINTER_H
# define UD_POINTER_H

// Lib
#include <stdlib.h>
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define    ud_ptr_set(ctype, ...)          ud_ut_array(ctype, __VA_ARGS__, NULL, (ctype)ud_ptr_end_flag())

# define    ud_ptr_foreach(ptr, name, action) \
    ({ \
        if (ptr) \
        { \
            typeof(*ptr)* name = ptr; \
            if (name) for (;*name;++name) ({ action }); \
        } \
    })

# define    ud_ptr_cpy(ptr)                 (typeof(ptr))ud_ptr_cpy_ctr((void **)ptr)
# define    ud_ptr_len(ptr)                 ud_ptr_len_ctr((void **)ptr)
# define    ud_ptr_init(type, len)          (type *)ud_ptr_init_ctr(len)
# define    ud_ptr_free(ptr, depth)         ud_ptr_free_ctr((void**)ptr, depth)

// Structures

// Prototypes
size_t      ud_ptr_len_ctr(void **ptr);
void        **ud_ptr_init_ctr(size_t len);
void        **ud_ptr_cpy_ctr(void **src);
void        *ud_ptr_end_flag(void);

#endif
