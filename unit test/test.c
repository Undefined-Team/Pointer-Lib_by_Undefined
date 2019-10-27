#include <ud_pointer.h>
#include <stdlib.h>

int main(void)
{
    char **test = ud_ut_array(char *, "test", "allo");
    char **test2 = ud_ut_array(char *, "test");
    char **test3 = ud_ut_array(char *, "test");

    char **t = ud_ptr_init(char *, 4);
    char ***ptr = ud_ptr_set(char **, test, test2, test3);
    char ***ptr2 = ud_ptr_cpy(ptr);

    // char *test_fe[] = {"slt", "cava", NULL};
    char *test_fe[] = {"slt", "cava", NULL};
    // ud_ptr_foreach(test_fe);
    // printf("str = %s\n", *key);

    // size_t *test_malloc = malloc(sizeof(test_malloc) * 27);
    // char *ptr_malloc = (char*)test_malloc;
    // printf("MALLOC SIZE = %zd\n", *(ptr_malloc - MALLOC_HEADER_SIZE));

    ud_ut_test(!ud_mem_cmp(ptr[0][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr[0][1], "allo", 4));
    ud_ut_test(!ud_mem_cmp(ptr[1][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr[2][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[0][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[0][1], "allo", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[1][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr2[2][0], "test", 4));
    ud_ut_test(!ud_mem_cmp(ptr[0], ptr2[0], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(ptr[1], ptr2[1], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(ptr[2], ptr2[2], sizeof(void *)));
    ud_ut_test(!ud_mem_cmp(*ptr, *ptr2, ud_ptr_len(ptr)));
    ud_ut_test(ptr != ptr2);
    ud_ut_test(ud_ptr_len(ptr) == 3);
    ud_ut_test(ud_ptr_len(ptr2) == 3);
    ud_ptr_foreach(test_fe, elem,
        ud_ut_test(!ud_mem_cmp(*elem, "cava", 4) || !ud_mem_cmp(*elem, "slt", 3));
    );

    return (0);
}