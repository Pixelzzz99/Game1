#include "Game1.hpp"

Game1::Game1(AlgorithmStrategy *strategy) : _strategy(strategy)
{
}

Game1::~Game1()
{
    delete this->_strategy;
}

void Game1::setStrategy(AlgorithmStrategy *strategy)
{
    delete this->_strategy;
    this->_strategy = strategy;
}

int Game1::getFirstNumber_N()
{
    return this->_strategy->getFirstNumber_N();
}

int Game1::getSecondNumber_K()
{
    return _strategy->getSecondNumber_K();
}

std::string Game1::DoSolve(bool gameStatus) const
{
    return this->_strategy->solve(gameStatus);
}

int Game1::getIndex()
{
    return _strategy->index;
}