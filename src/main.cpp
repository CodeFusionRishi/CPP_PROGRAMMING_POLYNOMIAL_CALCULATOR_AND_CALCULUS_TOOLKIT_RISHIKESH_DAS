#include "../include/Polynomial.hpp"
#include "../include/CalculusToolkit.hpp"
#include "../include/Utilities.hpp"

#include <iostream>

int main()
{
    Polynomial poly1;
    Polynomial poly2;
    Polynomial result;

    int mainChoice;

    do
    {
        Utilities::clearScreen();

        Utilities::showMainMenu();

        mainChoice =
            Utilities::getValidatedInteger("\nEnter Choice : ");

        switch (mainChoice)
        {

        //--------------------------------------------------
        // Polynomial Operations
        //--------------------------------------------------

        case 1:
        {
            int choice;

            do
            {
                Utilities::clearScreen();

                Utilities::showPolynomialMenu();

                choice =
                    Utilities::getValidatedInteger("\nChoice : ");

                switch (choice)
                {

                case 1:

                    std::cout << "\nEnter First Polynomial\n";
                    poly1.inputPolynomial();

                    std::cout << "\nEnter Second Polynomial\n";
                    poly2.inputPolynomial();

                    Utilities::saveHistory(
                        "Created two polynomials");

                    Utilities::pauseScreen();

                    break;

                case 2:

                    std::cout << "\nPolynomial 1 : ";
                    poly1.displayPolynomial();

                    std::cout << "\nPolynomial 2 : ";
                    poly2.displayPolynomial();

                    Utilities::pauseScreen();

                    break;

                case 3:

                    result = poly1 + poly2;

                    std::cout << "\nAddition Result :\n";

                    result.displayPolynomial();

                    Utilities::saveHistory(
                        "Performed Addition");

                    Utilities::pauseScreen();

                    break;

                case 4:

                    result = poly1 - poly2;

                    std::cout << "\nSubtraction Result :\n";

                    result.displayPolynomial();

                    Utilities::saveHistory(
                        "Performed Subtraction");

                    Utilities::pauseScreen();

                    break;

                case 5:

                    result = poly1 * poly2;

                    std::cout << "\nMultiplication Result :\n";

                    result.displayPolynomial();

                    Utilities::saveHistory(
                        "Performed Multiplication");

                    Utilities::pauseScreen();

                    break;

                case 6:
                {
                    double x =
                        Utilities::getValidatedDouble(
                            "\nEnter x : ");

                    std::cout
                        << "\nP1(" << x << ") = "
                        << poly1.evaluate(x)
                        << std::endl;

                    Utilities::pauseScreen();

                    break;
                }

                case 7:

                    std::cout
                        << "\nDegree of Polynomial 1 : "
                        << poly1.degree()
                        << std::endl;

                    Utilities::pauseScreen();

                    break;

                }

            } while (choice != 0);

            break;
        }
                //--------------------------------------------------
        // Calculus Toolkit
        //--------------------------------------------------

        case 2:
        {
            int choice;

            do
            {
                Utilities::clearScreen();

                Utilities::showCalculusMenu();

                choice =
                    Utilities::getValidatedInteger("\nChoice : ");

                switch (choice)
                {

                case 1:

                    result =
                        CalculusToolkit::firstDerivative(poly1);

                    std::cout
                        << "\nFirst Derivative:\n";

                    result.displayPolynomial();

                    Utilities::saveHistory(
                        "Calculated First Derivative");

                    Utilities::pauseScreen();

                    break;

                case 2:

                    result =
                        CalculusToolkit::secondDerivative(poly1);

                    std::cout
                        << "\nSecond Derivative:\n";

                    result.displayPolynomial();

                    Utilities::saveHistory(
                        "Calculated Second Derivative");

                    Utilities::pauseScreen();

                    break;

                case 3:

                    result =
                        CalculusToolkit::indefiniteIntegral(poly1);

                    std::cout
                        << "\nIndefinite Integral:\n";

                    result.displayPolynomial();

                    std::cout << " + C\n";

                    Utilities::saveHistory(
                        "Calculated Indefinite Integral");

                    Utilities::pauseScreen();

                    break;

                case 4:
                {
                    double lower =
                        Utilities::getValidatedDouble(
                            "Lower Limit : ");

                    double upper =
                        Utilities::getValidatedDouble(
                            "Upper Limit : ");

                    double area =
                        CalculusToolkit::definiteIntegral(
                            poly1,
                            lower,
                            upper);

                    std::cout
                        << "\nDefinite Integral = "
                        << area
                        << std::endl;

                    Utilities::saveHistory(
                        "Calculated Definite Integral");

                    Utilities::pauseScreen();

                    break;
                }

                case 5:
                {
                    double x =
                        Utilities::getValidatedDouble(
                            "Enter x : ");

                    CalculusToolkit::tangentLine(
                        poly1,
                        x);

                    Utilities::saveHistory(
                        "Calculated Tangent Line");

                    Utilities::pauseScreen();

                    break;
                }

                case 6:
                {
                    double lower =
                        Utilities::getValidatedDouble(
                            "Lower Limit : ");

                    double upper =
                        Utilities::getValidatedDouble(
                            "Upper Limit : ");

                    std::cout
                        << "\nArea Under Curve = "
                        << CalculusToolkit::areaUnderCurve(
                               poly1,
                               lower,
                               upper)
                        << std::endl;

                    Utilities::saveHistory(
                        "Calculated Area Under Curve");

                    Utilities::pauseScreen();

                    break;
                }

                }

            } while (choice != 0);

            break;
        }

            //--------------------------------------------------
        // Utilities
        //--------------------------------------------------

        case 3:
        {
            int choice;

            do
            {
                Utilities::clearScreen();

                Utilities::showUtilitiesMenu();

                choice =
                    Utilities::getValidatedInteger("\nChoice : ");

                switch (choice)
                {

                case 1:

                    if (Utilities::savePolynomial(
                            poly1,
                            "data/saved_polynomials.txt"))
                    {
                        std::cout
                            << "\nPolynomial saved successfully.\n";
                    }
                    else
                    {
                        std::cout
                            << "\nFailed to save polynomial.\n";
                    }

                    Utilities::pauseScreen();

                    break;

                case 2:

                    if (Utilities::loadPolynomial(
                            poly1,
                            "data/saved_polynomials.txt"))
                    {
                        std::cout
                            << "\nPolynomial loaded successfully.\n";
                    }
                    else
                    {
                        std::cout
                            << "\nFailed to load polynomial.\n";
                    }

                    Utilities::pauseScreen();

                    break;

                case 3:

                    Utilities::displayHistory();

                    Utilities::pauseScreen();

                    break;

                case 4:

                    Utilities::clearHistory();

                    Utilities::pauseScreen();

                    break;
                }

            } while (choice != 0);

            break;
        }

        //--------------------------------------------------
        // About Project
        //--------------------------------------------------

        case 4:

            Utilities::showAbout();

            Utilities::pauseScreen();

            break;

        //--------------------------------------------------
        // Exit
        //--------------------------------------------------

        case 0:

            std::cout
                << "\nThank you for using Polynomial Calculator & Calculus Toolkit.\n";

            break;

        default:

            std::cout
                << "\nInvalid Choice!\n";

            Utilities::pauseScreen();

        }

    } while (mainChoice != 0);

    return 0;
}
