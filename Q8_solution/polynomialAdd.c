#include "polynomials.h"

/// <summary>
/// Adds 2 polynomials of the same degree together and stores the result in p_poly_1.
/// </summary>
/// <param name="p_poly_1">The polynomial to add and store the result in.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
void add_same_degree_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

struct polynomial* add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2)
{
    //early returns
    if (p_poly_1 == NULL)
    {
        if (p_poly_2 == NULL)
        {
            return NULL;
        }
        return copy(p_poly_2);
    }
   
    //early return
    if (p_poly_2 == NULL)
    {
        return copy(p_poly_1);
    }


    struct polynomial* p_result = create_node();

    if (p_poly_1->exponent > p_poly_2->exponent) //We take the first node from p_poly 1
    {
        *p_result = *p_poly_1;
        p_poly_1 = p_poly_1->p_next;
        p_result->p_next = add(p_poly_1, p_poly_2);
    }
    else if (p_poly_2->exponent > p_poly_1->exponent) //We take the first node from p_poly 2
    {
        *p_result = *p_poly_2;
        p_poly_2 = p_poly_2->p_next;
        p_result->p_next = add(p_poly_1, p_poly_2);
    }
    else if (p_poly_1->coefficient + p_poly_2->coefficient != 0) //We take the sum of both first nodes
    {
        *p_result = *p_poly_1;
        p_result->coefficient += p_poly_2->coefficient;
        p_poly_1 = p_poly_1->p_next;
        p_poly_2 = p_poly_2->p_next;
        p_result->p_next = add(p_poly_1, p_poly_2);
    }
    else //We skip these nodes altogether because they sum to 0.
    {
        p_poly_1 = p_poly_1->p_next;
        p_poly_2 = p_poly_2->p_next;
        p_result = add(p_poly_1, p_poly_2);
    }
    return p_result;
}

void add_in_place(struct polynomial* p_poly_1, struct polynomial* p_poly_2)
{
    //early returns
    if (p_poly_1 == NULL)
    {
        if (p_poly_2 == NULL)
        {
            return;
        }
        p_poly_1 = copy(p_poly_2);
    }
    
    //early returns
    if (p_poly_2 == NULL)
    {
        return;
    }


    if (p_poly_1->exponent > p_poly_2->exponent) //We take the first node from p_poly 1
    {
        add_in_place(p_poly_1->p_next, p_poly_2);
    }
    else if (p_poly_2->exponent > p_poly_1->exponent) //We take the first node from p_poly 2
    {
        //add a new base node to p_poly_1
        struct polynomial* new_poly = create_node();
        *new_poly = *p_poly_2;
        new_poly->p_next = p_poly_1;
        p_poly_1 = new_poly;
        add_in_place(p_poly_1->p_next, p_poly_2->p_next);
    }
    else if (p_poly_1->coefficient + p_poly_2->coefficient != 0) //We take the sum of both first nodes
    {
        p_poly_1->coefficient += p_poly_2->coefficient;
        add_in_place(p_poly_1->p_next, p_poly_2->p_next);
    }
    else //We skip these nodes altogether because they sum to 0.
    {
        //remove the next node from the chain by duplicating it up the chain 1 space.
        if (p_poly_1->p_next != NULL)
        {
            *p_poly_1 = *p_poly_1->p_next;
            free(p_poly_1->p_next);
        }
        if (p_poly_2->p_next != NULL)
        {
            *p_poly_2 = *p_poly_2->p_next;
            free(p_poly_2->p_next);
        }
        add_in_place(p_poly_1, p_poly_2);
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

