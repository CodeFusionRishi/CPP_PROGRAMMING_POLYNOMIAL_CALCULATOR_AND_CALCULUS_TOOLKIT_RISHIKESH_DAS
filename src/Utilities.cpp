#include "../include/Utilities.hpp"

#include <fstream>
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

//--------------------------------------------------
// Main Menu
//--------------------------------------------------

void Utilities::showMainMenu()
{
    std::cout << "\n===============================================\n";
    std::cout << "   POLYNOMIAL CALCULATOR & CALCULUS TOOLKIT\n";
    std::cout << "===============================================\n";
    std::cout << "1. Polynomial Operations\n";
    std::cout << "2. Calculus Toolkit\n";
    std::cout << "3. Utilities\n";
    std::cout << "4. About Project\n";
    std::cout << "0. Exit\n";
    std::cout << "===============================================\n";
}

//--------------------------------------------------
// Polynomial Menu
//--------------------------------------------------

void Utilities::showPolynomialMenu()
{
    std::cout << "\n========== Polynomial Operations ==========\n";
    std::cout << "1. Create Polynomial\n";
    std::cout << "2. Display Polynomial\n";
    std::cout << "3. Add Polynomials\n";
    std::cout << "4. Subtract Polynomials\n";
    std::cout << "5. Multiply Polynomials\n";
    std::cout << "6. Evaluate Polynomial\n";
    std::cout << "7. Degree of Polynomial\n";
    std::cout << "0. Back\n";
}

//--------------------------------------------------
// Calculus Menu
//--------------------------------------------------

void Utilities::showCalculusMenu()
{
    std::cout << "\n========== Calculus Toolkit ==========\n";
    std::cout << "1. First Derivative\n";
    std::cout << "2. Second Derivative\n";
    std::cout << "3. Indefinite Integration\n";
    std::cout << "4. Definite Integration\n";
    std::cout << "5. Tangent Line\n";
    std::cout << "6. Area Under Curve\n";
    std::cout << "0. Back\n";
}

//--------------------------------------------------
// Utilities Menu
//--------------------------------------------------

void Utilities::showUtilitiesMenu()
{
    std::cout << "\n========== Utilities ==========\n";
    std::cout << "1. Save Polynomial\n";
    std::cout << "2. Load Polynomial\n";
    std::cout << "3. View History\n";
    std::cout << "4. Clear History\n";
    std::cout << "0. Back\n";
}

//--------------------------------------------------
// About
//--------------------------------------------------

void Utilities::showAbout()
{
    std::cout << "\n===============================================\n";
    std::cout << "Polynomial Calculator & Calculus Toolkit\n";
    std::cout << "Version : 1.0\n";
    std::cout << "Language : C++17\n";
    std::cout << "===============================================\n";
}

//--------------------------------------------------
// Clear Screen
//--------------------------------------------------

void Utilities::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//--------------------------------------------------
// Pause
//--------------------------------------------------

void Utilities::pauseScreen()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

//--------------------------------------------------
// Integer Validation
//--------------------------------------------------

int Utilities::getValidatedInteger(const std::string& message)
{
    int value;

    while (true)
    {
        std::cout << message;

        if (std::cin >> value)
            return value;

        std::cout << "Invalid input. Try again.\n";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//--------------------------------------------------
// Double Validation
//--------------------------------------------------

double Utilities::getValidatedDouble(const std::string& message)
{
    double value;

    while (true)
    {
        std::cout << message;

        if (std::cin >> value)
            return value;

        std::cout << "Invalid input. Try again.\n";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
//--------------------------------------------------
// Save Polynomial
//--------------------------------------------------

bool Utilities::savePolynomial(const Polynomial& poly,
                               const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
        return false;

    std::vector<double> coeffs = poly.getCoefficients();

    file << coeffs.size() << std::endl;

    for (double coefficient : coeffs)
    {
        file << coefficient << " ";
    }

    file.close();

    saveHistory("Polynomial saved to " + filename);

    return true;
}

//--------------------------------------------------
// Load Polynomial
//--------------------------------------------------

bool Utilities::loadPolynomial(Polynomial& poly,
                               const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
        return false;

    size_t size;
    file >> size;

    std::vector<double> coeffs(size);

    for (size_t i = 0; i < size; i++)
    {
        file >> coeffs[i];
    }

    poly = Polynomial(coeffs);

    file.close();

    saveHistory("Polynomial loaded from " + filename);

    return true;
}

//--------------------------------------------------
// Save History
//--------------------------------------------------

void Utilities::saveHistory(const std::string& operation)
{
    std::ofstream historyFile("data/history.txt", std::ios::app);

    if (historyFile)
    {
        historyFile << operation << std::endl;
    }
}

//--------------------------------------------------
// Display History
//--------------------------------------------------

void Utilities::displayHistory()
{
    std::ifstream historyFile("data/history.txt");

    if (!historyFile)
    {
        std::cout << "\nNo history available.\n";
        return;
    }

    std::string line;

    std::cout << "\n========== History ==========\n";

    while (getline(historyFile, line))
    {
        std::cout << line << std::endl;
    }

    historyFile.close();
}

//--------------------------------------------------
// Clear History
//--------------------------------------------------

void Utilities::clearHistory()
{
    std::ofstream historyFile("data/history.txt",
                              std::ios::trunc);

    historyFile.close();

    std::cout << "\nHistory cleared successfully.\n";
}
