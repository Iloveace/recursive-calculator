#ifndef RECURSIVE_CALCULATOR_H
#define RECURSIVE_CALCULATOR_H
#include <string_view> // For std::string_view
#include <cstddef> // For std::size_t


/*
* Evaluates arithmetic expressions with +, -, *, /, parentheses,
* and unary + / - using recursive descent parsing.
*/

class RecursiveCalculator {
public:
    // ===== Public Interface =====
    Explicit RecursiveCalculator(std::string_view input);
    double evaluate();

private:
    // ===== Core Parsing (high-level grammar) =====
    double parseExpression(); // + and -
    double parseTerm();       // * and /
    double parseFactor();     // unary, parentheses
    double parseNumber();     // numbers

    // ===== Helpers =====
    char peek() const;
    char get();
    void skipWhitespace();
    bool isAtEnd() const;
    bool isMinus() const;
    bool isPlus() const;
    bool isLeftParen() const;
    bool isRightParen() const;
    bool isPlusOrMinus() const;
    bool isMulOrDiv() const;
    bool isValidDigit() const;

    // ===== State =====
    std::string_view input;
    size_t index;
};
#endif // RECURSIVE_CALCULATOR_H
