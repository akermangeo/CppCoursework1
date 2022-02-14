#include "polynomials.h"

int main()
{
    struct polynomial* poly1 = polynomial_factory_method();
    struct polynomial* poly2 = polynomial_factory_method();
    print_poly(poly1);
    print_poly(poly2);
    print_poly(multiply(poly1, poly2));
}


void print_poly(const struct polynomial* p_poly)
{
    printf("%fx^%d", p_poly->coefficient, p_poly->exponent);
    p_poly = p_poly->p_next;
    while (p_poly != NULL)
    {
        if (p_poly->coefficient >= 0)
        {
            printf(" + ");
            printf("%fx^%d", p_poly->coefficient, p_poly->exponent);
        }
        else
        {
            printf(" - ");
            printf("%fx^%d", p_poly->coefficient, p_poly->exponent);
        }
        p_poly = p_poly->p_next;
        
    }
    printf("\n");
}


//TODO rename
struct polynomial* copy(const struct polynomial* p_poly) 
{
    struct polynomial* p_copy = create_node();
    struct polynomial* p_copy_root = p_copy;
    *p_copy = *p_poly;
    while (p_poly->p_next != NULL)
    {
        p_copy->p_next = create_node();
        p_copy = p_copy->p_next;
        p_poly = p_poly->p_next;
        *p_copy = *p_poly;
    }
    p_copy->p_next = NULL;
    return p_copy_root;
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

