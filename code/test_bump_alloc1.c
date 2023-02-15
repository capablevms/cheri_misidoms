// gcc -I../listings ./test_bump_alloc1.c

#include <assert.h>
#include <stddef.h>
#include <sys/mman.h>
#include <stdio.h>

#include "../listings/bump_alloc1.c"

int
sum_arr(int *arr, size_t arr_size)
{
    int sum = 0;
    for (size_t i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    return sum;
}

int
main()
{
    size_t vars_count = 10;
    int *vars = malloc(vars_count * sizeof(int));
    assert(vars != NULL);
    for (size_t i = 0; i < vars_count; i++) {
        vars[i] = i * i;
    }
    assert(sum_arr(vars, vars_count) == 285);
    int *ptr_var = malloc(sizeof(int));
    assert(ptr_var != NULL);
    assert(ptr_var != vars);
    vars_count--;
    int *new_vars = realloc(vars, vars_count * sizeof(int));
    assert(vars != new_vars);
    assert(new_vars != NULL);
    assert(sum_arr(new_vars, vars_count) == 204);
    return 0;
}
