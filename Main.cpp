#include <iostream>
#include "RecCal.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./toy-app \"expression\"\n";
        return 1;
    }

    try
    {
        RecursiveCalculator calculator(argv[1]);
        double result{calculator.evaluate()};
        std::cout << result << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error parsing expression: " << e.what() << '\n';
        return 1;
    }

    return 0;
}