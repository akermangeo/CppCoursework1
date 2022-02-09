#include <stdlib.h>

#include "fractionFinding.h"

int* find_fractions()
{
    int capacity = 10;
    int* fractions = (int*) malloc(10 * sizeof(int));

    //We test all fractions, for the numerator, numerator 1 is always the first digit whereas in the
    //denominator, denominator1 and denominator 2 can come in either order. However denominator 1 always cancels one of
    //the numerators
    
    for (int numerator1 = 1; numerator1 < 10; numerator1++)
    {
        for (int numerator2 = 0; numerator2 < 10; numerator2++)
        {
            //To have cancellation one of the denominators must equal one of the numerators
            int denominator1 = numerator1;

            
            for (int denominator2 = 0; denominator2 < 10; denominator2++)
            {
                float starting_fraction = CreateFraction(numerator1, numerator2, denominator1, denominator2);
                add_fraction(fractions, numerator1, numerator2, denominator1, denominator2)


                    
            }
        }
    }
    fractions[0] = 1.;
    fractions[1] = 2.;
    fractions[2] = 3.;
    fractions[3] = 4.;
    fractions[4] = 5.;
    return fractions;
}
