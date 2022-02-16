#include "polynomials.h"

/// <summary>
/// Multplies a polynomial by a single node. Returns a pointer to the result.
/// </summary>
/// <param name="p_poly">The polynomial to multiply.</param>
/// <param name="p_node">The node to mjultiply.</param>
/// <returns>The result of the multiplication</returns>
struct polynomial* multiply_by_node(const struct polynomial* p_poly, const struct polynomial* p_node);

struct polynomial* multiply(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_result = multiply_by_node(p_poly_1, p_poly_2);

    while (p_poly_2->p_next != NULL)
    {
        p_poly_2 = p_poly_2->p_next;

        struct polynomial* p_next_term = multiply_by_node(p_poly_1, p_poly_2);
        add_in_place(p_result, p_next_term);
        free_polynomial(p_next_term);
    }

    return p_result;
}

struct polynomial* multiply_by_node(const struct polynomial* p_poly, const struct polynomial* p_node)
{
    struct polynomial* p_result = create_node();
    p_result->coefficient = p_poly->coefficient * p_node->coefficient;

    //If this coefficient is 0 then one of the polynomials is constant 0 so we can return now.
    if (p_result->coefficient == 0)
    {
        return p_result;
    }

    //None of the polynomials have 0 as a coefficient for any term...
    struct polynomial* p_to_return = p_result;
    p_result->exponent = p_poly->exponent + p_node->exponent;
    p_poly = p_poly->p_next;

    while (p_poly != NULL)
    {
        p_result->p_next = create_node();
        p_result = p_result->p_next;

        p_result->coefficient = p_poly->coefficient * p_node->coefficient;
        p_result->exponent = p_poly->exponent + p_node->exponent;

        p_poly = p_poly->p_next;
    }
    p_result->p_next = NULL;
    return p_to_return;
}
