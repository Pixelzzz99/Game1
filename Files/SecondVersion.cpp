#include "SecondVersion.hpp"

SecondVersion::SecondVersion(GeneratorTest *test)
{
    setFirstNumber_N(test->getFirstNumber_N());
    setSecondNumber_K(test->getSecondNumber_K());
}

std::string SecondVersion::solve(bool gameStatus)
{
    int n = getFirstNumber_N();
    int k = getSecondNumber_K();
    prec(n, k);

    std::string result = preWinInfo(n, k);
    gamePlay(gameStatus, n, k);
    return result;
}

void SecondVersion::prec(int n, int k)
{
    for (int i = 0; i <= k + 1; i++)
        lose[0][i] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int mx = 1; mx <= k; mx++)
        {
            bool bol = true;
            for (int take = 1; take <= std::min(mx, i); take++)
            {
                if (lose[i - take][take + 1])
                    bol = false;
            }
            lose[i][mx] = bol;
        }
    }
}

void SecondVersion::winInfo(bool manMove)
{
    if (manMove)
        std::cout << "Win Computer" << std::endl;
    else
        std::cout << "Win Man" << std::endl;
}

std::string SecondVersion::preWinInfo(int n, int k)
{
    std::string result;
    if (!lose[n][k])
        return result = "If a person plays optimally, he will win";
    else
        return result = "The computer win";
}

void SecondVersion::gamePlay(bool gameStatus, int n, int k)
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
            int take;
            std::cin >> take;
            k = take + 1;
            n -= take;
            manMove = false;
            compMove = true;
        }
        else
        {
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
