#include <stdlib.h>
#include <stdio.h>

#include "polynomials.h"
#include "userIO.h"

/// <summary>
/// Reads a polynomial of a given degree from the user.
/// </summary>
/// <param name="degree">The degree of the polynomial.</param>
/// <returns>A pointer to thr created polynomial.</returns>
struct polynomial* read_polynomial(int degree);

struct polynomial* polynomial_factory_method()
{
    printf("Please enter the degree of the polynomial: ");
    int max_degree = read_int();

    if (max_degree < 0)
    {
        printf("Invalid polynomial degree. Exiting...\n");
        exit(1);
    }

    struct polynomial* p_poly = read_polynomial(max_degree);

    //If all the input coefficients were 0 then this will be NULL.
    if (p_poly == NULL)
    {
        p_poly = create_node();
    }
    return p_poly;
}

struct polynomial* read_polynomial(int degree)
{
    printf("Please input coefficient for x^%d: ", degree);

    float coefficient = read_float();

    struct polynomial* next_poly;
    if (degree == 0)
    {
        next_poly = NULL;
    }
    else
    {
        next_poly = read_polynomial(degree - 1);
    }

    if (coefficient == 0)
    {
        return next_poly;
    }

    struct polynomial* p_poly = create_node();
    p_poly->p_next = next_poly;
    p_poly->coefficient = coefficient;
    p_poly->exponent = degree;
    return p_poly;
}

struct polynomial* create_node()
{
    struct polynomial* node = (struct polynomial*)malloc(sizeof(struct polynomial));
    if (node == NULL)
    {
        printf("Memory allocation failure. (create_node)\n");
        exit(1);
    }
    node->coefficient = 0;
    node->exponent = 0;
    node->p_next = NULL;
    return node;
}


