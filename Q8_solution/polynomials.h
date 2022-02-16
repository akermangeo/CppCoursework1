#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// <summary>
/// A struct to represent a polynomial node. It is assumed that p_next always points to a node of strictly lower exponent.
/// The last node in the polynomial will have p_next pointing to NULL. None of the coefficients can be 0 unless the
/// polynomial is the constant polynomial 0.
/// </summary>
struct polynomial
{ 
    float coefficient;
    int exponent;
    struct polynomial *p_next;
};

/// <summary>
/// Factory method for polynomial creation. Asks for user input regarding index and coefficients.
/// </summary>
/// <returns>A pointer to the created polynomial.</returns>
struct polynomial* polynomial_factory_method();

/// <summary>
/// Creates a single uninitialised polynomial node initialised to 0x^0 with NULL pointer to next.
/// </summary>
/// <returns>A pointer to the new node.</returns>
struct polynomial* create_node();

/// <summary>
/// Prints the polynomial to the standard output.
/// </summary>
/// <param name="p_poly">The polynomial to print.</param>
void print_poly(const struct polynomial* p_poly);

/// <summary>
/// Adds two polynomials together and returns a pointer to the new polynomial.
/// </summary>
/// <param name="p_poly_1">The first polynomial to add.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
/// <returns>The result of the addition.</returns>
struct polynomial* add(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Adds to polynomials together and stores the result in p_poly_2.
/// </summary>
/// <param name="p_poly_1">The polynomial to add and store the result in.</param>
/// <param name="p_poly_2">The second polynomial to add.</param>
void add_in_place(struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Subtracts poly 2 from poly1, returns a pointer to the result.
/// </summary>
/// <param name="p_poly_1">The polynomial to subtract from.</param>
/// <param name="p_poly_2">The polynomial to subtract.</param>
/// <returns>The result of the subtraction.</returns>
struct polynomial* subtract(const struct polynomial* p_poly1, const struct polynomial* p_poly2);

/// <summary>
/// Multiplies 2 polynomials together, returns a pointer to the result.
/// </summary>
/// <param name="p_poly_1">The first polynomial to multiply.</param>
/// <param name="p_poly_2">The second polynomial to multiply.</param>
/// <returns>The result of the multiplication.</returns>
struct polynomial* multiply(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Coppies a polynomial and returns a pointer to the copy
/// </summary>
/// <param name="p_poly">The polynomial to copy.</param>
/// <returns>A pointer to the copy.</returns>
struct polynomial* copy_polynomial(const struct polynomial* p_poly);

/// <summary>
/// Frees all memory assaciated with a polynomial.
/// </summary>
/// <param name="p_poly">A pointer to the polynomial to free.</param>
void free_polynomial(struct polynomial* p_poly);

/// <summary>
/// Asks the user whether they want to store a polynomial.
/// </summary>
/// <returns>"i" if the polynomial is to replace polynomial_i, for i = 1,2.
///          "0" if the polynomial is not to be stored</returns>
int store_polynomial();

/// <summary>
/// Evaluates the polynomial at the specified point x using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>The result of the evaluation.</returns>
double evaluate(struct polynomial* p_poly, double x);

/// <summary>
/// Add case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_3(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

/// <summary>
/// Subtract case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_4(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

/// <summary>
/// Multiply case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_5(struct polynomial* p_poly_1, struct polynomial* p_poly_2);

/// <summary>
/// Evaluate case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_6(struct polynomial* p_poly_1, struct polynomial* p_poly_2);