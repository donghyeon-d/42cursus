# 함수

## [Part 1] Libc functions

### 확인 함수 (What is)

- [ft_isalpha](https://blockdmask.tistory.com/448) : 알파벳인지 확인. 대문자 1, 소문자2, 아니면 0 리턴
- [ft_isdigit](https://ya-ya.tistory.com/83) : 숫자인지 확인. 맞으면 4, 아니면 0 리턴
- ft_isalnum : 알파벳인지 숫자인지 확인. 맞으면1 아니면 0 리턴
- ft_isascii : ascii 값이면 1 아니면 0
- ft_isprint : ascii 기준으로 printable 값인지 확인. 맞으면 1 아니면 0 (32 ≤ c ≤ 126)
- ft_toupper : 소문자를 대문자로 바꿔줌(ft_isalpha 리턴값 활용)
- ft_tolower : 대문자를 대문자로 바꿔줌(ft_isalpha 리턴값 활용)

### 문자열 함수 (str)

- ft_strlen : 문자열의 길이를 반환
- [ft_strlcpy](https://velog.io/@meong9090/42seoul-strlcpy%EB%8A%94-%EC%96%B4%EB%96%A4-%ED%95%A8%EC%88%98%EC%9D%BC%EA%B9%8C) : size = dst+null 길이. size를 작게 입력하면 src의 일부만 복사되는데, 그건 함수 사용자의 몫임. 리턴값은 src의 길이
- ft_strlcat : dst에 src를 dstsize - strlen(dst) - 1 만큼 이어 붙임. 마지막엔 null.
    - return : dstlen + srclen (dst_len ≥ destsize → srclen + dstsize)
- ft_strchr : str 에서 c 찾기. 찾으면 찾은 자리 주소 리턴, 못찾으면 null(0) 리턴
    - c = ‘\0’ 인 경우, str의 끝에있는 null의 자리(주소)를 리턴해줘야함
- ft_strrchr : strchr랑 똑같은데, c를 str의 뒤에서부터 찾음
- ft_strncmp : str 2개를 사전적으로 비교. 문자 끝날때까지, n자리수만큼 비교. str1 - str2 를 리턴하는데 unsigned char 만 비교돼야함
- ft_strnstr : str1에서 str2를 찾는데, str1에서 len 길이 만큼만 확인해 봄. 찾은 자리의 주소를 반환함
- ft_strdup : str을 duplicate해줌. 메모리 할당해서 거기에 스트링 넣고 주소 반환

### 메모리 함수 (mem)

- ft_memset : [(참고)](https://www.notion.so/bfe0148fda4e49158b0229d7a88f9849)
- ft_bzero(void *s, size_t n) : s를 0으로 n길이의 바이트만큼 채우는 것. memset(s, 0, n)
- ft_memcpy : src를 dst에 n 길이만큼 복사. src와 dst가 겹쳐도 신경 안씀(덮어 씌운걸 가지고 또 덮어 쓸 수 있음) [참고](https://minsoftk.tistory.com/29)
- ft_memmove : src를 dst에 n 길이만큼 복사. src와 dst가 겹치는거 신경써줌(temp에 빼놨다가 dst에 옮겨줌)
- ft_memchr : byte 단위로 c가 나오는 부분을 찾음. 찾으면 그 자리 리턴, 못찾거나 n개 이내로 못찾으면 NULL리턴.
    - unsgined char 형 사용해야하는 이유 [(참고)](https://kldp.org/node/75686)
        - unsigned char 는 모든 bit를 투명하게 볼 수 있는 특성을 제공함. 다른 type은 내부 비트의 일부를 값을 표현하기 위한 용도가 아닌 다른 용도로 사용할 수 있으나, unsigned char 는 그게 안됨
        - char 보다 더 많은 수를 표현할 수 있음(확장 ascii) → signed char 와 unsigned char 사이의 값 변환이 1:1로 이루어지지 않을 수 있음.
        - ⇒ 임의의 메모리에 바이트 단위로 접근해서 값을 다룰 때는 무조건 unsigned char를 이용해야함. 그래야 모든 가능성을 다 확인할 수 있음
- ft_memcmp : byte 단위로 n byte만큼 두 포인터를 비교함. [참고](https://kirkim.github.io/c/2021/02/15/memcmp.html)
- ft_atoi : str을 int 형으로 바꿔줌. [범위 참고(슬랙)](https://42born2code.slack.com/archives/CU6MU5TB7/p1609838354265300)
- ft_calloc : count * size 만큼의 메모리를 할당해주고, 그 공간을 0으로 초기화해줌

# [Part 2] Additional functions

### 출력 함수 print

- ft_putchar_fd
    - void	ft_putchar_fd(char c, int fd);
    - char를 출력하는데, write 함수 첫번째 인자에 fd가 들어가야 함
- ft_putstr_fd
    - void	ft_putstr_fd(char *s, int fd);
    - 문자열을 출력하는데, write 함수 첫번째 인자에 fd가 들어가야 함
- ft_putendl_fd
    - void	ft_putendl_fd(char *s, int fd)
    - 문자열을 출력하는데, write 함수 첫번째 인자에 fd가 들어가야 함
    - 문자열 출력하고 개행 출력하기
    - (?) 개행문자에도 파일 디스크립트 동일하게 적용해야되나? 일단 fd로해놨음.
- ft_putnbr_fd
    - void	ft_putnbr_fd(int n, int fd)
    - int로 주어진 숫자 출력하기. write 함수 첫번째 인자에 fd가 들어가야 함
    - 재귀로 풀었음. int 최솟값 확인해주기

### 문자열 함수 str

- ft_substr
    - char	*ft_substr(char const *s, unsigned int start, size_t len)
    - s에서 start 글자부터 len의 길이 만큼을 duplicate 함
    - return : 위에서 duplicate 한 string의 주소를 리턴함.
    - 널가드, start랑 겹치는거 없을때 NULL(0)리턴
- ft_strjoin
    - char	*ft_strjoin(char const *s1, char const *s2)
    - 공간을 만들고, s1을 앞에, s2를 뒤에 붙이는 함수. 문자열이니까 마지막 널까지!
    - 널가드
- ft_strtrim
    - char	*ft_strtrim(char const *s1, char const *set)
    - s1에서 앞뒤로 set에 포함되는 글자들은 자르고 남은 것들만 새 str으로 만듦
    - 맨앞 / 맨뒤에서부터 연속되는 것들만 자르기
    1. char가 set인지 판단하는 함수만들기
    2. 잘라낸 str의 길이 구하기
    3. 길이만큼 공간 할당하고, 채워넣기
    - 이 함수만을 위한 함수는 static으로 선언해서 여기서만 사용하게 설정함.
- ft_strsplit
    - char	**ft_split(char const *s, char c)
    - s의 문자열을 c의 구분자를 가지고 쪼개서 문자열(단어)의 배열을 만드는 함수
    - 문자열의 배열을 리턴
    1. 구분자 판단하는 함수 ft_issep
    2. 단어가 몇개인지 세는 함수 ft_wordcount
    3. 단어의 길이 구하는 함수 ft_wordlen
    4. 단어를 위한 공간을 만들고 duplicate하는 함수 ft_word
    - 이 함수만을 위한 함수는 static으로 선언해서 여기서만 사용하게 설정함.
    
- ft_itoa
    - char	*ft_itoa(int n)
    - int로 들어온 숫자를 문자열로 변환시켜서 그 주소를 리턴해주는 함수
    1. int n가 몇글자가 될지 구해줌 (음수인 경우, 음수의 최솟값, 0 잘 확인해야함)
    2. 길이만큼 메모리 할당해주기 (널가드!)
    3. 할당한 공간에 숫자 하나씩 넣어주기 
        - 음수면 부호 넣기
        - % 10 으로해서 문자열 뒤에 부터 채워줄 수 있음
        - ascii 문자여야함
        - 최솟값 오버플러우 안되게 확인
        - 널로 마무리
- ft_strmapi
    - char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    - char *s 의 각 문자를 f함수에 넣은 리턴값들을 문자열로 반환함
    - unsigned int는 문자 s의 index 값
    - 널가드, 널로 닫아주기 필수
- ft_striteri
    - void	ft_striteri(char *s, void (*f)(unsigned int, char *))
    - 문자열 s의 각 자리를 f 함수에 넣어서 적용하는거 (리턴값은 없음)
    - unsigned int 는 index값이고, char *에는 문자 자리의 주소를 넣어주기)

## [Bonus part]

- ft_lstnew : 리스트 하나 생성
- ft_lstadd_front : 맨 앞에 요소 추가
- ft_lstsize : 리스트의 길이(사이즈) 리턴
- ft_lstlast : 리스트의 마지막 요소 리턴
- ft_lstadd_back : 리스트의 맨 뒤에 요소 추가
- ft_lstdelone : 리스트의 요소 지우기 + 해당 리스트 메모리 free
- ft_lstclear : 리스트의 전체 요소 지우기(처음부터 끝까지)
- ft_lstiter : 리스트 쭉 돌면서 적용
- ft_lstmap : 리스트 쭉 돌면서 적용한 것의 리턴값

## [테스터 돌려본 후]

- [참고](https://42born2code.slack.com/archives/CU6MU5TB7/p1609842365301000)
- split에서 word에서 에러났을 때 free해줘야돼