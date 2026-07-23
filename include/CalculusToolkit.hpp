#ifndef CALCULUSTOOLKIT_HPP
#define CALCULUSTOOLKIT_HPP

#include "Polynomial.hpp"

class CalculusToolkit
{
public:

    // Derivatives
    static Polynomial firstDerivative(const Polynomial& poly);

    static Polynomial secondDerivative(const Polynomial& poly);

    // Integration
    static Polynomial indefiniteIntegral(const Polynomial& poly);

    static double definiteIntegral(const Polynomial& poly,
                                   double lowerLimit,
                                   double upperLimit);

    // Tangent Line
    static void tangentLine(const Polynomial& poly,
                            double xValue);

    // Area Under Curve
    static double areaUnderCurve(const Polynomial& poly,
                                 double lowerLimit,
                                 double upperLimit);
};

#endif