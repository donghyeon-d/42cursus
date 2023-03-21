[노션 링크](https://helpful-eggplant-ec3.notion.site/Philosopher-947e57952e334043994125430f18b611)

# Philosopher
# 과제 개요
## 1. 무엇을 하는 과제인가?
- [식사하는 철학자 문제](https://ko.wikipedia.org/wiki/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94_%EC%B2%A0%ED%95%99%EC%9E%90%EB%93%A4_%EB%AC%B8%EC%A0%9C)
- 철학자에게 주어진 fork가 공유자원이기에, 공유자원 접근에 대해 data race가 발생하지 않도록 해야 함
- 철학자를 멀티 쓰레드로 구현하고, 공유자원을 mutex 제어하기
- 철학자를 멀티 프로세스로 구현하고, 공유자원을 semaphore로 제어하기
- 어떤 종류의 data race도 발생하지 않아야 함

<br>

## 2. 새롭게 배운 개념
- data races (경쟁 상태)
- multi tasking programing (thread, process)
- mutex
- semaphore

<br>

## 3. 보완할 점
- 과제 통과는 했는데, 전체적인 구현이 잘못됐음... 처음부터 제대로 다시 해보기
    - 모든 data race 에 대해 제어해주기
    - 철학자가 죽었는지는 자기 자신이 판단할 수 없음. 모니터 쓰레드가 철학자의 죽음 유무 확인하기
    - thread leak 체크하기
- data race 디버거 활용하면 data race 발생 영역 확인 가능  
    ```
    cc -g -fsanitize=thread *.c
    ```
- 한 쓰레드는 공유영역을 읽기만하고, 한 쓰레드는 공유영역에 읽고/쓰기를 하는 것도 data race이며 제어해줘야함. 잘못된 값을 읽어도 다음 루틴때 다시 읽어서 판단해도 된다고 생각해서 그냥 놔뒀었음.

- 철학자는 스스로 죽은지 판단할 수 없으며, 모니터 쓰레드가 철학자의 죽음을 판단해야 함
- C++ 를 사용하여 객체지향으로 구현해보기

<br>


## 4. 결과물
- 실행 방법  
```
$ make all
$ ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```


<br><br>

# 봉착된 문제 및 해결
## 아무도 안죽어야 되는데 어느 순간 죽음..
- 일어나자마자 포크를 집으면, 먼저 기다리고 있던 녀석보다 먼저 집을 수 있음 -> 깨어난 직후 usleep 줘서 살짝 기다렸다가 먹게하기

## 철학자가 홀수일 때
- 모든 철학자가 깨어나자마자 포크를 들려고 달려들음
- 경쟁이 너무 치열해서, 먹어야할 순서대로 먹지 못하는 철학자가 생김
- 일어났을 때 바로 포크를 집으러가는게 아니라 잠깐 usleep 해주면 해결
 
## sem_wait, mutex_lock 중에 죽으면 시간 확인하는 방법
- 철학자 자신이 스스로 죽었는지를 판단할 수 없음
- 모니터링 쓰레드를 따로 만들어서 그 쓰레드가 철학자들의 상태를 살펴야 함
