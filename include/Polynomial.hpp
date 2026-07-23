#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <vector>
#include <string>

class Polynomial
{
private:
    // coefficients[i] represents the coefficient of x^i
    std::vector<double> coefficients;

    // Remove unnecessary trailing zeros
    void trimPolynomial();

public:

    /*--------------------------------------------------
                    Constructors
    ---------------------------------------------------*/

    Polynomial();
    Polynomial(int degree);
    Polynomial(const std::vector<double>& coeffs);

    /*--------------------------------------------------
                    Input / Output
    ---------------------------------------------------*/

    void inputPolynomial();
    void displayPolynomial() const;

    /*--------------------------------------------------
                Polynomial Operations
    ---------------------------------------------------*/

    Polynomial add(const Polynomial& other) const;

    Polynomial subtract(const Polynomial& other) const;

    Polynomial multiply(const Polynomial& other) const;

    /*--------------------------------------------------
                    Utility Functions
    ---------------------------------------------------*/

    double evaluate(double x) const;

    int degree() const;

    bool isZero() const;

    void clear();

    /*--------------------------------------------------
                    Getters
    ---------------------------------------------------*/

    std::vector<double> getCoefficients() const;

    /*--------------------------------------------------
                Operator Overloading
    ---------------------------------------------------*/

    Polynomial operator+(const Polynomial& other) const;

    Polynomial operator-(const Polynomial& other) const;

    Polynomial operator*(const Polynomial& other) const;

    friend std::ostream& operator<<(std::ostream& out,
                                    const Polynomial& poly);

    friend std::istream& operator>>(std::istream& in,
                                    Polynomial& poly);
};

#endif