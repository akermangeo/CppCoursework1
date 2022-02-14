#include "polynomials.h"

/// <summary>
/// Cuts off the leading terms with zero coefficients.
/// </summary>
/// <param name="p_poly">The polynomial to cut.</param>
/// <returns>The cut down polynomial. This could be NULL.</returns>
struct polynomial* cut_off_leading_zeros(struct polynomial* p_poly);

/// <summary>
/// Removes all terms that are zero from a polynomial and returns a copy, leaving the orriginal unchanged.
/// </summary>
/// <param name="p_poly">The polynomial to reduce.</param>
/// <returns>A pointer to the reduced polynomial copy. This could be NULL.</returns>
struct polynomial* remove_zero_terms(const struct polynomial* p_poly);

struct polynomial* add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    struct polynomial* p_result = NULL;
    struct polynomial** pp_result_next_node = &p_result;

    cut_off_leading_zeros(p_poly_1);
    cut_off_leading_zeros(p_poly_2);
    while (p_poly_1 != NULL && p_poly_2 != NULL)
    {
        if (p_poly_1->exponent > p_poly_2->exponent)
        {
            *pp_result_next_node = create_node();
            **pp_result_next_node = *p_poly_1;
            pp_result_next_node = &(* pp_result_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
        }
        else if (p_poly_1->exponent < p_poly_2->exponent)
        {
            *pp_result_next_node = create_node();
            **pp_result_next_node = *p_poly_2;
            pp_result_next_node = &(*pp_result_next_node)->p_next;
            p_poly_2 = p_poly_2->p_next;
        }
        else if (p_poly_1->coefficient + p_poly_2->coefficient != 0)
        {
            *pp_result_next_node = create_node();
            **pp_result_next_node = *p_poly_1;
            (* pp_result_next_node)->coefficient += p_poly_2->coefficient;
            pp_result_next_node = &(*pp_result_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
        }
        else
        {
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
        }

        cut_off_leading_zeros(p_poly_1);
        cut_off_leading_zeros(p_poly_2);
    }
    
    if (p_poly_1 == NULL && p_poly_2 != NULL)
    {
        struct polynomial* p_remaining_terms = remove_zero_terms(p_poly_2);
        *pp_result_next_node = p_remaining_terms;
    }
    else if (p_poly_2 == NULL && p_poly_1 != NULL)
    {
        struct polynomial* p_remaining_terms = remove_zero_terms(p_poly_1);
        *pp_result_next_node = p_remaining_terms;
    }

    if (p_result == NULL)
    {
        p_result = create_node();
    }
    return p_result;
}

//TODO fix
void add_in_place(struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    //early returns
    if (p_poly_2 == NULL)
    {
        return;
    }

    //TODO remove
    if (p_poly_1 == NULL)
    {
        printf("This method should never be called with p_poly_1 == NULL.");
        return;
    }

    if (p_poly_1->exponent > p_poly_2->exponent) //We take the first node from p_poly 1
    {
        if (p_poly_1->p_next == NULL)
        {
            p_poly_1->p_next = add(p_poly_1->p_next, p_poly_2);
        }
        else
        {
            add_in_place(p_poly_1->p_next, p_poly_2);
        }
    }
    else if (p_poly_2->exponent > p_poly_1->exponent) //We take the first node from p_poly 2
    {
        //add a new base node to p_poly_1 and set it equal to the base of p_poly_2
        struct polynomial* new_poly = create_node();
        *new_poly = *p_poly_2;
        new_poly->p_next = p_poly_1;
        p_poly_1 = new_poly;
        add_in_place(p_poly_1->p_next, p_poly_2->p_next);
    }
    else if (p_poly_1->coefficient + p_poly_2->coefficient != 0) //We take the sum of both first nodes
    {
        p_poly_1->coefficient += p_poly_2->coefficient;
        if (p_poly_1->p_next == NULL)
        {
            p_poly_1->p_next = add(p_poly_1->p_next, p_poly_2->p_next);
        }
        else
        {
            add_in_place(p_poly_1->p_next, p_poly_2->p_next);
        }
        
    }
    else //We skip these nodes altogether because they sum to 0.
    {
        //remove the next node from the chain by duplicating it up the chain 1 space.
        if (p_poly_1->p_next != NULL)
        {
            *p_poly_1 = *p_poly_1->p_next;
            free(p_poly_1->p_next);
            add_in_place(p_poly_1, p_poly_2->p_next);
        }
        else
        {
            p_poly_1->p_next = copy(p_poly_2->p_next);
        }
    }
}

struct polynomial* cut_off_leading_zeros(struct polynomial* p_poly)
{
    while (p_poly != NULL && p_poly->coefficient == 0)
    {
        p_poly = p_poly->p_next;
    }
    return p_poly;
}

struct polynomial* remove_zero_terms(const struct polynomial* p_poly)
{
    struct polynomial* p_result = NULL;
    struct polynomial** pp_result_next_node = &p_result;
    while (p_poly != NULL)
    {
        if (p_poly->coefficient != 0)
        {
            *pp_result_next_node = create_node();
            **pp_result_next_node = *p_poly;
            *pp_result_next_node = (*pp_result_next_node)->p_next;
        }
    }
    return p_result;
}