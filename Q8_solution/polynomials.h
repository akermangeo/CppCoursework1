#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{ 
    int coefficient;
    int exponent;
    struct polynomial *p_next;
};

/// <summary>
/// Factory method for polynomial creation. Asks for user input regarding index and coefficients.
/// </summary>
/// <returns>A pointer to the created polynomial.</returns>
struct polynomial* polynomial_factory_method();

/// <summary>
/// Creates a single uninitialised polynomial node.
/// </summary>
/// <returns>A pointer to the new node.</returns>
struct polynomial* create_node();

/// <summary>
/// Initialises a new polynomial to be defined later.
/// </summary>
/// <param name="degree">Degree of polynomial to be initalised.</param>
/// <returns>Pointer to the new polynomial.</returns>
//struct polynomial *initialise_poly(int degree);

/// <summary>
/// Prints the polynomial to the standard output.
/// </summary>
/// <param name="poly">The polynomial to print.</param>
void print_poly(struct polynomial poly);

/// <summary>
/// Adds two polynomials together and returns a pointer to the new polynomial.
/// </summary>
/// <param name="p_poly_1">The first polynomial to add.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
/// <returns>The result of the addition.</returns>
struct polynomial* add(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

/// <summary>
/// Subtracts poly 2 from poly1.
/// </summary>
/// <param name="p_poly_1">The polynomial to subtract from.</param>
/// <param name="p_poly_2">The polynomial to subtract.</param>
/// <returns>The result of the subtraction.</returns>
struct polynomial subtract(struct polynomial poly1, struct polynomial poly2);

/// <summary>
/// Multiplies 2 polynomials together, returns a pointer to the result.
/// </summary>
/// <param name="p_poly_1">The first polynomial to multiply.</param>
/// <param name="p_poly_2">The second polynomial to multiply.</param>
/// <returns>The result of the multiplication.</returns>
struct polynomial* multiply(struct polynomial p_poly_1, struct polynomial p_poly_2);

/// <summary>
/// Evaluates the polynomial at the specified point x using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>The result of the evaluation.</returns>
float evaluate(struct polynomial p_poly, float x);


void free_poly(struct polynomial *p_head_poly, int degree);