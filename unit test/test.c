#include <ud_pointer.h>

int main(void)
{
    char **test = ud_ut_array(char *, "test", "allo");
    char **test2 = ud_ut_array(char *, "test");
    char **test3 = ud_ut_array(char *, "test");

    char **t = ud_ptr_init(char *, 4);
    char ***ptr = ud_ptr_set(char **, test, test2, test3);
    printf("%zd\n", ud_ptr_len(ptr));
    char ***ptr2 = ud_ptr_cpy(char **, ptr);
    printf("%zd\n", ud_ptr_len(ptr2));
    for (char i = 0; i < 3; ++i) printf("ptr1 %s\n", ptr[i][0]);
    for (char i = 0; i < 3; ++i) printf("ptr2 %s\n", ptr2[i][0]);
}