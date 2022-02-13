#include <stdlib.h>

#include "polynomials.h"

/// <summary>
/// Multplies a polynomial by a single node. Returns a pointer to the result.
/// </summary>
/// <param name="p_poly">The polynomial to multiply.</param>
/// <param name="p_node">The node to mjultiply.</param>
/// <returns>The result of the multiplication</returns>
struct polynomial* multiply_by_node(struct polynomial* p_poly, struct polynomial* p_node);

/// <summary>
/// Adds to polynomials together and stores the result in p_poly_2
/// </summary>
struct polynomial* add_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

struct polynomial* multiply(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    struct polynomial* p_result = multiply_by_node(p_poly_1, p_poly_2);

    while (p_poly_2->p_next != NULL)
    {
        p_poly_2 = p_poly_2->p_next;

        struct polynomial* p_next_term = multiply_by_node(p_poly_1, p_poly_2);
        add_in_place(p_result, p_next_term);
        free_polynomial(p_next_term);
    }

    //pp_head_poly_4 = simplyify(pp_head_poly_3, degree_1 + degree_2);

    return p_result;
}