/*
    Write a program which reads in 200 characters and outputs them in
    reverse order. Do not use arrays. Hint: use recursion.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// Reads in the given number of caracters and reverses them.
/// </summary>
/// <param name="caracters_to_reverse">The number of characters to reverse.</param>
void reverse_characters(int characters_to_reverse);

/// <summary>
/// Reads a single caracter from the user.
/// </summary>
/// <returns>The character read from the user.</returns>
char read_character();

int main(void)
{
    printf("Input 200 characters\n");
    printf("White space characters will be ignored as will any characters after the first 200.");
    reverse_characters(200);
}

void reverse_characters(int characters_to_reverse)
{
    char character = read_character();
    if (characters_to_reverse == 1)
    {
        printf("The caracters reversed are... ");
    }
    else
    {
        reverse_characters(characters_to_reverse - 1);
    }
    printf("%c", character);
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