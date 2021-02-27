#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class GeneratorTest
{
private:
    int MIN_COUNT = 1;
    int MAX_COUNT = 20;

    int _firstNumber_N;
    int _secondNumber_K;

    int Randomizator(int min, int max);

public:
    GeneratorTest();
    GeneratorTest(int new_n, int new_m);
    ~GeneratorTest() = default;

    int getFirstNumber_N();
    int getSecondNumber_K();
};