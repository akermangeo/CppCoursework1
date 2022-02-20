#include <stdlib.h>
#include <stdio.h>

#include "polynomials.h"
#include "userIO.h"

/// <summary>
/// Evaluates the polynomial at the specified point x using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>The result of the evaluation.</returns>
float evaluate(const struct polynomial* p_poly, float x);

struct polynomial* case_add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    const struct polynomial* p_poly_to_return = add(p_poly_1, p_poly_2);
    printf("Sum = ");
    print_poly(p_poly_to_return);
    return p_poly_to_return;
}

struct polynomial* case_subtract(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_to_return;
    printf("Which polynomial would you like to subract from the other?\n");
    printf("(1 - Subtract Polynomial 1 from 2, 2 - Subtract Polynomial 2 from 1)\n");
    int sub = read_int();


    struct polynomial p_poly_minus =
    {
        .coefficient = -1,
        .exponent = 0,
        .p_next = NULL
    };

    if (sub == 1)
    {
        p_poly_to_return = multiply(p_poly_1, &p_poly_minus);
        add_in_place(p_poly_to_return, p_poly_2);
    }
    else if (sub == 2)
    {
        p_poly_to_return = multiply(p_poly_2, &p_poly_minus);
        add_in_place(p_poly_to_return, p_poly_1);
    }
    else
    {
        printf("Invalid input. Exiting...");
        exit(1);
    }

    printf("Subtraction = ");
    print_poly(p_poly_to_return);
    return p_poly_to_return;
}

struct polynomial* case_multiply(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_to_return = multiply(p_poly_1, p_poly_2);
    printf("Product = ");
    print_poly(p_poly_to_return);
    return p_poly_to_return;
}

void case_evaluate(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    
    printf("Which polynomial would you like to evaluate? (1/2) ");
    int poly_eval = read_int();

    if (poly_eval != 1 && poly_eval != 2)
    {
        printf("Invalid polynomial index.  Returning to options...");
        return;
    }

    float result;
    printf("At what value would you like to evaluate polynomial %d? (input float) ", poly_eval);
    float val = read_float();

    if (poly_eval == 1)
    {
        result = evaluate(p_poly_1, val);
    }
    else if (poly_eval == 2)
    {
        result = evaluate(p_poly_2, val);
    }

    printf("Result = %f\n", result);
}

float evaluate(const struct polynomial* p_poly, float x)
{
    float value = 0;
    while (p_poly != NULL)
    {
        value += p_poly->coefficient;
        if (p_poly->exponent != 0)
        {
            value *= x;
        }
        p_poly = p_poly->p_next;
    }
    return value;
}
