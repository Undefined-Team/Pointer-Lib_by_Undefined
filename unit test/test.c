#include <ud_pointer.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    char **test = ud_ut_array(char *, "test", "allo");
    char **test2 = ud_ut_array(char *, "test");
    char **test3 = ud_ut_array(char *, "test");

    char **t = ud_ptr_init(char *, 4);
    char ***ptr = ud_ptr_set(char **, test, test2, test3);
    printf("%zd\n", ud_ptr_len(ptr));
    char ***ptr2 = ud_ptr_cpy(ptr);
    printf("%zd\n", ud_ptr_len(ptr2));
    for (char i = 0; i < 3; ++i) printf("ptr1 %s\n", ptr[i][0]);
    for (char i = 0; i < 3; ++i) printf("ptr2 %s\n", ptr2[i][0]);

    // char *test_fe[] = {"slt", "cava", NULL};
    char *test_fe[] = {"slt", "cava", NULL};
    // ud_ptr_foreach(test_fe);
    ud_ptr_foreach(test_fe, elem, 
    printf("str = %s\n", *elem);
    printf("st = %s\n", *elem);
    );
    // printf("str = %s\n", *key);

    // size_t *test_malloc = malloc(sizeof(test_malloc) * 27);
    // char *ptr_malloc = (char*)test_malloc;
    // printf("MALLOC SIZE = %zd\n", *(ptr_malloc - MALLOC_HEADER_SIZE));

    return (0);
}