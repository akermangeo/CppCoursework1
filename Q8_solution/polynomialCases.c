#include "polynomials.h"

void case_3(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    int store = store_polynomial();
    if (store != 1 && store != 2 && store != 0)
    {
        printf("Invalid entry.  Returning to options...");
        return;
    }
    
    printf("Sum = ");
    if (store == 1)
    {
        add_in_place(p_poly_1, p_poly_2);
        print_poly(p_poly_1);
    }
    else if (store == 2)
    {
        add_in_place(p_poly_2, p_poly_1);
        print_poly(p_poly_2);
    }
    else if (store == 0)
    {
        print_poly(add(p_poly_1, p_poly_2));
    }
}

void case_4(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    printf("Which polynomial would you like to subract from the other?\n");
    printf("(1 - Subtract Polynomial 1 from 2, 2 - Subtract Polynomial 2 from 1)\n");
    int sub = scanf_s("%d", &sub);

    int store = store_polynomial();
    if (store != 1 && store != 2 && store != 0)
    {
        printf("Invalid entry.  Returning to options...");
        return;
    }

    struct polynomial* p_poly_temp;
    struct polynomial* p_poly_temp1;
    struct polynomial* p_poly_temp2;

    struct polynomial p_poly_minus;
    p_poly_minus.coefficient = -1;
    p_poly_minus.exponent = 0;
    p_poly_minus.p_next = NULL;

    if (sub == 1)
    {
        p_poly_temp1 = multiply(p_poly_1, &p_poly_minus);
        p_poly_temp2 = p_poly_2;
    }
    else if (sub == 2)
    {
        p_poly_temp1 = multiply(p_poly_2, &p_poly_minus);
        p_poly_temp2 = p_poly_1;
    }
    else
    {
        printf("Invalid entry.  Returning to options...");
        return;
    }

    p_poly_temp = add(p_poly_temp1, p_poly_temp2);
    printf("Subtraction = ");
    print_poly(p_poly_temp);

    //  NOT WORKING
    if (store == 1)
    {
        free_polynomial(p_poly_1);
        p_poly_1 = p_poly_temp;
    }
    if (store == 2)
    {
        free_polynomial(p_poly_2);
        p_poly_2 = p_poly_temp;
    }
    else
    {
        free_polynomial(p_poly_temp);
    }
    //

    free_polynomial(p_poly_temp1);
}

void case_5(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    struct polynomial* p_poly_temp;

    int store = store_polynomial();
    if (store != 1 && store != 2 && store != 0)
    {
        printf("Invalid entry.  Returning to options...");
        return;
    }

    p_poly_temp = multiply(p_poly_1, p_poly_2);
    printf("Product = ");
    print_poly(p_poly_temp);
    
    //  NOT WORKING
    if (store == 1)
    {
        free_polynomial(p_poly_1);
        p_poly_1 = p_poly_temp;
    }
    else if (store == 2)
    {
        free_polynomial(p_poly_2);
        p_poly_2 = p_poly_temp;
    }
    else
    {
        free_polynomial(p_poly_temp);
    }
    //
}

void case_6(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
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

int store_polynomial()
{
    int store;

    printf("Would you like to store the resulting polynomial?\n");
    printf("(1 - Replace Polynomial 1, 2 - Replace Polynomial 2, 0 - Do not store)\n");
    scanf_s("%d", &store);

    return store;
}