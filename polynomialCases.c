#include "polynomials.h"
#include "polynomialCases.h"

void case_3(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_temp2 = add(p_poly_1, p_poly_2);
    *p_poly_temp = *p_poly_temp2;
    printf("Sum = ");
    print_poly(p_poly_temp);
    free(p_poly_temp2);
}

void case_4(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    printf("Which polynomial would you like to subract from the other?\n");
    printf("(1 - Subtract Polynomial 1 from 2, 2 - Subtract Polynomial 2 from 1)\n");
    int sub = 0;
    scanf_s("%d", &sub);

    struct polynomial* p_poly_temp2 = NULL;
    struct polynomial* p_poly_temp3 = NULL;

    struct polynomial p_poly_minus;
    p_poly_minus.coefficient = -1;
    p_poly_minus.exponent = 0;
    p_poly_minus.p_next = NULL;

    if (sub == 1)
    {
        p_poly_temp2 = multiply(p_poly_1, &p_poly_minus);
        p_poly_temp3 = add(p_poly_temp2, p_poly_2);
    }
    else if (sub == 2)
    {
        p_poly_temp2 = multiply(p_poly_2, &p_poly_minus);
        p_poly_temp3 = add(p_poly_1, p_poly_temp2);
    }
    else
    {
        printf("Invalid input.  Returning to options...");
        return;
    }

    *p_poly_temp = *p_poly_temp3;
    printf("Subtraction = ");
    print_poly(p_poly_temp);
    free_polynomial(p_poly_temp2);
    free(p_poly_temp3);
}

void case_5(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_temp2 = multiply(p_poly_1, p_poly_2);
    *p_poly_temp = *p_poly_temp2;
    printf("Product = ");
    print_poly(p_poly_temp);
    free(p_poly_temp2);
}

void case_6(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    int poly_eval;
    printf("Which polynomial would you like to evaluate? (1/2) ");
    scanf_s("%d", &poly_eval);

    if (poly_eval != 1 && poly_eval != 2)
    {
        printf("Invalid polynomial index.  Returning to options...");
        return;
    }

    double val, result;
    printf("At what value would you like to evaluate polynomial %d? (input float) ", poly_eval);
    scanf_s("%lf", &val);

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

double evaluate(const struct polynomial* p_poly, double x)
{
    double value = 0;
    struct polynomial* p_temp_poly = p_poly;
    int exp1, exp2 = p_temp_poly->exponent;

    while (p_temp_poly != NULL)
    {
        exp1 = p_temp_poly->exponent;
        value += p_temp_poly->coefficient;

        if (p_temp_poly->exponent != 0)
        {
            value *= x;
        }

        exp2 = exp1;
        p_temp_poly = p_temp_poly->p_next;
    }

    return value;
}