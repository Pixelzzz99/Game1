#pragma once
#include "AlgorithmStrategy.hpp"

class FirstVersion : public AlgorithmStrategy
{
private:
    bool prec(int n, int k);
    std::string preWinInfo(int n, int k);
    void winInfo(bool manMove);
    void gamePlay(bool gameStatus, int n, int k);
public:
    
    FirstVersion(GeneratorTest *);
    ~FirstVersion() = default;
    std::string solve(bool gameStatus) override;
};
