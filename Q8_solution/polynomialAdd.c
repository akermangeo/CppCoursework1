#include <stdlib.h>
#include <stdbool.h>

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
            pp_result_next_node = &(*pp_result_next_node)->p_next;
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
            (*pp_result_next_node)->coefficient += p_poly_2->coefficient;
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

    //This may still be poiting to a poly1 or poly2 node.
    *pp_result_next_node = NULL;

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

        return;
    }
    
    //tracks weather all the nodes are canceling each other out
    bool base_node_found = false;

    struct polynomial** pp_next_node = &p_poly_1;

    while (p_poly_1 != NULL && p_poly_2 != NULL)
    {
        if (p_poly_1->exponent > p_poly_2->exponent)
        {
            pp_next_node = &(*pp_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
            base_node_found = true;
        }
        else if (p_poly_1->exponent < p_poly_2->exponent)
        {
            struct polynomial* new_node = create_node();
            *new_node = *p_poly_1;
            *p_poly_1 = *p_poly_2;
            p_poly_1->p_next = new_node;
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
            base_node_found = true;
        }
        //If the sum is 0 we skip it unless it is the original node.
        else if (p_poly_1->coefficient + p_poly_2->coefficient == 0)
        {
            //If they exist, shift the poly_1 nodes up the chain.
            if (p_poly_1->p_next != NULL)
            {
                struct polynomial* temp_to_delete = p_poly_1->p_next;
                *p_poly_1 = *p_poly_1->p_next;
                free(temp_to_delete);
            }
            else if (base_node_found) //If it's safe to delete the node we delete the node.
            {
                free(p_poly_1);
                p_poly_1 = NULL;
                *pp_next_node = NULL;
            }
            else //If it's not safe to delete the node then we set it to the constant 0 polynomial.
            {
                p_poly_1->coefficient = 0;
                p_poly_1->exponent = 0;
                p_poly_1->p_next = NULL;
            }
            p_poly_2 = p_poly_2->p_next;
        }
        else
        {
            
            (*pp_next_node)->coefficient += p_poly_2->coefficient;
            pp_next_node = &(*pp_next_node)->p_next;
            p_poly_1 = p_poly_1->p_next;
            p_poly_2 = p_poly_2->p_next;
            base_node_found = true;
        }
    }

    //p_poly_2 may still have a tail that is unacounted for.
    //Notice the tail will not be just 0 as this case is handled at the start of the function.
    if (p_poly_2 != NULL)
    {
        struct polynomial* p_remaining_terms = copy_polynomial(p_poly_2);
        *pp_next_node = p_remaining_terms;
    }    
}