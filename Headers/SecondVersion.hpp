#pragma once
#include <algorithm>
#include "AlgorithmStrategy.hpp"

class SecondVersion : public AlgorithmStrategy
{
private:
    void prec(int n, int k);
    std::string preWinInfo(int n, int k);
    void winInfo(bool manMove);
    void gamePlay(bool gameStatus, int n, int k);
public:
    SecondVersion(GeneratorTest *);
    ~SecondVersion() = default;
    std::string solve(bool gameStatus) override;
};
