#include <iostream>
#include <vector>
#include "GeneratorTest.hpp"
#include "Game1.hpp"
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include <fstream>

GeneratorTest *test1 = new GeneratorTest(5, 2);

int testRegularVersion()
{
    Game1 *firstVersion = new Game1(new FirstVersion(test1));
    std::cout << "First Number: " << test1->getFirstNumber_N() << std::endl;
    std::cout << "Second Number: " << test1->getSecondNumber_K() << std::endl;

    unsigned int time_start = clock();
    std::string result = firstVersion->DoSolve(false);
    unsigned int time_end = clock();

    std::cout << "Answer :" << result << std::endl;
    std::cout << "Time: " << (double)(time_end - time_start) / CLOCKS_PER_SEC << std::endl;
    std::cout << "Test finished" << std::endl;
    std::cout << std::endl;
    delete firstVersion;
    return 1;
}

int testOptimizedVersion()
{
    Game1 *secondVersion = new Game1(new SecondVersion(test1));
    std::cout << "First Number: " << test1->getFirstNumber_N() << std::endl;
    std::cout << "Second Number: " << test1->getSecondNumber_K() << std::endl;

    unsigned int time_start = clock();
    std::string result = secondVersion->DoSolve(false);
    unsigned int time_end = clock();

    std::cout << "Answer :" << result << std::endl;
    std::cout << "Time: " << (double)(time_end - time_start) / CLOCKS_PER_SEC << std::endl;
    std::cout << "Test finished" << std::endl;
    std::cout << std::endl;
    delete secondVersion;
    return 1;
}

int testRegularOptimizedVersion()
{
    std::cout << "Excel Table Test" << std::endl;
    std::ofstream ExcelFile;
    ExcelFile.open("D:\\projects\\Game1\\Tables\\Tables.csv");
    if (ExcelFile.is_open())
    {
        ExcelFile << "N ;"
                  << "K ;"
                  << "Answer First ;"
                  << "Time First ;"
                  << ";"
                  << "Answer Second ;"
                  << "Time Second ;"
                  << std::endl;

        for (int i = 5; i <= 40; i++)
        {
            for (int j = 2; j <= i; j++)
            {

                GeneratorTest *test2 = new GeneratorTest(i, j);
                Game1 *firstVersion = new Game1(new FirstVersion(test2));
                Game1 *secondVersion = new Game1(new SecondVersion(test2));

                std::cout << "First Number: " << test2->getFirstNumber_N() << std::endl;
                ExcelFile << test2->getFirstNumber_N() << ";";

                std::cout << "Second Number: " << test2->getSecondNumber_K() << std::endl;
                ExcelFile << test2->getSecondNumber_K() << ";";

                unsigned int time_start_one = clock();
                std::string result1 = firstVersion->DoSolve(false);
                unsigned int time_end_one = clock();

                unsigned int time_start_two = clock();
                std::string result2 = secondVersion->DoSolve(false);
                unsigned int time_end_two = clock();

                std::cout << "Answer first version: " << result1 << std::endl;
                std::cout << "Answer second version: " << result2 << std::endl;
                std::cout << "Time one: " << (double)(time_end_one - time_start_one) / CLOCKS_PER_SEC << std::endl;
                std::cout << "Time two: " << (double)(time_end_two - time_start_two) / CLOCKS_PER_SEC << std::endl;
                ExcelFile << result1 << ";" << (double)(time_end_one - time_start_one) / CLOCKS_PER_SEC << ";;" << result2 << ";" << (double)(time_end_two - time_start_two) / CLOCKS_PER_SEC << std::endl;
                std::cout << std::endl;

                delete firstVersion;
                delete secondVersion;
                delete test2;
            }
        }
    }
    return 1;
}

int main()
{
    testRegularOptimizedVersion();
    //testRegularVersion();
    //testOptimizedVersion();
    //delete test1;
    system("pause>nul");
    return 0;
}
