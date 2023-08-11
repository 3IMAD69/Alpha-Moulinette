#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex08/ft_sort_int_tab.c"
#include "../../../utils/constants.h"

int test1(void);

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}

int is_sorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
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
    // Test with a sorted array
    int sorted_array[] = {1, 2, 3, 4, 5};
    ft_sort_int_tab(sorted_array, 5);
    if (is_sorted(sorted_array, 5))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Sorted array remains sorted.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Sorted array is not sorted correctly.\n" DEFAULT);
    }

    // Test with a reverse sorted array
    int reverse_sorted_array[] = {5, 4, 3, 2, 1};
    ft_sort_int_tab(reverse_sorted_array, 5);
    if (is_sorted(reverse_sorted_array, 5))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Reverse sorted array is sorted correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Reverse sorted array is not sorted correctly.\n" DEFAULT);
    }

    // Test with an empty array
    int empty_array[] = {};
    ft_sort_int_tab(empty_array, 0); // Function should handle this gracefully

    // Test with an array of size 1
    int single_element_array[] = {42};
    ft_sort_int_tab(single_element_array, 1);
    if (is_sorted(single_element_array, 1))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Single-element array remains unchanged.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Single-element array is changed incorrectly.\n" DEFAULT);
    }

    // Test with duplicate values
    int duplicate_array[] = {5, 2, 3, 5, 1};
    int expected_duplicate_sorted[] = {1, 2, 3, 5, 5};
    ft_sort_int_tab(duplicate_array, 5);
    if (is_sorted(duplicate_array, 5) && compare_arrays(duplicate_array, expected_duplicate_sorted, 5))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Array with duplicates is sorted correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Array with duplicates is not sorted correctly.\n" DEFAULT);
    }

    // Test with larger array
    int larger_array[] = {9, 4, 12, 1, 6, 8, 3};
    int expected_larger_sorted[] = {1, 3, 4, 6, 8, 9, 12};
    ft_sort_int_tab(larger_array, 7);
    if (is_sorted(larger_array, 7) && compare_arrays(larger_array, expected_larger_sorted, 7))
    {
        printf("  " GREEN CHECKMARK GREY "Test Passed: Larger array is sorted correctly.\n" DEFAULT);
    }
    else
    {
        printf("    " RED "Test Failed: Larger array is not sorted correctly.\n" DEFAULT);
    }

    return 0;
}