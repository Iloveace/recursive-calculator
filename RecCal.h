#ifndef RECURSIVE_CALCULATOR_H
#define RECURSIVE_CALCULATOR_H
#include <string_view> // For std::string_view
#include <cstddef> // For std::size_t


/*
* Evaluates arithmetic expressions with +, -, *, /, parentheses,
* and unary + / - using recursive descent parsing.
*/

class RecursiveCalculator
{

public:
    explicit RecursiveCalculator(std::string_view expression);
    double evaluate();

private:
    std::string_view expr;

    std::size_t index{0};

    bool isAtEnd() const;
    char peek() const;
    void skipWhitespace();
    bool isMinus() const;
    bool isPlus() const;
    bool isLeftParen() const;
    bool isRightParen() const;
    bool isPlusOrMinus() const;
    double parseExpression();
    bool isMulOrDiv() const;
    double parseTerm();
    double parseFactor();
    bool isValidDigit() const;
    double parseNumber();

};
#endif // RECURSIVE_CALCULATOR_H