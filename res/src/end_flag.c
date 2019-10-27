#include "ud_pointer.h"

void    *ud_ptr_end_flag(void)
{
    static char *end_flag = NULL;
    if (!end_flag) end_flag = ud_ut_array(char, '\0');
    return (void *)end_flag;
}