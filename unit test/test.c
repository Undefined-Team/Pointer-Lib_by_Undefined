#include <ud_pointer.h>
#include <stdlib.h>

int main(void)
{
    char **test = ud_ptr_set(char *, "test", "allo");
    char **test2 = ud_ptr_set(char *, "test2");
    char **test3 = ud_ptr_set(char *, "test3");

    char **t = ud_ptr_init(char *, 4);
    char ***ptr = ud_ptr_set(char **, test, test2, test3);
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
    ud_ut_test(!ud_mem_cmp(ptr[0][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr[0][1], "allo", 4));
    ud_ut_test(!ud_mem_cmp(ptr[1][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr[2][0], "test", 4));
    ud_ut_test(ptr[3] == NULL);
    ud_ut_test(ptr[4] == ud_ptr_end_flag());
    ud_ut_test(!ud_mem_cmp(ptr2[0][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[0][1], "allo", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[1][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[2][0], "test", 4));
    ud_ut_test(ptr2[3] == NULL);
    ud_ut_test(ptr2[4] == ud_ptr_end_flag());
    ud_ut_test(!ud_mem_cmp(ptr[0], ptr2[0], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(ptr[1], ptr2[1], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(ptr[2], ptr2[2], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(*ptr, *ptr2, ud_ptr_len(ptr)));
    ud_ut_test(ptr != ptr2);
    ud_ut_test(ud_ptr_len(ptr) == 3);
    ud_ut_test(ud_ptr_len(ptr2) == 3);

    char *test_fe[] = {"slt", "cava", NULL};

    ud_ptr_foreach(test_fe, elem,
        ud_ut_test(!ud_mem_cmp(*elem, "cava", 4) || !ud_mem_cmp(*elem, "slt", 3));
    );

    void *a = ud_ptr_set(void *, NULL);
    void *b = ud_ptr_cpy(a);

    ud_ut_test(((char **)a)[0] == NULL);
    ud_ut_test(((char **)a)[1] == NULL);
    ud_ut_test(ud_ptr_len(a) == 1);
    ud_ut_test(((char **)b)[0] == NULL);
    ud_ut_test(ud_ptr_len(b) == 1);
    ud_ut_test(a != b);

    void *c = ud_ptr_set(char *, NULL, "test");
    void *d = ud_ptr_cpy(c);
    
    ud_ut_test(ud_ptr_len(c) == 2);
    ud_ut_test(ud_ptr_len(d) == 2);
    ud_ut_test(((char **)c)[0] == NULL);
    ud_ut_test(!ud_mem_cmp(((char **)c)[1], "test", 4));
    ud_ut_test(((char **)c)[2] == NULL);
    ud_ut_test(((char **)c)[3] == ud_ptr_end_flag());
    ud_ut_test(((char **)d)[0] == NULL);
    ud_ut_test(!ud_mem_cmp(((char **)d)[1], "test", 4));
    ud_ut_test(((char **)d)[2] == NULL);

    return (0);
}