#include <ud_pointer.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    char **test = ud_ptr_set(char *, "test", "allo");
    char **test2 = ud_ptr_set(char *, "test2");
    char **test3 = ud_ptr_set(char *, "test3");

    char **t = ud_ptr_init(char *, 4);
    char ***ptr = ud_ptr_set(char **, test, test2, test3);
    printf("%zd\n", ud_ptr_len(ptr));
    char ***ptr2 = ud_ptr_cpy(ptr);

    printf("START RM TESTS\n");
    // if (ptr) 
    // { 
    //     typeof(*ptr)* name = ptr; 
    //     if (name) for (;*name;++name) printf("TEST\n");
    // }
    // ud_ptr_foreach(ptr2, elem, printf("TEST\n"););
    ud_ptr_foreach(ptr2, elem, printf("START: ");ud_ptr_foreach(*elem, truck, printf("%s, ", *truck);); printf("\n"););
    printf("try remove elem\n");
    
    ud_ptr_rm_adr(ptr2, ptr2[2], 0);
    // ud_ptr_rm_idx(ptr2, 2, 0);

    ud_ptr_foreach(ptr2, elem, printf("START: ");ud_ptr_foreach(*elem, elem2, printf("%s, ", *elem2);); printf("\n"););

    printf("%zd\n", ud_ptr_len(ptr2));
    // for (char i = 0; i < 3; ++i) printf("ptr1 %s\n", ptr[i][0]);
    // for (char i = 0; i < 3; ++i) printf("ptr2 %s\n", ptr2[i][0]);
    // ud_ut_free(test);
    // ud_ut_free(test2);
    // ud_ut_free(test3);
    // ud_ut_free(ptr);
    ud_ptr_free(ptr2, 1);
    ud_ut_free(t);
    ud_ut_free(ptr);
    // ud_ut_free(ptr2);    
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