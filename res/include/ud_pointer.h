#ifndef UD_POINTER_H
# define UD_POINTER_H

// Lib
#include <stdlib.h>
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define    ud_ptr_set(...)                     ud_ut_array(__VA_ARGS__, NULL)

# define    ud_ptr_foreach(ptr, name, action) \
    ({ \
        if (ptr) \
        { \
            typeof(*ptr)* name = ptr; \
            if (name) for (;*name;++name) ({ action }); \
        } \
    })

# define    ud_ptr_cpy(ptr)                     (typeof(ptr))ud_ptr_cpy_ctr((void **)ptr)
# define    ud_ptr_len(ptr)                     ud_ptr_len_ctr((void **)ptr)
# define    ud_ptr_init(type, len)              (type *)ud_ptr_init_ctr(len)
# define    ud_ptr_free(ptr, depth)             ud_ptr_free_ctr((void**)ptr, depth)
# define    ud_ptr_rm_idx(ptr, index, depth)    ud_ptr_rm_idx_ctr((void***)&ptr, index, depth);
# define    ud_ptr_rm_adr(ptr, adr, depth)      ({ if (ptr) ud_ptr_rm_idx(ptr, (adr - *ptr) / sizeof(adr), depth); })
// Structures

// Prototypes
size_t      ud_ptr_len_ctr(void **ptr);
size_t      ud_ptr_len_flag_ctr(void **ptr);
void        **ud_ptr_init_ctr(size_t len);
void        **ud_ptr_cpy_ctr(void **src);
void        ud_ptr_free_ctr(void **ptr, size_t depth);
void        ud_ptr_rm_idx_ctr(void ***ptr_i, size_t index, int depth);

#endif
