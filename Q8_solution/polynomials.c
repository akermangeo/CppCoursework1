#include "polynomials.h"
#include "polynomialCases.h"

int main()
{
    /*
    struct polynomial* polynomial_temp;
    double val = 3.14159;

    printf("Define polynomial 1\n");
    struct polynomial* polynomial_1 = polynomial_factory_method();
    printf("Define polynomial 2\n");
    struct polynomial* polynomial_2 = polynomial_factory_method();

    polynomial_temp = add(polynomial_1, polynomial_2);
    free_polynomial(polynomial_1);
    polynomial_1 = polynomial_temp;
    print_poly(polynomial_1);
    polynomial_temp = multiply(polynomial_1, polynomial_2);
    free_polynomial(polynomial_1);
    polynomial_1 = polynomial_temp;
    print_poly(polynomial_1);
    printf("%lf\n", evaluate(polynomial_2, val));

    printf("Goodbye!\n");

    free_polynomial(polynomial_1);
    free_polynomial(polynomial_2);

    return EXIT_SUCCESS;
    */

    // /*

    int choice;
    
    printf("Define polynomial 1\n");
    struct polynomial* polynomial_1 = polynomial_factory_method();
    printf("Define polynomial 2\n");
    struct polynomial* polynomial_2 = polynomial_factory_method();

    do
    {
        printf("1 : Print polynomial 1\n");
        printf("2 : Print polynomial 2\n");
        printf("3 : Add polynomials 1 and 2\n");
        printf("4 : Subtract polynomials\n");
        printf("5 : Multiply polynomials 1 and 2\n");
        printf("6 : Evaluate a polynomial\n");
        printf("7 : Quit\n");
        printf("Input the number corresponding to your option choice: ");
        scanf_s("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Polynomial 1 = ");
            print_poly(polynomial_1);
            break;

        case 2:
            printf("Polynomial 2 = ");
            print_poly(polynomial_2);
            break;

        case 3:
            case_3(polynomial_1, polynomial_2);
            break;

        case 4:
            case_4(polynomial_1, polynomial_2);
            break;

        case 5:
            case_5(polynomial_1, polynomial_2);
            break;

        case 6:
            case_6(polynomial_1, polynomial_2);
            break;
        }
    } while (0 < choice && choice < 7);

    free_polynomial(polynomial_1);
    free_polynomial(polynomial_2);

    printf("Goodbye!\n");
    return EXIT_SUCCESS;
    
    // */
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
            printf("%fx^%d", fabs(p_poly->coefficient), p_poly->exponent);
        }
        p_poly = p_poly->p_next;
        
    }
    printf("\n");
}


struct polynomial* copy_polynomial(const struct polynomial* p_poly)
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