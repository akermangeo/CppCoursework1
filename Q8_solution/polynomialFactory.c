#include <stdlib.h>

#include "polynomials.h"

/// <summary>
/// Reads a polynomial of a given degree from the user.
/// </summary>
/// <param name="degree">The degree of the polynomial.</param>
/// <returns>A pointer to thr created polynomial.</returns>
struct polynomial* read_polynomial(int degree);


struct polynomial* polynomial_factory_method()
{
    int max_degree;
    printf("Please enter the degree of the polynomial.");
    scanf_s("%i", &max_degree);

    return read_polynomial(max_degree);
}

struct polynomial* read_polynomial(int degree)
{
    float coefficient;
    printf("Please input coefficient for x^%d.", degree);
    scanf_s("%f", &coefficient);
    struct polynomial* p_poly = create_node();
    p_poly->coefficient = coefficient;
    p_poly->exponent = degree;
    if (degree == 0)
    {
        p_poly->p_next = NULL;
    }
    else
    {
        struct polynomial* next_poly = read_polynomial(degree - 1);
        p_poly->p_next = next_poly;
    }
    return p_poly;
}

struct polynomial* create_node()
{
    struct polynomial* node = (struct polynomial*)malloc(sizeof(struct polynomial));
    node->coefficient = 0;
    node->exponent = 0;
    node->p_next = NULL;
    return node;
}


