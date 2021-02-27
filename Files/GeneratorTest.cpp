#include "GeneratorTest.hpp"

GeneratorTest::GeneratorTest()
{
    _firstNumber_N = Randomizator(MIN_COUNT, MAX_COUNT);
    _secondNumber_K = Randomizator(MIN_COUNT, MAX_COUNT);
}

GeneratorTest::GeneratorTest(int firstNumber, int secondNumber)
{
    _firstNumber_N = firstNumber;
    _secondNumber_K = secondNumber;
}

int GeneratorTest::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int GeneratorTest::getFirstNumber_N()
{
    return _firstNumber_N;
}

int GeneratorTest::getSecondNumber_K()
{
    return _secondNumber_K;
}