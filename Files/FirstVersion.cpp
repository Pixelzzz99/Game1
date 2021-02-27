#include "FirstVersion.hpp"

FirstVersion::FirstVersion(GeneratorTest *test)
{
    setFirstNumber_N(test->getFirstNumber_N());
    setSecondNumber_K(test->getSecondNumber_K());
}

std::string FirstVersion::solve(bool gameStatus)
{
    int n = getFirstNumber_N();
    int k = getSecondNumber_K();
    prec(n, k);

    std::string result = preWinInfo(n, k);
    gamePlay(gameStatus, n, k);
    return result;
}

bool FirstVersion::prec(int n, int k)
{
    int n_local = n;
    int k_local = k;
    if (n_local <= 0)
    {
        lose[n_local][k_local] = true;
        return true;
    }

    if (n_local <= k_local)
    {
        return false;
    }
    bool bol = true;
    for (int take = 1; take <= k_local; take++)
    {
        if (prec(n_local - take, take + 1))
            bol = false;
    }

    return lose[n_local][k_local] = bol;
}

void FirstVersion::winInfo(bool manMove)
{
    if (manMove)
        std::cout << "Win Computer" << std::endl;
    else
        std::cout << "Win Man" << std::endl;
}

std::string FirstVersion::preWinInfo(int n, int k)
{
    std::string result;
    if (!lose[n][k])
        return result = "If a person plays optimally, he will win";
    else
        return result = "The computer win";
}

void FirstVersion::gamePlay(bool gameStatus, int n, int k)
{
    bool manMove = true;
    bool compMove = false;
    while (gameStatus)
    {
        std::cout << "TABLO n = " << n << " k = " << k << std::endl;
        if (n <= 0)
        {
            winInfo(manMove);
            break;
        }
        if (manMove)
        {
            std::cout << "Now your move DO IT: " << std::endl;
            int take;
            std::cin >> take;
            k = take + 1;
            n -= take;
            manMove = false;
            compMove = true;
        }
        else
        {
            std::cout << "Now computer move..." << std::endl;
            int id = 1;
            for (int take = std::min(k, n); take >= 1; take--)
            {
                if (lose[n - take][take + 1])
                    id = take;
            }
            std::cout << "I take " << id << std::endl;
            n -= id;
            compMove = false, manMove = true;
        }
    }
}