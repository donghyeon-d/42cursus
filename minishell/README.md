[노션 링크](https://helpful-eggplant-ec3.notion.site/minishell-fa96dbd636744fe9b2f112f59f1730ce)

# Philosopher
# 과제 개요
## 1. 무엇을 하는 과제인가?
- bash shell 만들기 [(bash manual)](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)
- 몇몇 명령어는 built-in 함수로 만들고, 나머지는 execve로 실행
- 환경변수도 세팅해줄 수 있어야 함

<br>

## 2. 새롭게 배운 개념
- 부모-자식 process
- pipe 통신
- tree 구조 재귀하향파싱
- 설계의 중요성

<br>

## 3. 팀프로젝트에서 기여한 파트
- 재귀하향파싱
- cmd 구조체 설계 및 파싱한 정보 넣기
- 명령어 종류 및 상황별 분기처리 및 pipe line 세팅 (협업)
- built-in 함수 만들기

<br>


## 4. 결과물
- 실행 방법  
```
$ make all
$ ./minishell
```
- 현재 터미널의 자식프로세스로 minshell이 실행 됨
- bash shell 과 비슷하게 동작함

<br><br>

# 어려웠던 점 및 해결
## 설계
- 처음 시작할 때 무엇부터 어떻게 해야할지 몰랐고, 파싱할 때 어떻게 해야할지 막막했음
- bash 메뉴얼을 보면서 bash가 어떻게 동작하는지 살펴봤고, 재귀하향파서에 대한 레퍼런스들을 참고함

## termios 함수
- 터미널에서 키 입력받을 수 있게 해주는 함수들이라고 하는데, 도저히 이해가 되지 않아서 패스했음
- readline 함수로도 충분히 구현할 수 있었음
 
## pipe
- 부모-자식 프로세스 간 pipe를 설정해주는 것이 어려웠음
- 적절히 fd를 연결해주고 끊어주는 과정을 연습해보면서 익힘

## execute 실행
- cmd구조체에 담겨있는 정보를 보면서 실행해주는 부분에서 상황별로 분기해주는 것이 꽤 헷갈렸음
- bash와 최대한 비슷하게 하기 위해서 exit code 도 하나하나 다 비교해주고 signal 처리도 자세히 살펴보며 진행했음

