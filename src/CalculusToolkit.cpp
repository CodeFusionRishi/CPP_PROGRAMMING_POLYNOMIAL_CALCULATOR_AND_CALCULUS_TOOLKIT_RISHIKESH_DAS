#include "../include/CalculusToolkit.hpp"

#include <cmath>
#include <iostream>

//--------------------------------------------------
// First Derivative
//--------------------------------------------------

Polynomial CalculusToolkit::firstDerivative(const Polynomial& poly)
{
    std::vector<double> coeffs = poly.getCoefficients();

    if (coeffs.size() <= 1)
        return Polynomial();

    std::vector<double> result(coeffs.size() - 1);

    for (size_t i = 1; i < coeffs.size(); i++)
    {
        result[i - 1] = coeffs[i] * i;
    }

    return Polynomial(result);
}

//--------------------------------------------------
// Second Derivative
//--------------------------------------------------

Polynomial CalculusToolkit::secondDerivative(const Polynomial& poly)
{
    return firstDerivative(firstDerivative(poly));
}

//--------------------------------------------------
// Indefinite Integration
//--------------------------------------------------

Polynomial CalculusToolkit::indefiniteIntegral(const Polynomial& poly)
{
    std::vector<double> coeffs = poly.getCoefficients();

    std::vector<double> result(coeffs.size() + 1, 0.0);

    for (size_t i = 0; i < coeffs.size(); i++)
    {
        result[i + 1] = coeffs[i] / (i + 1);
    }

    return Polynomial(result);
}

//--------------------------------------------------
// Definite Integration
//--------------------------------------------------

double CalculusToolkit::definiteIntegral(const Polynomial& poly,
                                         double lowerLimit,
                                         double upperLimit)
{
    Polynomial integral = indefiniteIntegral(poly);

    return integral.evaluate(upperLimit) -
           integral.evaluate(lowerLimit);
}
//--------------------------------------------------
// Tangent Line
//--------------------------------------------------

void CalculusToolkit::tangentLine(const Polynomial& poly,
                                  double xValue)
{
    Polynomial derivative = firstDerivative(poly);

    double slope = derivative.evaluate(xValue);
    double y = poly.evaluate(xValue);

    std::cout << "\n=====================================\n";
    std::cout << "Tangent Line at x = " << xValue << "\n";
    std::cout << "=====================================\n";

    std::cout << "Slope (m) = " << slope << std::endl;
    std::cout << "Point = (" << xValue
              << ", " << y << ")" << std::endl;

    std::cout << "\nEquation:\n";
    std::cout << "y - " << y
              << " = "
              << slope
              << "(x - "
              << xValue
              << ")\n";
}

//--------------------------------------------------
// Area Under Curve
//--------------------------------------------------

double CalculusToolkit::areaUnderCurve(const Polynomial& poly,
                                       double lowerLimit,
                                       double upperLimit)
{
    double area = definiteIntegral(poly,
                                   lowerLimit,
                                   upperLimit);

    return std::abs(area);
}
