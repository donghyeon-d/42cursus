[학습 정리 노션 링크](https://helpful-eggplant-ec3.notion.site/GNL-get_next_line-b147b31988ec473cbc5ef99c098b96b6)

# GNL(get_next_line)
# 1. 무엇을 하는 과제인가?
- fd를 읽으면서 개행(\n) 단위로 char *로 리턴해주는 함수 만들기
- 파일의 문자를 읽을 때 한번에 읽어오지 않으며, 함수를 여러번 호출해도 잃어버리는 문자가 없어야 하고, 여러 fd를 번갈아 읽어도 잃어버리는 문자가 없어야 함
- 허용된 함수 : read, malloc, free
- 전역변수 사용 금지, static 변수 1개 사용 가능

<br>

# 2. 새롭게 배우는 개념은 무엇인가?
- 파일디스크립트 이해 및 사용
- read함수 사용
- 연결리스트 활용

<br>

# 3. 과제하면서 습득한 것
- lldb를 사용한 디버깅
- C 컴파일 옵션 -g3 -fasnitize=address를 사용한 메모리 참조 오류 검사
- 연결리스트의 개념을 확실히 익히고 자유롭게 사용할 수 있게 됨 (2중 연결리스트를 사용하여 구현함)

<br>

# 4. 구현 방식

## 구조체연결리스트 사용
`char	*get_next_line(int fd)`
- 구조체 
``` C
typedef struct s_list
{
	char			*content;
	ssize_t			fd;
	struct s_list	*next;
	struct s_list	*next_fd;
}	t_list;
```
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

<br>

# 5. 봉착된 문제

## \n, \0, NULL 찾기

- 처음에 구현했던 것
    - int check_n(char *s) 함수를 만들어서 str에서 \n의 자리를 찾고, 없으면을 -1 해줬음
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