#pragma once
#include <vector>
#include <algorithm>
#include "GeneratorTest.hpp"

class AlgorithmStrategy
{
private:
    int _firstNumber_N;
    int _secondNumber_K;
    void fillLose();

protected:
    std::vector<std::vector<bool>> lose;

public:
    int index = 0;
    int getFirstNumber_N();
    void setFirstNumber_N(int);

    int getSecondNumber_K();
    void setSecondNumber_K(int);

    virtual ~AlgorithmStrategy() = default;
    virtual std::string solve(bool gameStatus) = 0;
};
