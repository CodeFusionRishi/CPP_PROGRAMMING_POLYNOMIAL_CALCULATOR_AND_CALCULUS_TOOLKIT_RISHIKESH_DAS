#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include "Polynomial.hpp"

class Utilities
{
public:

    // Menus
    static void showMainMenu();
    static void showPolynomialMenu();
    static void showCalculusMenu();
    static void showUtilitiesMenu();
    static void showAbout();

    // Screen Utilities
    static void clearScreen();
    static void pauseScreen();

    // Input Validation
    static int getValidatedInteger(const std::string& message);
    static double getValidatedDouble(const std::string& message);

    // File Handling
    static bool savePolynomial(const Polynomial& poly,
                               const std::string& filename);

    static bool loadPolynomial(Polynomial& poly,
                               const std::string& filename);

    // History
    static void saveHistory(const std::string& operation);
    static void displayHistory();
    static void clearHistory();
};

#endif