#pragma once
#include <vector>
#include "AlgorithmStrategy.hpp"

class Game1
{
private:
    AlgorithmStrategy *_strategy;
    
public:
    Game1(AlgorithmStrategy *strategy = nullptr);
    ~Game1();
    
    int getFirstNumber_N();
    int getSecondNumber_K();

    void setStrategy(AlgorithmStrategy *);
    int getIndex();
    std::string DoSolve(bool) const;
};

