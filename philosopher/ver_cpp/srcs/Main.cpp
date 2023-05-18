#include "../include/Philo.hpp"
#include "../include/Fork.hpp"
#include "../include/Monitor.hpp"
#include "../include/Parser.hpp"
#include <vector>

int main(int argc, char **argv)
{
    // 파싱
    int philoCount = Parsing(argc, argv);

    // 포크 만들기
    std::vector<Fork*> forks = InitForkList(philoCount);

    // 필로 만들기
    std::vector<Philo*> philos = InitPhiloList(philoCount, forks);

    // 모니터 만들기
    Monitor monitor(philos);

    // 필로 쓰레드 시작
    StartDining(philos);

    // 모니터 시작
    monitor.StartMonitoring();

    GarbageCollect(philos, forks);

    return 0;
}


int Parsing(int argc, char **argv)
{
    Parser parser(argc, argv);
    if (parser.IsValidParm() != true)
    {
        std::cerr << "Error : Invalid Parm" << std::endl;
        exit(0);
    }

    parser.SetDiningRuleFromParm();

    return std::atoi(argv[0]);
}

std::vector<Fork*> InitForkList(int count)
{
    std::vector<Fork*> forkList;

    for (int i = 0; i < count; i++)
    {
        Fork *fork = new Fork();
        forkList.push_back(fork);
    }

    return forkList;
}

std::vector<Philo*> InitPhiloList(int count, std::vector<Fork*> &forks)
{
    std::vector<Philo*> philoList;

    for (int philoNumber = 0; philoNumber < count; philoNumber++)
    {
        Philo* philo = new Philo(philoNumber, forks);
        philoList.push_back(philo);
    }

    return philoList;
}

void StartDining(std::vector<Philo*> &philos)
{
    for (int philoNum = 0; philoNum < philos.size(); philoNum++)
    {
        philos[philoNum]->StartDining();
    }
}



void GarbageCollect(std::vector<Philo*> &philos, std::vector<Fork*> &forks)
{
    for (int philoNum = 0; philoNum < philos.size(); philoNum++)
    {
        philos[philoNum]->ThreadJoin();
        free(philos[philoNum]);
        free(forks[philoNum]);
    }

    Printer::Unlock();
}


