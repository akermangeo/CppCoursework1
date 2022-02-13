#include "polynomials.h"

int main()
{
    return EXIT_SUCCESS;
}


void print_poly(struct polynomial* p_head_poly, int degree)
{
    float abs_coeff;
    struct polynomial* ptr = p_head_poly;

    while (ptr != NULL)
    {
        if (ptr->exponent != 0)
        {
            if (ptr->coefficient >= 0)
            {
                printf(" + ");
            }
            else
            {
                printf(" - ");
            }
        }
        abs_coeff = abs(ptr->coefficient);
        printf("%fx^%d", abs_coeff, ptr->exponent);
        ptr = ptr->p_next;
    }
    printf("\n");
}

//float evaluate(struct polynomial* p_poly, float x, int degree)
//{
//    float value;
//    int i, j;
//    struct polynomial* p_temp_poly = p_poly;
//
//    for (i = degree; i >= 0; i--)
//    {
//        p_temp_poly = p_poly;
//
//        for (j = 0; j < i; j++)
//        {
//            p_temp_poly = p_temp_poly->p_next;
//        }
//
//        value += p_temp_poly->coefficient;
//        if (i != 0)
//        {
//            value *= x;
//        }
//    }
//
//    printf("%f", value);
//    return;
//}

struct polynomial* copy(struct polynomial* p_poly) 
{
    struct polynomial* p_copy = create_node();
    *p_copy = *p_poly;
    while (p_poly->p_next != NULL)
    {
        p_copy->p_next = create_node();
        p_copy = p_copy->p_next;
        p_poly = p_poly->p_next;
        *p_copy = *p_poly;
    }
    p_copy->p_next = NULL;
    return p_copy;
}

void free_polynomial(struct polynomial* p_poly)
{
    while (p_poly->p_next != NULL)
    {
        struct polynomial* p_next_poly = p_poly->p_next;
        free(p_poly);
        p_poly = p_next_poly;
    }
    free(p_poly);
}

