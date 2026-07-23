#include "../include/Polynomial.hpp"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

//--------------------------------------------------
// Private Helper Function
//--------------------------------------------------

void Polynomial::trimPolynomial()
{
    while (coefficients.size() > 1 &&
           std::abs(coefficients.back()) < 1e-9)
    {
        coefficients.pop_back();
    }
}

//--------------------------------------------------
// Constructors
//--------------------------------------------------

Polynomial::Polynomial()
{
    coefficients.push_back(0.0);
}

Polynomial::Polynomial(int degree)
{
    coefficients.assign(degree + 1, 0.0);
}

Polynomial::Polynomial(const std::vector<double>& coeffs)
{
    coefficients = coeffs;
    trimPolynomial();
}

//--------------------------------------------------
// Input Polynomial
//--------------------------------------------------

void Polynomial::inputPolynomial()
{
    int deg;

    std::cout << "\nEnter Degree of Polynomial : ";
    std::cin >> deg;

    coefficients.assign(deg + 1, 0.0);

    for (int i = deg; i >= 0; i--)
    {
        std::cout << "Coefficient of x^"
                  << i
                  << " : ";

        std::cin >> coefficients[i];
    }

    trimPolynomial();
}

//--------------------------------------------------
// Display Polynomial
//--------------------------------------------------

void Polynomial::displayPolynomial() const
{
    bool firstTerm = true;

    for (int i = degree(); i >= 0; i--)
    {
        double coef = coefficients[i];

        if (std::abs(coef) < 1e-9)
            continue;

        if (!firstTerm)
        {
            if (coef >= 0)
                std::cout << " + ";
            else
                std::cout << " - ";
        }
        else
        {
            if (coef < 0)
                std::cout << "-";
        }

        double absCoef = std::abs(coef);

        if (!(absCoef == 1 && i != 0))
            std::cout << absCoef;

        if (i > 0)
        {
            std::cout << "x";

            if (i > 1)
                std::cout << "^" << i;
        }

        firstTerm = false;
    }

    if (firstTerm)
        std::cout << "0";

    std::cout << std::endl;
}
//--------------------------------------------------
// Addition
//--------------------------------------------------

Polynomial Polynomial::add(const Polynomial& other) const
{
    size_t maxSize = std::max(coefficients.size(),
                              other.coefficients.size());

    std::vector<double> result(maxSize, 0.0);

    for (size_t i = 0; i < maxSize; i++)
    {
        if (i < coefficients.size())
            result[i] += coefficients[i];

        if (i < other.coefficients.size())
            result[i] += other.coefficients[i];
    }

    return Polynomial(result);
}

//--------------------------------------------------
// Subtraction
//--------------------------------------------------

Polynomial Polynomial::subtract(const Polynomial& other) const
{
    size_t maxSize = std::max(coefficients.size(),
                              other.coefficients.size());

    std::vector<double> result(maxSize, 0.0);

    for (size_t i = 0; i < maxSize; i++)
    {
        if (i < coefficients.size())
            result[i] += coefficients[i];

        if (i < other.coefficients.size())
            result[i] -= other.coefficients[i];
    }

    return Polynomial(result);
}

//--------------------------------------------------
// Multiplication
//--------------------------------------------------

Polynomial Polynomial::multiply(const Polynomial& other) const
{
    std::vector<double> result(
        degree() + other.degree() + 1,
        0.0);

    for (size_t i = 0; i < coefficients.size(); i++)
    {
        for (size_t j = 0; j < other.coefficients.size(); j++)
        {
            result[i + j] +=
                coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial(result);
}
//--------------------------------------------------
// Evaluate Polynomial
//--------------------------------------------------

double Polynomial::evaluate(double x) const
{
    double result = 0.0;

    for (int i = degree(); i >= 0; i--)
    {
        result = result * x + coefficients[i];
    }

    return result;
}

//--------------------------------------------------
// Degree
//--------------------------------------------------

int Polynomial::degree() const
{
    return static_cast<int>(coefficients.size()) - 1;
}

//--------------------------------------------------
// Check if Zero Polynomial
//--------------------------------------------------

bool Polynomial::isZero() const
{
    for (double coefficient : coefficients)
    {
        if (std::abs(coefficient) > 1e-9)
        {
            return false;
        }
    }

    return true;
}

//--------------------------------------------------
// Clear Polynomial
//--------------------------------------------------

void Polynomial::clear()
{
    coefficients.clear();
    coefficients.push_back(0.0);
}

//--------------------------------------------------
// Getter
//--------------------------------------------------

std::vector<double> Polynomial::getCoefficients() const
{
    return coefficients;
}
//--------------------------------------------------
// Operator Overloading
//--------------------------------------------------

Polynomial Polynomial::operator+(const Polynomial& other) const
{
    return add(other);
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
    return subtract(other);
}

Polynomial Polynomial::operator*(const Polynomial& other) const
{
    return multiply(other);
}

//--------------------------------------------------
// Output Stream Operator
//--------------------------------------------------

std::ostream& operator<<(std::ostream& out,
                         const Polynomial& poly)
{
    bool firstTerm = true;
    const std::vector<double>& coeffs = poly.coefficients;

    for (int i = poly.degree(); i >= 0; i--)
    {
        double coef = coeffs[i];

        if (std::abs(coef) < 1e-9)
            continue;

        if (!firstTerm)
        {
            out << (coef >= 0 ? " + " : " - ");
        }
        else
        {
            if (coef < 0)
                out << "-";
        }

        double absCoef = std::abs(coef);

        if (!(absCoef == 1 && i != 0))
            out << absCoef;

        if (i > 0)
        {
            out << "x";

            if (i > 1)
                out << "^" << i;
        }

        firstTerm = false;
    }

    if (firstTerm)
        out << "0";

    return out;
}

//--------------------------------------------------
// Input Stream Operator
//--------------------------------------------------

std::istream& operator>>(std::istream& in,
                         Polynomial& poly)
{
    int deg;

    std::cout << "Enter Degree of Polynomial: ";
    in >> deg;

    poly.coefficients.assign(deg + 1, 0.0);

    for (int i = deg; i >= 0; i--)
    {
        std::cout << "Coefficient of x^"
                  << i
                  << ": ";

        in >> poly.coefficients[i];
    }

    poly.trimPolynomial();

    return in;
}