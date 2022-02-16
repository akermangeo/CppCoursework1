/// <summary>
/// Add case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_3(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Subtract case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_4(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Multiply case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_5(struct polynomial* p_poly_temp, const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Evaluate case function.
/// </summary>
/// <param name="p_poly_1">The first polynomial.</param>
/// <param name="p_poly_2">The second polynomial.</param>
void case_6(const struct polynomial* p_poly_1, const struct polynomial* p_poly_2);

/// <summary>
/// Evaluates the polynomial at the specified point x using Horner's method.
/// </summary>
/// <param name="p_poly">A pointer to the poltnomial to evaluate.</param>
/// <param name="x">Value at which to evaluate the polynomial.</param>
/// <returns>The result of the evaluation.</returns>
double evaluate(const struct polynomial* p_poly, double x);
