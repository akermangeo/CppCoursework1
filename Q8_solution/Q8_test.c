#include "polynomials.h"

int main()
{
    int choice, deg_1, deg_2, deg_3, store, poly;
    float val;
    struct polynomial* polynomial_1 = NULL, * polynomial_2 = NULL, * polynomial_3 = NULL;

    do
    {
        printf("1 : Define polynomial 1\n");
        printf("2 : Define polynomial 2\n");
        printf("3 : Add polynomials 1 and 2\n");
        printf("4 : Subtract polynomials\n");
        printf("5 : Multiply polynomials 1 and 2\n");
        printf("6 : Evaluate a polynomial\n");
        printf("7 : Quit\n");
        printf("Input the number corresponding to your option choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the degree of polynomial 1: ");
            scanf("%d", &deg_1);
            polynomial_1 = read(deg_1);
            break;

        case 2:
            printf("Input the degree of polynomial 2: ");
            scanf("%d", &deg_2);
            polynomial_2 = read(deg_2);
            break;

        case 3:
            if (deg_1 >= deg_2)
            {
                deg_3 = deg_1;
            }
            else
            {
                deg_3 = deg_2;
            }

            polynomial_3 = add(polynomial_1, polynomial_2, deg_3);

            printf("Sum = ");
            print_poly(polynomial_3, deg_3);
            store_poly(polynomial_1, &deg_1, polynomial_2, &deg_2, polynomial_3, &deg_3);
            print_poly(polynomial_1, deg_1);

            break;

        case 4:
            printf("Which polynomial would you like to subract from the other?\n");
            printf("(1 - Subtract Polynomial 1 from 2, 2 - Subtract Polynomial 2 from 1)\n");
            scanf("%d", &store);

            if (deg_1 >= deg_2)
            {
                deg_3 = deg_1;
            }
            else
            {
                deg_3 = deg_2;
            }

            if (store == 1)
            {
                polynomial_3 = subtract(polynomial_2, polynomial_1, deg_3);
            }
            if (store == 2)
            {
                polynomial_3 = subtract(polynomial_1, polynomial_2, deg_3);
            }

            printf("Subtraction = ");
            print_poly(polynomial_3, deg_3);
            store_poly(polynomial_1, &deg_1, polynomial_2, &deg_2, polynomial_3, &deg_3);
            print_poly(polynomial_1, deg_1);

            break;

        case 5:
            polynomial_3 = multiply(polynomial_1, deg_1, polynomial_2, deg_2);
            deg_3 = deg_1 + deg_2;

            printf("Product = ");
            print_poly(polynomial_3, deg_3);
            store_poly(polynomial_1, &deg_1, polynomial_2, &deg_2, polynomial_3, &deg_3);
            print_poly(polynomial_1, deg_1);

            break;

        case 6:
            printf("Which polynomial would you like to evaluate? (1/2) ");
            scanf("%d", &poly);

            if (poly != 1 && poly != 2)
            {
                printf("Invalid polynomial index.  Returning to options...");
                break;
            }

            printf("At what value would you like to evaluate polynomial %d? (input float) ", poly);
            scanf("%f", &val);

            if (poly == 1)
            {
                evaluate(polynomial_1, val, deg_1);
            }
            if (poly == 2)
            {
                evaluate(polynomial_2, val, deg_2);
            }

            break;
        }
    } while (0 < choice && choice < 7);

    printf("Goodbye!\n");
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

void store_poly(struct polynomial* p_poly_1, int* degree_1, struct polynomial* p_poly_2, int* degree_2, struct polynomial* p_poly_3, int* degree_3)
{
    static int store;
    struct polynomial* temp_p_poly;

    printf("Would you like to store this polynomial?\n");
    printf("(1 - Replace Polynomial 1, 2 - Replace Polynomial 2, 0 - Do not store)\n");
    scanf("%d", &store);

    if (store == 1)
    {
        temp_p_poly = p_poly_1;
        p_poly_1 = p_poly_3;
        p_poly_3 = temp_p_poly;
        degree_1 = degree_3;
    }
    if (store == 2)
    {
        temp_p_poly = p_poly_2;
        p_poly_2 = p_poly_3;
        p_poly_3 = temp_p_poly;
        degree_2 = degree_3;
    }
    return;
}

struct polynomial* add(const struct polynomial* poly_1, const struct polynomial* poly_2)
{
    const struct polynomial* const p_result = create_node();

    struct polynomial* p_result_current_node = p_result;

    while (poly_1 != NULL || poly_2 != NULL)
    {
        if (poly_1 == NULL)
        {
            p_result_current_node->coefficient = poly_2->coefficient;
            poly_2 = poly_2->p_next;
        }
        else if (poly_2 == NULL)
        {
            p_result_current_node->coefficient = poly_1->coefficient;
            poly_1 = poly_1->p_next;
        }
        else
        {
            p_result_current_node->coefficient = poly_1->coefficient + poly_2->coefficient;
            poly_1 = poly_1->p_next;
            poly_2 = poly_2->p_next;
        }

        p_result_current_node = p_result_current_node->p_next;
    }

    return p_result;
}

//struct polynomial* subtract(struct polynomial* p_head_poly_1, struct polynomial* p_head_poly_2, int degree_3)
//{
//    struct polynomial* p_head_poly_3, * pp_head_poly_3;
//
//    p_head_poly_3 = initialise_poly(degree_3);
//    pp_head_poly_3 = p_head_poly_3;
//
//    while (p_head_poly_1 != NULL || p_head_poly_2 != NULL)
//    {
//        if (p_head_poly_1 == NULL)
//        {
//            p_head_poly_3->coefficient = -p_head_poly_2->coefficient;
//            p_head_poly_2 = p_head_poly_2->p_next;
//        }
//        else if (p_head_poly_2 == NULL)
//        {
//            p_head_poly_3->coefficient = p_head_poly_1->coefficient;
//            p_head_poly_1 = p_head_poly_1->p_next;
//        }
//        else
//        {
//            p_head_poly_3->coefficient = p_head_poly_1->coefficient - p_head_poly_2->coefficient;
//            p_head_poly_1 = p_head_poly_1->p_next;
//            p_head_poly_2 = p_head_poly_2->p_next;
//        }
//        p_head_poly_3 = p_head_poly_3->p_next;
//    }
//
//    return pp_head_poly_3;
//}



struct polynomial* simplyify(struct polynomial* p_head_poly, int degree)
{
    struct polynomial* p_temp1_head_poly = p_head_poly;
    //struct polynomial *p_temp2_head_poly = p_head_poly -> p_next;
    struct polynomial* p_temp3_head_poly;
    int i;

    p_temp3_head_poly = initialise_poly(degree);

    for (i = degree; i >= 0; i--)
    {
        p_temp1_head_poly = p_head_poly;
        while (p_temp1_head_poly != NULL)
        {
            if (p_temp1_head_poly->exponent == p_temp3_head_poly->exponent)
            {
                p_temp3_head_poly->coefficient += p_temp1_head_poly->coefficient;
            }
            /*p_temp2_head_poly = p_head_poly -> p_next;
            while (p_temp2_head_poly != NULL)
            {
              if (p_temp2_head_poly -> exponent == p_head_poly -> exponent)
              {
                p_temp3_head_poly -> coefficient += p_temp2_head_poly -> coefficient;
              }
              p_temp2_head_poly = p_temp2_head_poly -> p_next;
            }*/
            p_temp1_head_poly = p_temp1_head_poly->p_next;
        }
        p_temp3_head_poly = p_temp3_head_poly->p_next;
    }

    return p_temp3_head_poly;
}

void evaluate(struct polynomial* p_poly, float x, int degree)
{
    float value;
    int i, j;
    struct polynomial* p_temp_poly = p_poly;

    for (i = degree; i >= 0; i--)
    {
        p_temp_poly = p_poly;

        for (j = 0; j < i; j++)
        {
            p_temp_poly = p_temp_poly->p_next;
        }

        value += p_temp_poly->coefficient;
        if (i != 0)
        {
            value *= x;
        }
    }

    printf("%f", value);
    return;
}