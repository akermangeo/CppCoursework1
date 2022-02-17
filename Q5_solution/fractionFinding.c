#include <stdlib.h>
#include <stdbool.h>

#include "fractionFinding.h"

/// <summary>
/// Checks if the provided fraction is sleepy.
/// </summary>
/// <param name="numerator">The numerator.</param>
/// <param name="denominator">The denominator.</param>
/// <returns>True if the fraction is sleepy.</returns>
bool fraction_is_sleepy(int numerator, int denominator);

/// <summary>
/// Adds a fraction to the array as 2 consecutive integers.
/// </summary>
/// <param name="p_start_pointer">The pointer to the location to store the numerator digit.</param>
/// <param name="numerator">The numerator.</param>
/// <param name="denominator2">The denominator.</param>
void append_fraction(int* p_start_pointer, int numerator, int denominator);


int* find_fractions(int* p_fractions_length)
{
    size_t capacity = 10;
    *p_fractions_length = 0;
    int* p_fractions = (int*) malloc(capacity * 2 * sizeof(int));
    

    for (int numerator = 10; numerator < 100; numerator++)
    {
        for (int denominator = 10; denominator < 100; denominator++)
        {
            if (fraction_is_sleepy(numerator, denominator))
            {
                if (*p_fractions_length == capacity)
                {
                    capacity *= 4;
                    p_fractions = (int*)realloc(p_fractions, capacity * 2 * sizeof(int));
                }
                int* first_digit_location = p_fractions + *p_fractions_length * 2;
                append_fraction(first_digit_location, numerator, denominator);
                (* p_fractions_length)++;
            }
        }
    }
    return p_fractions;
}

bool fraction_is_sleepy(int numerator, int denominator)
{
    int numerator1 = numerator / 10;
    int numerator2 = numerator % 10;
    int denominator1 = denominator / 10;
    int denominator2 = denominator % 10;

    float originalfraction = ((float)10 * numerator1 + numerator2) / (10 * denominator1 + denominator2);
    if (numerator1 == denominator1 && originalfraction == (float)numerator2 / denominator2)
    {
        return true;
    }
    if (numerator1 == denominator2 && originalfraction == (float)numerator2 / denominator1)
    {
        return true;
    }
    if (numerator2 == denominator1 && originalfraction == (float)numerator1 / denominator2)
    {
        return true;
    }
    if (numerator2 == denominator2 && originalfraction == (float)numerator1 / denominator1)
    {
        return true;
    }
    return false;
}

void append_fraction(int* p_start_pointer, int numerator, int denominator)
{
    p_start_pointer[0] = numerator;
    p_start_pointer[1] = denominator;
}
