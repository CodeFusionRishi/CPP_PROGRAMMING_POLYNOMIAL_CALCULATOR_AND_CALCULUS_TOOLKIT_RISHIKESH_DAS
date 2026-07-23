# Polynomial Calculator & Calculus Toolkit

A modular, menu-driven C++ application that performs polynomial arithmetic operations and fundamental calculus computations. The project is designed using Object-Oriented Programming (OOP) principles with a clean separation of interface and implementation, making it suitable for academic learning and software engineering practice.

---

## 📖 Project Description

This application enables users to create, manipulate, evaluate, and analyze polynomial expressions through an interactive console interface. It combines a Polynomial Calculator with a Calculus Toolkit, providing operations such as differentiation, integration, polynomial evaluation, and persistent storage using file handling.

The project demonstrates modern C++ programming concepts, modular software design, and basic numerical computation techniques.

---

## ✨ Key Features

### Polynomial Module
- Create and store polynomial expressions
- Display polynomials in mathematical notation
- Polynomial addition
- Polynomial subtraction
- Polynomial multiplication
- Evaluate polynomial at any value of **x**
- Determine polynomial degree

### Calculus Toolkit
- First derivative
- Second derivative
- Indefinite integration
- Definite integration
- Tangent line calculation
- Area under the curve

### Utility Module
- Save polynomial to file
- Load polynomial from file
- View operation history
- Clear history
- Input validation
- Menu-driven console interface

---

## 🏗️ Project Structure

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
│
├── screenshots/
│
├── README.md
├── Makefile
├── LICENSE
└── .gitignore
```

---

## 🛠️ Technologies Used

- C++17
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- File Handling
- Modular Programming
- Visual Studio Code
- MinGW (g++)

---

## 🧩 OOP Concepts Implemented

- Classes & Objects
- Encapsulation
- Constructors
- Operator Overloading
- Friend Functions
- Static Member Functions
- Modular Design
- Header and Source File Separation

---

## 📐 Algorithms Implemented

| Operation | Algorithm |
|-----------|-----------|
| Polynomial Addition | Coefficient-wise addition |
| Polynomial Subtraction | Coefficient-wise subtraction |
| Polynomial Multiplication | Nested-loop multiplication |
| Polynomial Evaluation | Horner's Method |
| First Derivative | Power Rule |
| Second Derivative | Repeated Differentiation |
| Indefinite Integration | Basic Integration Rule |
| Definite Integration | Fundamental Theorem of Calculus |

---

## 📂 Data Storage

The application stores runtime data in the `data/` directory.

| File | Purpose |
|------|---------|
| `saved_polynomials.txt` | Stores polynomial coefficients |
| `history.txt` | Stores user operation history |

---

## ⚙️ Compilation

Compile the project using:

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Polynomial.cpp src/CalculusToolkit.cpp src/Utilities.cpp -o PolynomialCalculator
```

---

## ▶️ Running the Application

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

- Polynomial arithmetic
- Differential calculus
- Integral calculus
- Object-Oriented Programming
- File handling
- Modular software development
- Console application development
- Exception-safe user input

---

## 🚀 Future Enhancements

- Polynomial Division
- Polynomial Root Finder
- Graph Plotting
- Matrix Calculator
- Complex Polynomial Support
- Graphical User Interface (GUI)
- Export Results to PDF

---

## 👨‍💻 Developer

**Rishikesh Das**

Bachelor of Technology (Computer Science & Engineering)

Lovely Professional University

---

## 📄 License

This project was developed for academic and educational purposes.