#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{ 
    int coefficient;
    int exponent;
    struct node *p_next;
};

/// <summary>
/// Prints the polynomial to the standard output.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial.</param>
/// <returns>Nothing (uses pointers).</returns>
struct node *simplyify(struct node *p_poly, int degree);

/// <summary>
/// Defines a term in the given polynomial.
/// </summary>
/// <param name="pp_poly">A pointer to a pointer to the poltnomial to define.</param>
/// <param name="coeff">Exponent of polynomial term..</param>
/// <param name="exp">Exponent of polynomial term.</param>
/// <returns>Nothing (uses pointers).</returns>
void create_poly(struct node **pp_poly,int coeff,int exp);

/// <summary>
/// Initialises a new polynomial to be defined later.
/// </summary>
/// <param name="degree">Degree of polynomial to be initalised.</param>
/// <returns>Pointer to the new polynomial.</returns>
struct node *initialise_poly(int degree);

/// <summary>
/// Prints the polynomial to the standard output.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial.</param>
/// <returns>Nothing (uses pointers).</returns>
void print_poly(struct node *p_poly, int degree);

/// <summary>
/// Adds two polynomials together.
/// </summary>
/// <param name="p_poly_1">A pointer to the poltnomial.</param>
/// <param name="p_poly_2">A pointer to another poltnomial.</param>
/// <returns>Nothing (uses pointers).</returns>
struct node *add(struct node *p_head_poly_1, struct node *p_head_poly_2, int degree_3);

/// <summary>
/// Subtracts polynomial 2 from polynomial 1.
/// </summary>
/// <param name="p_poly_1">A pointer to the poltnomial.</param>
/// <param name="p_poly_2">A pointer to another poltnomial (the one to be subtracted).</param>
/// <returns>Nothing (uses pointers).</returns>
struct node *subtract(struct node *p_head_poly_1, struct node *p_head_poly_2, int degree_3);

/// <summary>
/// Multiplies 2 polynomials together.
/// </summary>
/// <param name="p_poly_1">A pointer to the poltnomial.</param>
/// <param name="p_poly_2">A pointer to another poltnomial.</param>
/// <returns>Nothing (uses pointers).</returns>
struct node *multiply(struct node *p_head_poly_1, int degree_1, struct node *p_head_poly_2, int degree_2);

/// <summary>
/// Evaluates the polynomial at the specified point using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>Nothing (uses pointers).</returns>
void evaluate(struct node *p_poly, float x, int degree);

/// <summary>
/// Replaces either polynomial 1 or 2 with the third.
/// </summary>
/// <param name="p_poly_1">A pointer to the first poltnomial.</param>
/// <param name="p_poly_2">A pointer to the second poltnomial.</param>
/// <param name="p_poly_3">A pointer to the third poltnomial.</param>
/// <returns>Nothing (uses pointers).</returns>
void store_poly(struct node *p_poly_1, int *degree_1, struct node *p_poly_2, int *degree_2, struct node *p_poly_3, int *degree_3);

//void read(struct node *p_head_poly, int degree);

struct node *read(int degree);

void free_poly(struct node *p_head_poly, int degree);