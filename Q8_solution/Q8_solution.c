#include <stdlib.h>
#include <stdio.h>

#include "polynomials.h"
#include "userIO.h"

/// <summary>
/// Asks the user whether they want to store a polynomial and replaces that polynomial with p_poly_temp.
/// </summary>
/// <param name="p_poly_temp">The polynomial to replace another.</param>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
int store_polynomial();

/// <summary>
/// Add case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_add(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Subtract case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_subtract(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Multiply case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_multiply(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);


int main()
{
    printf("Define polynomial 1\n");
    struct polynomial* polynomial_1 = polynomial_factory_method();
    printf("Define polynomial 2\n");
    struct polynomial* polynomial_2 = polynomial_factory_method();
    
    int choice;
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
        
        choice = read_int();

        struct polynomial* polynomial_temp = create_node();

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
            case_add(polynomial_temp, polynomial_1, polynomial_2);
            break;

        case 4:
            case_subtract(polynomial_temp, polynomial_1, polynomial_2);
            break;

        case 5:
            case_multiply(polynomial_temp, polynomial_1, polynomial_2);
            break;

        case 6:
            case_evaluate(polynomial_1, polynomial_2);
            break;

        case 7:
            free_polynomial(polynomial_1);
            free_polynomial(polynomial_2);
            free_polynomial(polynomial_temp);
            printf("Goodbye!\n");
            return EXIT_SUCCESS;
        
        default:
            printf("Invalid input, exiting...");
            return EXIT_SUCCESS;
        }   

        if (choice == 3 || choice == 4 || choice == 5)
        {
            int store = store_polynomial();

            if (store == 0)
            {
                free_polynomial(polynomial_temp);
            }
            else if (store == 1)
            {
                free_polynomial(polynomial_1);
                polynomial_1 = polynomial_temp;
            }
            else if (store == 2)
            {
                free_polynomial(polynomial_2);
                polynomial_2 = polynomial_temp;
            }
        }
    } while (0 < choice && choice < 7);
}


void print_poly(const struct polynomial* p_poly)
{
    printf("%.2fx^%d", p_poly->coefficient, p_poly->exponent);
    p_poly = p_poly->p_next;
    while (p_poly != NULL)
    {
        if (p_poly->coefficient >= 0)
        {
            printf(" + ");
            printf("%.2fx^%d", p_poly->coefficient, p_poly->exponent);
        }
        else
        {
            printf(" - ");
            printf("%.2fx^%d", fabs(p_poly->coefficient), p_poly->exponent);
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

int store_polynomial()
{

    printf("Would you like to store the resulting polynomial?\n");
    printf("(1 - Replace Polynomial 1, 2 - Replace Polynomial 2, 0 - Do not store)\n");
    int store = read_int();
    if (store < 0 || store > 2)
    {
        printf("Invalid entry.  Returning to options...");
        return 0;
    }
    else
    {
        return store;
    }
}