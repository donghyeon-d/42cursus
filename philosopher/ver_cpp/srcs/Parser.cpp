#include "../include/Parser.hpp"
#include "../include/DiningRule.hpp"

bool Parser::IsValidParm()
{
    if (IsInvalidCount(_argc))
    {
        return false;
    }

    if (IsWrongType(_argc, _argv))
    {
        return false;
    }

    InitDiningRule(_argc, _argv);
}

void Parser::SetDiningRuleFromParm()
{

}

bool IsInvalidCount(int argc)
{
    if (argc == 4 || argc == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsWrongType(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            if (std::isdigit(argv[i][j]) == false)
            {
                return true;
            }
            j++;
        }
    }

    return false;
}

void InitDiningRule(int argc, char **argv)
{
    int philoCount = std::atoi(argv[0]);
    int timeToDie = std::atoi(argv[1]);
    int timeToEat = std::atoi(argv[2]);
    int timeToSleep = std::atoi(argv[3]);
    int mustEat = -1;
    if (argc == 5)
    {
        int mustEat = std::atoi(argv[4]);
    }

    DiningRule diningRule(philoCount, timeToDie, timeToEat, timeToSleep, mustEat);
}