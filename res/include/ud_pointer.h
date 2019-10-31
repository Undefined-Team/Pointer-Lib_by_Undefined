#ifndef UD_POINTER_H
# define UD_POINTER_H

// Lib
#include <stdlib.h>
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define    ud_ptr_set(...)                     ud_ut_array(__VA_ARGS__, NULL)

# define    ud_ptr_foreach(_ptr, _name, _action) \
    ({ \
        if (_ptr) \
        { \
            typeof(*_ptr)* _name = _ptr; \
            if (_name) for (;*_name;++_name) ({ _action }); \
        } \
    })

# define    ud_ptr_cpy(_ptr)                    ({ __auto_type _ptrt = _ptr; (typeof(_ptrt))ud_ptr_cpy_ctr((void **)_ptrt); })
# define    ud_ptr_len(_ptr)                    ud_ptr_len_ctr((void **)_ptr)
# define    ud_ptr_init(_type, _len)            (_type *)ud_ptr_init_ctr(_len)
# define    ud_ptr_free(_ptr, _depth)           ud_ptr_free_ctr((void**)_ptr, _depth)
# define    ud_ptr_rm_idx(_ptr, _index, _depth) ud_ptr_rm_idx_ctr((void***)&(_ptr), _index, _depth);
# define    ud_ptr_rm_adr(_ptr, _adr, _depth)   ({ if (_ptr) ud_ptr_rm_idx(_ptr, (_adr - *(_ptr)) / sizeof(_adr), _depth); })

// Structures

// Prototypes
size_t      ud_ptr_len_ctr(void **ptr);
void        **ud_ptr_init_ctr(size_t len);
void        **ud_ptr_cpy_ctr(void **src);
void        ud_ptr_free_ctr(void **ptr, size_t depth);
void        ud_ptr_rm_idx_ctr(void ***ptr_i, size_t index, int depth);

#endif
