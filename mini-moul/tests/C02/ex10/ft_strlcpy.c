#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../ex10/ft_strlcpy.c"
#include "../../../utils/constants.h"

int test1(void);

int main(void)
{
	if (test1() != 0)
		return (-1);
	return (0);
}

int test1(void)
{
    // Test with empty source string
    char dest_empty[20] = "destination";
    char src_empty[] = "";
    unsigned int result_empty = ft_strlcpy(dest_empty, src_empty, sizeof(dest_empty));
    if (result_empty == 0 && strcmp(dest_empty, "") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [1] Test Passed: Empty source string." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Empty source string." DEFAULT "\n");
    }

    // Test with smaller destination size
    char dest_small[5] = "";
    char src_small[] = "hello";
    unsigned int result_small = ft_strlcpy(dest_small, src_small, sizeof(dest_small));
    if (result_small == 5 && strcmp(dest_small, "hell") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [2] Test Passed: Smaller destination size." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Smaller destination size." DEFAULT "\n");
    }

    // Test with larger destination size
    char dest_large[20] = "";
    char src_large[] = "world";
    unsigned int result_large = ft_strlcpy(dest_large, src_large, sizeof(dest_large));
    if (result_large == 5 && strcmp(dest_large, "world") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [3] Test Passed: Larger destination size." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Larger destination size." DEFAULT "\n");
    }

    // Test with same destination size as source size
    char dest_same[7] = "";
    char src_same[] = "foobar";
    unsigned int result_same = ft_strlcpy(dest_same, src_same, sizeof(dest_same));
    if (result_same == 6 && strcmp(dest_same, "foobar") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [4] Test Passed: Same destination and source size." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Same destination and source size." DEFAULT "\n");
    }


    // ... (Other tests)

    return 0;
}