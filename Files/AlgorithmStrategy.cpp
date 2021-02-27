#include "AlgorithmStrategy.hpp"

int AlgorithmStrategy::getFirstNumber_N()
{
    return (this->_firstNumber_N);
}

void AlgorithmStrategy::setFirstNumber_N(int newFirstNumber_N)
{
    this->_firstNumber_N = newFirstNumber_N;
}

int AlgorithmStrategy::getSecondNumber_K()
{
    return (this->_secondNumber_K);
}

void AlgorithmStrategy::setSecondNumber_K(int newSecondNumber_K)
{
    this->_secondNumber_K = newSecondNumber_K;
    fillLose();
}

void AlgorithmStrategy::fillLose()
{
    lose.resize(_firstNumber_N + 1);
    for (int i = 0; i < _firstNumber_N + 1; i++)
    {
        lose[i].resize(_secondNumber_K+2);
    }
}
