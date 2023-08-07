#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex07/ft_putnbr.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
        char *desc;
        int n;
        char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
        t_test tests[] = {
            {.desc = "ft_putnbr(0)",
             .n = 0,
             .expected = "0"},
            {.desc = "ft_putnbr(-2147483648)",
             .n = -2147483648,
             .expected = "-2147483648"},
            {.desc = "ft_putnbr(2147483647)",
             .n = 2147483647,
             .expected = "2147483647"},
            {.desc = "ft_putnbr(42)",
             .n = 42,
             .expected = "42"},
            {.desc = "ft_putnbr(-42)",
             .n = -42,
             .expected = "-42"},
            // Add more test cases here
        };
        int count = sizeof(tests) / sizeof(tests[0]);
        return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
        int i;
        int error = 0;
        for (i = 0; i < count; i++)
        {
                // Flush the standard output buffer
                fflush(stdout);

                char buffer[1024];
                // Clear the buffer used to capture the output of the function being tested
                memset(buffer, 0, sizeof(buffer));

                // Redirect the output to a file
                int saved_stdout = dup(STDOUT_FILENO);
                int pipefd[2];
                pipe(pipefd);
                dup2(pipefd[1],STDOUT_FILENO);
                close(pipefd[1]);

                // Call the function to be tested
                ft_putnbr(tests[i].n);

                size_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));
                close(pipefd[0]);

                //ghadi t7sb b nullterminator ila kan
                size_t actual_length = bytes_read;

                // Restore the original output
                fflush(stdout);
                dup2(saved_stdout, STDOUT_FILENO);
                close(saved_stdout);


                // Check that the output matches the expected value
                // Compare the actual output length with the expected output length
                //moulinette katrj3 write(1, "2147483648", 11); 7itach katprinter \0 khassha tkun write(1, "2147483648", 10);
                if (actual_length != strlen(tests[i].expected)) 
                {
                        printf("    " ORANGE "[%d] %s Expected %zu characters, got %zu characters\n", i + 1, tests[i].desc, strlen(tests[i].expected) - 1, actual_length - 1);
                        error -= 1;
                }
                else if (strcmp(buffer, tests[i].expected) != 0)
                {
                        printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, tests[i].expected, buffer);
                        error -= 1;
                }
                else
                        printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, buffer);
        }

        return (error);
}
