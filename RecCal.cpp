#include <stdexcept> // For std::runtime_error
#include <cctype> // For std::isspace and std::isdigit
#include "RecCal.h"


// Member initializer list to initialize the expression
RecursiveCalculator::RecursiveCalculator(std::string_view expression) : expr(expression) {}

// This function evaluates the expression and checks for any remaining characters after parsing
double RecursiveCalculator::evaluate()
{
    double value{parseExpression()};
    skipWhitespace();
    if (!isAtEnd())
    {
        throw std::runtime_error("Unexpected characters at the end of the expression");
    }
    return value;
}

/*
* This function parses an expression,
* handling addition and subtraction.
*/
double RecursiveCalculator::parseExpression()
{
    double value{parseTerm()};
    skipWhitespace();
    while (isPlusOrMinus())
    {
        char op = peek();
        index++; // Consume operator
        double nextValue = parseTerm();
        if (op == '+')
        {
            value += nextValue;
        }
        else
        {
            value -= nextValue;
        }
        skipWhitespace();
    }
    return value;
}

/*
* This function parses a term from the expression,
* handling multiplication and division.
*/
double RecursiveCalculator::parseTerm()
{
    double value{parseFactor()};
    skipWhitespace();

    while (isMulOrDiv())
    {
        char op = peek();
        index++;
        double nextValue = parseFactor();

        if (op == '*')
        {
            value *= nextValue;
        }
        else
        {
            if (nextValue == 0)
            {
                throw std::runtime_error("Division by zero");
            }
            value /= nextValue;
        }

        skipWhitespace();
    }

    return value;
}

/*
* This function parses a factor from the expression,
* handling unary minus and plus signs, as well as parentheses.
*/
double RecursiveCalculator::parseFactor()
{
    skipWhitespace();

    if (isMinus())
    {
        index++; // consume '-'
        return -parseFactor();
    }

    if (isPlus())
    {
        index++; // consume '+'
        return parseFactor();
    }

    if (isLeftParen())
    {
        index++; // consume '('

        double value = parseExpression();

        skipWhitespace();

        if (!isRightParen())
        {
            throw std::runtime_error("Expected ')'");
        }

        index++; // consume ')'
        return value;
    }

    return parseNumber();
}

/*
* This function checks if the current character is a
* valid digit and parses a number from the expression,
* handling multi-digit numbers as well.
*/
double RecursiveCalculator::parseNumber()
{
    if (!isValidDigit())
    {
        throw std::runtime_error("Expected a number");
    }
    double value{0};
    while (isValidDigit())
    {
        value = value * 10 + (peek() - '0');
        index++;
    }
    return value;
}

bool RecursiveCalculator::isAtEnd() const
{
    return index >= expr.size();
}

bool RecursiveCalculator::isMinus() const
{
    return peek() == '-';
}

bool RecursiveCalculator::isPlus() const
{
    return peek() == '+';
}

bool RecursiveCalculator::isLeftParen() const
{
    return peek() == '(';
}

bool RecursiveCalculator::isRightParen() const
{
    return peek() == ')';
}


bool RecursiveCalculator::isMulOrDiv() const
{
    return peek() == '*' || peek() == '/';
}


bool RecursiveCalculator::isPlusOrMinus() const
{
    return peek() == '+' || peek() == '-';
}

bool RecursiveCalculator::isValidDigit() const
{
    return !isAtEnd() && std::isdigit(static_cast<unsigned char>(peek()));
}

char RecursiveCalculator::peek() const
{
    if (isAtEnd())
    {
        return '\0';
    }
    return expr[index];
}

void RecursiveCalculator::skipWhitespace()
{
    while (!isAtEnd() && std::isspace(static_cast<unsigned char>(peek())))
    {
        index++;
    }
}
