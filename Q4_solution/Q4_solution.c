/*
    Write a program which reads in 200 characters and outputs them in
    reverse order. Do not use arrays. Hint: use recursion.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHAR 200
#define FALSE 0
#define TRUE 1

int check_string_len(const char* p_str, int len, int* p_actual_len)
{
    static int i;
    for (i = 0; p_str[i] != '\0'; ++i);
    *p_actual_len = i;
    if (i == len)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

char* reverse_string(const char* p_str)
{
    static int i = 0;
    static char str_rev[NUM_CHAR + 1];
    if (*p_str)
    {
        reverse_string(p_str + 1);
        str_rev[i++] = *p_str;
    }
    return str_rev;
}

int main(void)
{
    char string[NUM_CHAR + 1];
    char* p_rev_string;
    int actual_string_length, check_str;

    printf("Input string of %d characters: ", NUM_CHAR);
    scanf("%s", string);

    // To do this for strings upto NUM_CHAR characters long, quote the part below out
    check_str = check_string_len(string, NUM_CHAR, &actual_string_length);

    if (check_str == FALSE)
    {
        printf("Wrong input string length.\n");
        printf("Expected %d, got %d.\n", NUM_CHAR, actual_string_length);
        return EXIT_FAILURE;
    }
    //

    p_rev_string = reverse_string(string);

    printf("\nYour string reversed is: %s\n\n", p_rev_string);
    printf("(Your string was: %s)\n", string);

    return EXIT_SUCCESS;
}