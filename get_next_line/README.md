노션에 정리한내용
노션 링크 : [링크](https://www.notion.so/GNL-get_next_line-26200c3617194be4928d43b1f7df29f9)

# GNL(get_next_line)

[read 함수 reference link](https://linux.die.net/man/3/read) 

- 노션에 정리한거 참고 [https://www.notion.so/Get-Next-Line-c7a311e63bd2483ab5bf404791e917c6](https://www.notion.so/Get-Next-Line-c7a311e63bd2483ab5bf404791e917c6)
- [파일 디스크립터 설명 참고](https://minsoftk.tistory.com/40) [https://minsoftk.tistory.com/40](https://minsoftk.tistory.com/40)

# read 함수 [(참고)](https://linux.die.net/man/3/read)

- 프로토타입 ssize_t read(int fildescripter**, void ***buf**, size_t** nbyte**);**
- 헤더
    - **#include <[unistd.h](https://linux.die.net/include/unistd.h)>**
- 동작
    - nbyte = 0 일 때, 0 리턴하고 아무 동작 안함
- 리턴
    - 읽기 성공하면 (양수)읽은 바이트 수 리턴
    - 실패, 에러 발생하면 -1 리턴 (fd가 잘못 들어왔을 때 등)
- buf에 저장되는 글자에는 ‘\0’ 포함되어있지 않음. 그냥 글자 그대로만 가져와줌

# open, close 함수

- 프로토타입 int open(const char **path***, int** *oflag***, ... );**
- 헤더
    - **#include <[sys/stat.h](https://linux.die.net/include/sys/stat.h)>**
    - #include <[fcntl.h](https://linux.die.net/include/fcntl.h)>
- oflag
    - O_RDONLY
        - Open for reading only.
    - O_WRONLY
        - Open for writing only.
    - O_RDWR
        - Open for reading and writing. The result is undefined if this flag is applied to a FIFO.
- Return
    - 가장 작은 수의 fd를 반환함(3부터)
    - 실패하면 -1 반환
- file descripter
    - 0 : stdin
    - 1 : stdout
    - 2 : error

# 구현 방식

## 구조체연결리스트 사용

- 구조체 멤버 (char *content, t_list *next, t_list *next_fd, ssize_t fd)
    - content : 읽은 것을 저장해 놓을 부분. 개행까지는 head→next→content부터 next로 넣기
    - next : 다음 읽어온 content
    - next_fd : fd를 확인하고, fd별로 헤드를 따로 만들어줌
    - fd : fd를 저장해놓음. next→fd 는 -1 로 초기화. 헤드에만 fd 값이 들어가있음
1. static 변수는 한개만 사용 가능 - 가장 처음의 헤드 노드 주소를 static으로 고정하기
2. fd를 확인하면서별로 헤드노드를 각각 지정해줌
3. read하면 개행까지 content에 저장하고, 개행 뒤부터는 fd_head의 content에 넣어줌

## \n 과 EOF  찾기

1. temp = read(fd, str, BUFFER_SIZE);
2. while (str[i] ≠ ‘\n’ && str[i] ≠ ‘\0’) i++;
3. if (str[i] == ‘\n’) 이면 개행이 있는거. 개행이 있으면 그 자리(i)까지 next→content에 넣고
i 뒤부터 head→content에 넣음
4. if (str[i] == ‘\n’) 아니면 ‘\0’일테니까 next→content에 넣고 read 또 해.
5. temp > 0 여부를 확인해서, 틀리면 파일이 끝난거

## free 해주기!

1. content에 문자 넣을 때 duplicate로 들어가기 때문에, 임시로 쓰는 녀석들 free 필요
2. content들 하나로 묶어준 다음에는 next들 돌면서 conent랑 next 들 free 필요
3. fd_head→content 가 비어있으면 필요 없으니까 free
4. head→next_fd 가 NULL이면 굳이 static 변수도 필요 없으니까 head free

# 봉착된 문제

## \n, \0, NULL 찾기

- 처음에 구현했던 것
    - int check_n(char *s) 함수를 만들어서 str에서 \n의 자리를 찾고, 없으면 -1 해줬음
    - 파일이 끝나기 전 마지막으로 읽는 지점을 찾기가 어려웠음 (read 함수의 리턴값을 활용하긴 했었는데, 모든 테스트 케이스드를 다 담지는 못했음, str의 길이를 알기 어려웠음)
- 고쳐서 새로 짜낸 것
    - while (str[i] ≠ ‘\n’ && str[i] ≠ ‘\0’) i++ 함
    - 위 반복문 돌고 난 후에 if (str[i] == ‘\n’)을 확인하면 개행을 발견한 것이고, 발견 못하면 ‘\0’까지 읽었을 것임.
    - ‘\0’의 경우에 i == read의 리턴값 이면, 파일 안끝난거고, 다르면 마즈막으로 파일 읽기 한 것임

## memory leaks

1. 임시로 쓰는 char *, t_list * 지워주기
2. static t_list *head도 갖고 있을 필요 없는 경우에는 free해 줘야함. 
    - head→next_fd == NULL 일때 free 해주기!
    - (leaks, lldb, fsanitize=address에 안나오고, 테스터기에서만 나와서 헤멤..)
