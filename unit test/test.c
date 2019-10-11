#include <ud_pointer.h>
#include <ud_string.h>

int main(void)
{
    char *test = ud_str_dup("test1");
    char *test2 = ud_str_dup("test2");
    char *test3 = ud_str_dup("test3");

    char **ptr = (char **)ud_ptr_set(char **, test, test2, test3);
    printf("%zd\n", ud_ptr_len(ptr));
    char **ptr2 = (char **)ud_ptr_cpy(ptr);
    printf("%zd\n", ud_ptr_len(ptr2));
    for (size_t i = 0; i < 3; ++i) printf("ptr1 %s\n", ptr[i]);
    for (size_t i = 0; i < 3; ++i) printf("ptr2 %s\n", ptr2[i]);
}