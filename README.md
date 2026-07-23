# Polynomial Calculator & Calculus Toolkit

A modular, menu-driven C++ application designed to perform polynomial arithmetic and fundamental calculus operations. The project is built using Object-Oriented Programming (OOP) principles and demonstrates modular software design, file handling, and the use of the C++ Standard Template Library (STL).

---

## 📖 Overview

The **Polynomial Calculator & Calculus Toolkit** is a console-based application that allows users to create, manipulate, evaluate, and analyze polynomial expressions. Along with arithmetic operations, the application provides essential calculus functionalities such as differentiation and integration.

The project emphasizes clean code organization, modular programming, and reusable components by separating declarations, implementations, and utility functions into different modules.

---

## ✨ Features

### Polynomial Operations

- Create Polynomial
- Display Polynomial
- Add Two Polynomials
- Subtract Two Polynomials
- Multiply Two Polynomials
- Evaluate Polynomial at any value of **x**
- Find Polynomial Degree

### Calculus Toolkit

- First Derivative
- Second Derivative
- Indefinite Integration
- Definite Integration
- Tangent Line Calculation
- Area Under the Curve

### Utilities

- Save Polynomial
- Load Polynomial
- View Operation History
- Clear History
- Input Validation
- Interactive Menu-driven Interface

---

## 📂 Project Structure

```text
PolynomialCalculatorAndCalculusToolkit/
│
├── include/
│   ├── Polynomial.hpp
│   ├── CalculusToolkit.hpp
│   └── Utilities.hpp
│
├── src/
│   ├── Polynomial.cpp
│   ├── CalculusToolkit.cpp
│   ├── Utilities.cpp
│   └── main.cpp
│
├── data/
│   ├── saved_polynomials.txt
│   └── history.txt
│
├── docs/
├── screenshots/
│
├── README.md
├── Makefile
├── LICENSE
└── .gitignore
```

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++17 | Programming Language |
| STL | Dynamic Data Structures |
| OOP | Software Design |
| File Handling | Data Storage |
| VS Code | Development Environment |
| MinGW (g++) | Compilation |

---

## 📚 OOP Concepts Demonstrated

- Classes & Objects
- Encapsulation
- Constructors
- Operator Overloading
- Friend Functions
- Static Member Functions
- Modular Programming
- Header and Source File Separation

---

## ⚙️ Algorithms Implemented

| Operation | Method Used |
|-----------|-------------|
| Polynomial Addition | Coefficient-wise Addition |
| Polynomial Subtraction | Coefficient-wise Subtraction |
| Polynomial Multiplication | Nested Loop Multiplication |
| Polynomial Evaluation | Horner's Method |
| First Derivative | Power Rule |
| Second Derivative | Repeated Differentiation |
| Indefinite Integration | Basic Integration Rule |
| Definite Integration | Fundamental Theorem of Calculus |

---

## 💾 Data Storage

The application stores runtime information inside the **data** directory.

| File | Description |
|------|-------------|
| `saved_polynomials.txt` | Stores polynomial coefficients |
| `history.txt` | Stores operation history |

---

## 🚀 Compilation

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Polynomial.cpp src/CalculusToolkit.cpp src/Utilities.cpp -o PolynomialCalculator
```

---

## ▶️ Running the Project

### Windows

```bash
PolynomialCalculator.exe
```

### Linux

```bash
./PolynomialCalculator
```

---

## 🎯 Learning Outcomes

This project demonstrates practical implementation of:

- Polynomial Arithmetic
- Differential Calculus
- Integral Calculus
- Object-Oriented Programming
- File Handling
- Modular Software Design
- Console Application Development
- Input Validation

---

## 🔮 Future Enhancements

- Polynomial Division
- Root Finding Algorithms
- Polynomial Graph Plotting
- Matrix Calculator Module
- GUI Version
- Export Results to PDF
- Complex Polynomial Support

---

## 👨‍💻 Author

**Rishikesh Das**

Bachelor of Technology (Computer Science & Engineering)

Lovely Professional University

---

## 📜 License

This project has been developed for academic and educational purposes.
