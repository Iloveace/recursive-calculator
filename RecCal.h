#pragma once

#include <string_view> // For std::string_view
#include <cstddef> // For std::size_t


/*
* Evaluates arithmetic expressions with +, -, *, /, parentheses,
* and unary + / - using recursive descent parsing.
*/

class RecursiveCalculator
{
public:
    // ===== Public Interface =====
    explicit RecursiveCalculator(std::string_view expression);
    double evaluate();

private:
    // ===== Core Parsing (high-level grammar) =====
    double parseExpression(); // + and -
    double parseTerm();       // * and /
    double parseFactor();     // unary, parentheses
    double parseNumber();     // numbers

    // ===== Helpers =====
    bool isAtEnd() const;
    bool isLeftParen() const;
    bool isRightParen() const;
    bool isMinus() const;
    bool isPlus() const;
    bool isMulOrDiv() const;
    bool isPlusOrMinus() const;
    bool isValidDigit() const;
    char peek() const;
    void skipWhitespace();

    // ===== State =====
    std::string_view expr;
    std::size_t index{0};
};

