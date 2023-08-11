#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../../../../ex01/ft_strncpy.c"
#include "../../../utils/constants.h"

int	test1(void)
{
	char src[] = "Hello";
	char dest[] = "World1";
	char *result;

	result = ft_strncpy(dest, src, 3);

	if (strcmp(result, "Helld1") != 0)
	{
		printf("    " RED "[1] ft_strncpy(\"World1\", \"Hello\", 3) Expected \"Helld1\", got \"%s\"\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [1] ft_strncpy(\"World1\", \"Hello\", 3) Expected \"Helld1\", got \"%s\"\n" DEFAULT, result);
	return (0);
}

int	test2(void)
{
	char src[] = "Hello";
	char dest[] = "World1";
	char *result;

	result = ft_strncpy(dest, src, 5);

	if (strcmp(result, "Hello1") != 0)
	{
		printf("    " RED "[2] ft_strncpy(\"World1\", \"Hello\", 5) Expected \"Hello1\", got \"%s\"\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [2] ft_strncpy(\"World1\", \"Hello\", 5) Expected \"Hello1\", got \"%s\"\n" DEFAULT, result);
	return (0);
}

int	test3(void)
{
	char src[] = "Hello";
	char dest[] = "World1";
	char *result;

	result = ft_strncpy(dest, src, 7);

	if (strcmp(result, "Hello") != 0)
	{
		printf("    " RED "[3] ft_strncpy(\"World1\", \"Hello\", 7) Expected \"Hello\", got \"%s\"\n", result);
		return (-1);
	}
	else
		printf("  " GREEN CHECKMARK GREY " [3] ft_strncpy(\"World1\", \"Hello\", 7) Expected \"Hello\", got \"%s\"\n" DEFAULT, result);
	return (0);
}

int	test4(void)
{
	    // Test with empty source string
    char dest_empty[10] = "Hello";
    char src_empty[] = "";
    size_t n_empty = sizeof(dest_empty);
    ft_strncpy(dest_empty, src_empty, n_empty);
    if (strcmp(dest_empty, "") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [1] Test Passed: Copied empty source string correctly." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Empty source string not copied correctly." DEFAULT "\n");
		return (-1);
    }
	return (0);
}

int test5(void)
{
	// Test copying with n = 0 (no characters copied)
    char dest_n_zero[10] = "Hello";
    char src_n_zero[] = "Goodbye";
    ft_strncpy(dest_n_zero, src_n_zero, 0);
    if (strcmp(dest_n_zero, "Hello") == 0)
    {
        printf("   " GREEN CHECKMARK GREY " [5] Test Passed: Copied with n = 0, destination unchanged." DEFAULT "\n");
    }
    else
    {
        printf("    " RED "Test Failed: Copied with n = 0, destination changed incorrectly." DEFAULT "\n");
		return (-1);
    }
	return (0);
}

int	main(void)
{
	if (test1()+test2()+test3()+test4()+test5()!=0)
		return (-1);
	return (0);
}