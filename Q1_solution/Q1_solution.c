#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// Reads a single caracter from the user.
/// </summary>
/// <returns>The character read from the user.</returns>
char read_character();

int main()
{
    printf("Input 2 characters (white space characters will be ignored as will any characters after the first 2): ");
    char char1 = read_character();
    char char2 = read_character();
    printf("Output char:%c %c \n", char2, char1);
    return EXIT_SUCCESS;
}

char read_character()
{
    char character;
    int input_counter = scanf_s(" %c", &character, 1);
    if (input_counter < 1)
    {
        printf("Invalid input. Exiting... ");
        exit(1);
    }
    return character;
}
