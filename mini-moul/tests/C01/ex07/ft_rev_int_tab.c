#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex07/ft_rev_int_tab.c"
#include "../../../utils/constants.h"

int test1(void);

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}

int compare_arrays(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

int test1(void)
{
    int original[] = {1, 2, 3, 4, 5};
    int reversed[] = {5, 4, 3, 2, 1};
    int size = sizeof(original) / sizeof(original[0]);

    int test_array[size];
    for (int i = 0; i < size; i++)
    {
        test_array[i] = original[i];
    }

    ft_rev_int_tab(test_array, size);

    if (compare_arrays(test_array, reversed, size))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Array is reversed correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Array is not reversed correctly.\n" DEFAULT);
    }

    // Edge Cases

    // Test with an empty array
    int empty_array[] = {};
    ft_rev_int_tab(empty_array, 0); // Function should handle this gracefully

    // Test with an array of size 1
    int single_element_array[] = {42};
    ft_rev_int_tab(single_element_array, 1);
    if (single_element_array[0] == 42)
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Single-element array remains unchanged.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Single-element array is changed incorrectly.\n" DEFAULT);
    }

    // Test with an array of even size
    int even_array[] = {10, 20, 30, 40};
    int expected_even_reversed[] = {40, 30, 20, 10};
    ft_rev_int_tab(even_array, 4);
    if (compare_arrays(even_array, expected_even_reversed, 4))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Even-sized array is reversed correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Even-sized array is not reversed correctly.\n" DEFAULT);
    }

    // Test with an array of odd size
    int odd_array[] = {15, 25, 35, 45, 55};
    int expected_odd_reversed[] = {55, 45, 35, 25, 15};
    ft_rev_int_tab(odd_array, 5);
    if (compare_arrays(odd_array, expected_odd_reversed, 5))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Odd-sized array is reversed correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Odd-sized array is not reversed correctly.\n" DEFAULT);
    }

    return 0;
}