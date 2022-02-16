#include "polynomials.h"

struct polynomial* add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    //We handle the case when one of the polynomials is 0. If the first coefficient is 0 then
    //the whole polynomial is 0. Id the first coefficient is non-zero then all the coefficients are non-zero.
    if (p_poly_1->coefficient == 0)
    {
        return copy_polynomial(p_poly_2);
    }
    if (p_poly_2->coefficient == 0)
    {
        return copy_polynomial(p_poly_1);
    }

    struct polynomial* p_result = NULL;
    struct polynomial** pp_result_next_node = &p_result;


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
        else //We skip both these nodes if there coefficients sum to 0.
        {
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
        }
    }
    
    //One of the polynomials may still have a tail that is unacounted for.
    //Notice the tail will not be just 0 as this case is handled at the start of the function.
    if (p_poly_2 != NULL)
    {
        struct polynomial* p_remaining_terms = copy_polynomial(p_poly_2);
        *pp_result_next_node = p_remaining_terms;
    }
    else if (p_poly_1 != NULL)
    {
        struct polynomial* p_remaining_terms = copy_polynomial(p_poly_1);
        *pp_result_next_node = p_remaining_terms;
    }

    //The result could be 0 in which case the pointer will be NULL at this point
    if (p_result == NULL)
    {
        p_result = create_node();
    }
    return p_result;
}

void add_in_place(struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    //We handle the case when one of the polynomials is 0. If the first coefficient is 0 then
    //the whole polynomial is 0. Id the first coefficient is non-zero then all the coefficients are non-zero.
    if (p_poly_2->coefficient == 0)
    {
        return;
    }
    if (p_poly_1->coefficient == 0)
    {
        *p_poly_1 = *p_poly_2;
        if (p_poly_2->p_next != NULL)
        {
            p_poly_1->p_next = copy_polynomial(p_poly_2->p_next);
        }
        else
        {
            p_poly_1->p_next = NULL;
        }
        return;
    }

    struct polynomial** pp_next_node = &p_poly_1;
    const struct polynomial* p_poly_1_copy = p_poly_1;

    while (p_poly_1 != NULL && p_poly_2 != NULL)
    {
        if (p_poly_1->exponent > p_poly_2->exponent)
        {
            pp_next_node = &(*pp_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
        }
        else if (p_poly_1->exponent < p_poly_2->exponent)
        {
            //add a new node into p_poly_1
            struct polynomial* p_temp_node = *pp_next_node;
            *pp_next_node = create_node();
            **pp_next_node = *p_poly_2;
            pp_next_node = &(*pp_next_node)->p_next;
            *pp_next_node = p_temp_node;
            p_poly_2 = p_poly_2->p_next;
        }
        else if (p_poly_1->coefficient + p_poly_2->coefficient != 0)
        {
            (*pp_next_node)->coefficient += p_poly_2->coefficient;
            pp_next_node = &(*pp_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
        }
        else //We skip both these nodes if there coefficients sum to 0.
        {
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
        }
    }

    //p_poly_2 may still have a tail that is unacounted for.
    //Notice the tail will not be just 0 as this case is handled at the start of the function.
    if (p_poly_2 != NULL)
    {
        struct polynomial* p_remaining_terms = copy_polynomial(p_poly_2);
        *pp_next_node = p_remaining_terms;
    }


    //The result could be 0 in which case the pointer will be NULL at this point
    if (p_poly_1_copy == NULL)
    {
        p_poly_1_copy = create_node();
    }

}
