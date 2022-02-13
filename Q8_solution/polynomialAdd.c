#include "polynomials.h"

/// <summary>
/// Adds 2 polynomials of the same degree together, returns a pointer to the result.
/// </summary>
/// <param name="p_poly_1">The first polynomial to add.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
/// <returns>The result of the addition.</returns>
struct polynomial* add_same_degree(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

/// <summary>
/// Adds 2 polynomials of the same degree together and stores the result in p_poly_1.
/// </summary>
/// <param name="p_poly_1">The polynomial to add and store the result in.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
void add_same_degree_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

struct polynomial* add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    if (p_poly_1->exponent == p_poly_2->exponent)
    {
        return add_same_degree(p_poly_1, p_poly_2);
    }

    struct polynomial* const p_result = create_node();
    if (p_poly_1->exponent > p_poly_2->exponent)
    {
        p_result->exponent = p_poly_1->exponent;
        p_result->coefficient = p_poly_1->coefficient;
        if (p_poly_1->p_next == NULL)
        {
            p_result->p_next = copy(p_poly_2);
        }
        else
        {
            p_poly_1 = p_poly_1->p_next;
            p_result->p_next = add(p_poly_1, p_poly_2);
        }
    }
    else
    {
        p_result->exponent = p_poly_2->exponent;
        p_result->coefficient = p_poly_2->coefficient;
        if (p_poly_2->p_next == NULL)
        {
            p_result->p_next = copy(p_poly_1);
        }
        else
        {
            p_poly_2 = p_poly_2->p_next;
            p_result->p_next = add(p_poly_1, p_poly_2);
        }
    }
    return p_result;
}

struct polynomial* add_same_degree(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    struct polynomial* p_result = create_node();
    p_result->exponent = p_poly_1->exponent;
    p_result->coefficient = p_poly_1->coefficient + p_poly_2->coefficient;
    if (p_poly_1->p_next == NULL)
    {
        if (p_poly_2->p_next == NULL)
        {
            p_result->p_next = NULL;
        }
        else
        {
            p_poly_2 = p_poly_2->p_next;
            p_result->p_next = copy(p_poly_2);
        }
    }
    else if (p_poly_2->p_next == NULL)
    {
        p_poly_1 = p_poly_1->p_next;
        p_result->p_next = copy(p_poly_1);
    }
    else
    {
        p_poly_1 = p_poly_1->p_next;
        p_poly_2 = p_poly_2->p_next;
        p_result->p_next = add(p_poly_1, p_poly_2);
    }
    return p_result;
}

void add_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    if (p_poly_1->exponent == p_poly_2->exponent)
    {
        return add_same_degreeIin_pace(p_poly_1, p_poly_2);
    }

    if (p_poly_1->exponent > p_poly_2->exponent)
    {
        if (p_poly_1->p_next == NULL)
        {
            p_poly_1->p_next = copy(p_poly_2);
        }
        else
        {
            add_in_place(p_poly_1->p_next, p_poly_2);
        }
    }
    else if (p_poly_1->exponent < p_poly_2->exponent)
    {
        //add a new base node to p_poly_1
        struct polynomial* new_poly = create_node();
        *new_poly = *p_poly_2;
        new_poly->p_next = p_poly_1;
        p_poly_1 = new_poly;


        if (p_poly_2->p_next != NULL)
        {
            p_poly_2 = p_poly_2->p_next;
            add_in_place(p_poly_1, p_poly_2);
        }
    }
}



void add_same_degree_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    p_poly_1->coefficient += p_poly_2->coefficient;
    if (p_poly_2->p_next != NULL)
    {
        if (p_poly_1->p_next == NULL)
        {
            p_poly_1->p_next = copy(p_poly_2);
        }
        else
        {
            add_in_place(p_poly_1->p_next, p_poly_2->p_next);
        }
    }
}

