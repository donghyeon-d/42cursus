[노션 링크](https://www.notion.so/ft_printf-a89bea73b32f41838b9b43ad7b2db6c0)

# ft_printf

# 함수 메뉴얼(레퍼런스)

- [cppreference](https://en.cppreference.com/w/c/io/fprintf)
- 위키 [(한글)](https://ko.wikipedia.org/wiki/C_%ED%91%9C%EC%A4%80_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)
- [microsoft visual studio](https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170)
- 형식지정자 [(코딩도장)](https://dojang.io/mod/page/view.php?id=736) [(tutorial point)](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm)
- [IBM printf 설명](https://www.ibm.com/docs/ko/i/7.3?topic=functions-printf-print-formatted-characters)

# 가변인자 Variadic functions <stdarg.h> [(reference)](https://en.cppreference.com/w/c/variadic)

- va_list는 type, va_start, va arg, va_copy, va_end는 매크로(함수 매크로인듯?)
- va_list (typedef 구조체) : 가변인자의 포인터
    - va_list ap; 이렇게 선언해서 ap를 가변인자의 첫 자리의 주소를 가리키는 포인터로 사용함
- void va_start(va_list ap, parmN) : ap라는 구조체가 parmN에 접근할 수 있게 해줌(파일 읽기에서 open같은 느낌인가?)
    - parmN : 매개변 수 중 첫 번째 변수로 명명된 매개변수 → printf(a, b, c, d, e)에서 a를 의미함
    - va_arg 함수 사용하기 전에 사용해야함
- T va_arg(va_list ap, T) : ap가 다음 매개변수를 보게 해줌
    - va_arg 전에 va_start 또는 va_copy를 통해 초기화 된 상태여야 함
    - 한번 호출할 때마다 ap가 다음 매개변수를 보게 됨
    - T : ap에서 다음 매개변수의 자료형
    - return : T자료형인 값을 반환함
    
    ![Untitled](ft_printf%20f95cb9d7126246b6b759dc24391c09e8/Untitled.png)
    
- void va_copy(va_list dest, va_list src)
    - src를 dest로 복사함(va_list가 포인터니까 주소를 복사해오는 것)
- void va_end(va_list ap)
    - va_start와 반대로 ap라는 구조체가 더이상 매개변수에 접근할 수 없도록 닫아주는 것.
    - va_start와 va_copy의 호출이 없거나, 두 개를 호출하는 함수가 반환되기 전에 va_end가 호출되지 않으면 동작이 정의되지 않음 (????)
    
    ![Untitled](ft_printf%20f95cb9d7126246b6b759dc24391c09e8/Untitled%201.png)
    

# bonus 서식지정자

[(참조) 코딩도장](https://dojang.io/mod/page/view.php?id=736)

# 함수포인터

- 함수 포인터를 반환하는 함수 [(참조)](https://dojang.io/mod/page/view.php?id=600)

# 함수 전체적 구조

1. 구조체에 각종 플래그를 체크하고 길이들을 저장할 수 있는 멤버들 넣기
2. fmt 를 돌면서 % 만나면 flag 체크하면서 구조체 멤버에 값 넣기
3. flag 뒤에 자료형별로 가변인자 받기
4. flag에 들어가있는 내용들 살펴보면서 길이랑 옵션들 정리하기
5. 자료형별로 str 화 해주기
6. 자료형별로 경우에따라 순서대로 요소들 출력
7. malloc 실패 or write 실패시 error 플래그에서 체크하고, 본함수에서 리턴 -1 해줌

# printf 출력 경우 나누기

% : c s p d i u x X o O %

flag : # ‘ ‘ - + 0 . digit

- 출력 : 버퍼, 패딩, prefix, sign, 문자들 각각 출력. 경우에 맞춰서 순서와 길이를 확인하고 출력해줌

### char

- write(1, c, 1) 로 한글자씩 출력
- return : 1 (c == ‘\0’ 일때도 리턴 1)
- c1 = a,   c2 = 0

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("s   : %s %s|\n", c1, c2);     | |a|| | 2 |  |
| printf("#   : %#s %#s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("-   : %-s %-s|\n", c1, c2); | |a|| | 2 |  |
| printf("+   : %+s %+s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("' ' : % s % s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("0   : %0s %0s|\n", c1, c2); | |a|| | 2 | undefine |
| printf(".   : %.s %.s|\n", c1, c2); | |a|| | 2 |  |
| printf(".0 : |%.0s|%.0s|", c1, c2); | |a|| | 2 | undefine |
| printf("4   : %4s %4s|\n", c1, c2); | |   a|   | | 8 |  |
| printf("8   : %8s %8s|\n", c1, c2); | |       a|       | | 16 |  |
| printf(".8  : %.8s %.8s|\n", c1, c2); | |a|| | 2 | undefine |
| printf(".4  : %.4s %.4s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("-8  : %-8s %-8s|\n", c1, c2); | |a       |       | | 16 |  |
| printf("-4  : %-4s %-4s|\n", c1, c2); | |a   |   | | 8 |  |
| printf("-4.8: %-4.8s %-4.8s|\n", c1, c2); | |a   |   | | 8 | undefine |
| printf("-8.4: %-8.4s %-8.4s|\n", c1, c2; | |a       |       | | 16 | undefine |
| printf("4.8: |%4.8c|%4.8c|", c1, c2); | |   a|   | |  |  |
| printf("8.5: |%8.4c|%8.4c|", c1, c2); | |       a|       | |  |  |
- c = 0 출력하면 아무것도 안나오지만 return 값은 1
- digit ≤ strlen 다 출력.
digit > strlen 차이 만큼 버퍼 더 출력

```c
int a;
char c1 = 'a';
char c2 = 0;

	a = printf("c   : |%c|%c|", c1, c2);printf("  return = %d\n", a);
	a = printf("#   : |%#c|%#c|", c1, c2);printf("  return = %d\n", a);
	a = printf("-   : |%-c|%-c|", c1, c2);printf("  return = %d\n", a);
	a = printf("+   : |%+c|%+c|", c1, c2);printf("  return = %d\n", a);
	a = printf("' ' : |% c|% c|", c1, c2);printf("  return = %d\n", a);
	a = printf("0   : |%0c|%0c|", c1, c2);printf("  return = %d\n", a);
	a = printf(".   : |%.c|%.c|", c1, c2);printf("  return = %d\n", a);
	a = printf(".0  : |%.0c|%.0c|", c1, c2);printf("  return = %d\n", a);
	a = printf("4   : |%4c|%4c|", c1, c2);printf("  return = %d\n", a);
	a = printf("8   : |%8c|%8c|", c1, c2);printf("  return = %d\n", a);
	a = printf(".8  : |%.8c|%.8c|", c1, c2);printf("  return = %d\n", a);
	a = printf(".4  : |%.4c|%.4c|", c1, c2);printf("  return = %d\n", a);
	a = printf("-8  : |%-8c|%-8c|", c1, c2);printf("  return = %d\n", a);
	a = printf("-4  : |%-4c|%-4c|", c1, c2);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8c|%-4.8c|", c1, c2);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4c|%-8.4c|", c1, c2);printf("  return = %d\n", a);
	a = printf("4.8: |%4.8c|%4.8c|", c1, c2);printf("  return = %d\n", a);
	a = printf("8.4: |%8.4c|%8.4c|", c1, c2);printf("  return = %d\n", a);

/*  출력 결과
c   : |a||  return = 11
#   : |a||  return = 11
-   : |a||  return = 11
+   : |a||  return = 11
' ' : |a||  return = 11
0   : |a||  return = 11
.   : |a||  return = 11
.0  : |a||  return = 11
4   : |   a|   |  return = 17
8   : |       a|       |  return = 25
.8  : |a||  return = 11
.4  : |a||  return = 11
-8  : |a       |       |  return = 25
-4  : |a   |   |  return = 17
-4.8: |a   |   |  return = 17
-8.4: |a       |       |  return = 25
4.8 : |   a|   |  return = 16
8.4 : |       a|       |  return = 24
*/
```

### str (char *)

- 출력문자는 va_arg(*ap, char *) 해온 것 그대로 출력
- str1 = “abcdef”,   str2 = NULL

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("s   : %s %s|\n", str1, str2);     | |abcdef|(null)| | 12 |  |
| printf("#   : %#s %#s|\n", str1, str2); | |abcdef|(null)| | 12 | undefine |
| printf("' ' : % s % s|\n", str1, str2); | |abcdef|(null)| | 12 | undefine |
| printf("-   : %-s %-s|\n", str1, str2); | |abcdef|(null)| | 12 |  |
| printf("+   : %+s %+s|\n", str1, str2); | |abcdef|(null)| | 12 | undefine |
| printf("0   : %0s %0s|\n", str1, str2); | |abcdef|(null)| | 12 | undefine |
| printf(".   : %.s %.s|\n", str1, str2); | ||| | 0 |  |
| printf(".0 : |%.0s|%.0s|", str1, str2); | ||| | 0 |  |
| printf("4   : %4s %4s|\n", str1, str2); | |abcdef|(null)| | 12 |  |
| printf("8   : %8s %8s|\n", str1, str2); | |  abcdef|  (null)| | 16 |  |
| printf(".8  : %.8s %.8s|\n", str1, str2); | |abcdef|(null)| | 12 |  |
| printf(".4  : %.4s %.4s|\n", str1, str2); | |abcd|(nul| | 8 |  |
| printf("-8  : %-8s %-8s|\n", str1, str2); | |abcdef  |(null)  | | 16 |  |
| printf("-4  : %-4s %-4s|\n", str1, str2); | |abcdef|(null)| | 12 |  |
| printf("-4.8: %-4.8s %-4.8s|\n", str1, str2); | |abcdef|(null)| | 12 |  |
| printf("-8.4: %-8.4s %-8.4s|\n", str1, str2); | |abcd    |(nul    | | 16 |  |
- prec(.num) ≤ strlen str 짤라서 출력
prec(.num) > strlen str 다 출력
- digit ≤ strlen 다 출력.
digit > strlen 차이 만큼 버퍼 더 출력

```c
int a, b;
	char *str1 = "abcdef";
	char *str2 = NULL;

	a = printf("s   : |%s|%s|", str1, str2);printf("  return = %d\n", a);
	a = printf("#   : |%#s|%#s|", str1, str2);printf("  return = %d\n", a);
	a = printf("-   : |%-s|%-s|", str1, str2);printf("  return = %d\n", a);
	a = printf("+   : |%+s|%+s|", str1, str2);printf("  return = %d\n", a);
	a = printf("' ' : |% s|% s|", str1, str2);printf("  return = %d\n", a);
	a = printf("0   : |%0s|%0s|", str1, str2);printf("  return = %d\n", a);
	a = printf(".   : |%.s|%.s|", str1, str2);printf("  return = %d\n", a);
  a = printf(".0 : |%.0s|%.0s|", str1, str2);printf("  return = %d\n", a);
	a = printf("4   : |%4s|%4s|", str1, str2);printf("  return = %d\n", a);
	a = printf("8   : |%8s|%8s|", str1, str2);printf("  return = %d\n", a);
	a = printf(".8  : |%.8s|%.8s|", str1, str2);printf("  return = %d\n", a);
	a = printf(".4  : |%.4s|%.4s|", str1, str2);printf("  return = %d\n", a);
	a = printf("-8  : |%-8s|%-8s|", str1, str2);printf("  return = %d\n", a);
	a = printf("-4  : |%-4s|%-4s|", str1, str2);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8s|%-4.8s|", str1, str2);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4s|%-8.4s|", str1, str2);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8s|%4.8s|", str1, str2);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4s|%8.4s|", str1, str2);printf("  return = %d\n", a);

/*  출력 결과
s   : |abcdef|(null)|  return = 21
#   : |abcdef|(null)|  return = 21
-   : |abcdef|(null)|  return = 21
+   : |abcdef|(null)|  return = 21
' ' : |abcdef|(null)|  return = 21
0   : |abcdef|(null)|  return = 21
.   : |||  return = 9
.0  : |||  return = 9
4   : |abcdef|(null)|  return = 21
8   : |  abcdef|  (null)|  return = 25
.8  : |abcdef|(null)|  return = 21
.4  : |abcd|(nul|  return = 17
-8  : |abcdef  |(null)  |  return = 25
-4  : |abcdef|(null)|  return = 21
-4.8: |abcdef|(null)|  return = 21
-8.4: |abcd    |(nul    |  return = 25
4.8 : |abcdef|(null)|  return = 19
8.4 : |    abcd|    (nul|  return = 23
*/
```

### pointer

- 출력문자는 va_arg(*ap, void *) 해온 것 size_t로 형변환
- 숫자로 들어온거 convert base 해서 진수로 바꿈
- prefix(0, 0x)랑 위의 결과물 join
- str1 = “abcdef”,   str2 = NULL

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("p   : |%p|%p|%p|", 1, 0, -1) | |0x1|0x0|0xffffffff| | 16 |  |
| printf("#   : |%#p|%#p|%#p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("-   : |%-p|%-p|%-p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 |  |
| printf("+   : |%+p|%+p|%+p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("' ' : |% p|% p|% p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("0   : |%0p|%0p|%0p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf(".   : |%.p|%.p|%.p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf(".0  : |%.0p|%.0p|%.0p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf("4   : |%4p|%4p|%4p|", 1, 0, -1); | | 0x1| 0x0|0xffffffff| | 18 |  |
| printf("8   : |%8p|%8p|%8p|", 1, 0, -1); | |     0x1|     0x0|0xffffffff| | 26 |  |
| printf(".8  : |%.8p|%.8p|%.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 | undefine |
| printf(".4  : |%.4p|%.4p|%.4p|", 1, 0, -1); | |0x0001|0x0000|0xffffffff| | 22 | undefine |
| printf("-8  : |%-8p|%-8p|%-8p|", 1, 0, -1); | |0x1     |0x0     |0xffffffff| | 26 |  |
| printf("-4  : |%-4p|%-4p|%-4p|", 1, 0, -1); | |0x1 |0x0 |0xffffffff| | 18 |  |
| printf("-4.8: |%-4.8p|%-4.8p|%-4.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 |  |
| printf("-8.4: |%-8.4p|%-8.4p|%-8.4p|", 1, 0, -1); | |0x0001  |0x0000  |0xffffffff| | 26 |  |
| printf("4.8: |%4.8p|%4.8p|%4.8p|", 1, 0, -1) | |0x00000001|0x00000000|0xffffffff| | 29 |  |
| printf("8.4: |%8.4p|%8.4p|%8.4p|", 1, 0, -1) | |  0x0001|  0x0000|0xffffffff| | 25 |  |
- . 있는데 . 뒤의 숫자 0이면 0x로 출력(0 출력 안함)
- prec(.num) > numlen 이면, 0x 출력, prec - numlen 만큼 0 출력, num 출력
- digit ≤ numlen(+prec) 이면 위처럼 출력.
digit > numlen(+prec) 이면, 차이 만큼 버퍼 출력하고 위 출력

```c
int a, b;

	a = printf("p   : |%p|%p|%p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("#   : |%#p|%#p|%#p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-   : |%-p|%-p|%-p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("+   : |%+p|%+p|%+p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("' ' : |% p|% p|% p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("0   : |%0p|%0p|%0p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".   : |%.p|%.p|%.p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".0  : |%.0p|%.0p|%.0p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4   : |%4p|%4p|%4p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8   : |%8p|%8p|%8p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".8  : |%.8p|%.8p|%.8p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".4  : |%.4p|%.4p|%.4p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8  : |%-8p|%-8p|%-8p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4  : |%-4p|%-4p|%-4p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8p|%-4.8p|%-4.8p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4p|%-8.4p|%-8.4p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8p|%4.8p|%4.8p|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4p|%8.4p|%8.4p|", 1, 0, -1);printf("  return = %d\n", a);

/*  출력 결과
p   : |0x1|0x0|0xffffffff|  return = 26
#   : |0x1|0x0|0xffffffff|  return = 26
-   : |0x1|0x0|0xffffffff|  return = 26
+   : |0x1|0x0|0xffffffff|  return = 26
' ' : |0x1|0x0|0xffffffff|  return = 26
0   : |0x1|0x0|0xffffffff|  return = 26
.   : |0x1|0x|0xffffffff|  return = 25
.0  : |0x1|0x|0xffffffff|  return = 25
4   : | 0x1| 0x0|0xffffffff|  return = 28
8   : |     0x1|     0x0|0xffffffff|  return = 36
.8  : |0x00000001|0x00000000|0xffffffff|  return = 40
.4  : |0x0001|0x0000|0xffffffff|  return = 32
-8  : |0x1     |0x0     |0xffffffff|  return = 36
-4  : |0x1 |0x0 |0xffffffff|  return = 28
-4.8: |0x00000001|0x00000000|0xffffffff|  return = 40
-8.4: |0x0001  |0x0000  |0xffffffff|  return = 36
4.8: |0x00000001|0x00000000|0xffffffff|  return = 39
8.4: |  0x0001|  0x0000|0xffffffff|  return = 35
*/
```

### u (unsigned int)

- 출력문자는 va_arg(*ap, unsigned) 해온 convert base 해서 진수로 바꿈
- 1, 0, -1
- digit > numlen(+prec) 이면, digit - (numlen + prec) 공백 출력
- first_sign 있으면 출력
- prec(.num) > numlen 이면, prec - numlen 만큼 0 출력, num 출력

```c
int a;

	a = printf("u   : |%u|%u|%u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("#   : |%#u|%#u|%#u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-   : |%-u|%-u|%-u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("+   : |%+u|%+u|%+u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("' ' : |% u|% u|% u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("0   : |%0u|%0u|%0u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".   : |%.u|%.u|%.u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".0  : |%.0u|%.0u|%.0u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4   : |%4u|%4u|%4u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8   : |%8u|%8u|%8u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".8  : |%.8u|%.8u|%.8u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".4  : |%.4u|%.4u|%.4u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8  : |%-8u|%-8u|%-8u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4  : |%-4u|%-4u|%-4u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8u|%-4.8u|%-4.8u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4u|%-8.4u|%-8.4u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8u|%4.8u|%4.8u|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4u|%8.4u|%8.4u|", 1, 0, -1);printf("  return = %d\n", a);

/*  출력 결과
u   : |1|0|4294967295|  return = 22
#   : |1|0|4294967295|  return = 22
-   : |1|0|4294967295|  return = 22
+   : |1|0|4294967295|  return = 22
' ' : |1|0|4294967295|  return = 22
0   : |1|0|4294967295|  return = 22
.   : |1||4294967295|  return = 21
.0  : |1||4294967295|  return = 21
4   : |   1|   0|4294967295|  return = 28
8   : |       1|       0|4294967295|  return = 36
.8  : |00000001|00000000|4294967295|  return = 36
.4  : |0001|0000|4294967295|  return = 28
-8  : |1       |0       |4294967295|  return = 36
-4  : |1   |0   |4294967295|  return = 28
-4.8: |00000001|00000000|4294967295|  return = 36
-8.4: |0001    |0000    |4294967295|  return = 36
4.8 : |00000001|00000000|4294967295|  return = 36
8.4 : |    0001|    0000|4294967295|  return = 36
*/
```

### d, i (int)

- 1, 0, -1
- minus 유무에 따라 공백 먼저 출력할지, first_sign먼저 출력할지
- digit > numlen(+prec) 이면, digit - (numlen + prec) 공백 출력
- first_sign 있으면 출력
- prec(.num) > numlen 이면, prec - numlen 만큼 0 출력, num 출력

```c
int a;

	a = printf("d   : |%d|%d|%d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("#   : |%#d|%#d|%#d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-   : |%-d|%-d|%-d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("+   : |%+d|%+d|%+d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("' ' : |% d|% d|% d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("0   : |%0d|%0d|%0d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".   : |%.d|%.d|%.d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".0  : |%.0d|%.0d|%.0d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4   : |%4d|%4d|%4d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8   : |%8d|%8d|%8d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".8  : |%.8d|%.8d|%.8d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf(".4  : |%.4d|%.4d|%.4d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8  : |%-8d|%-8d|%-8d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4  : |%-4d|%-4d|%-4d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8d|%-4.8d|%-4.8d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4d|%-8.4d|%-8.4d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8d|%4.8d|%4.8d|", 1, 0, -1);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4d|%8.4d|%8.4d|", 1, 0, -1);printf("  return = %d\n", a);

/*  출력 결과
d   : |1|0|-1|  return = 14
#   : |1|0|-1|  return = 14
-   : |1|0|-1|  return = 14
+   : |+1|+0|-1|  return = 16
' ' : | 1| 0|-1|  return = 16
0   : |1|0|-1|  return = 14
.   : |1||-1|  return = 13
.0  : |1||-1|  return = 13
4   : |   1|   0|  -1|  return = 22
8   : |       1|       0|      -1|  return = 34
.8  : |00000001|00000000|-00000001|  return = 35
.4  : |0001|0000|-0001|  return = 23
-8  : |1       |0       |-1      |  return = 34
-4  : |1   |0   |-1  |  return = 22
-4.8: |00000001|00000000|-00000001|  return = 35
-8.4: |0001    |0000    |-0001   |  return = 34
4.8 : |00000001|00000000|-00000001|  return = 35
8.4 : |    0001|    0000|   -0001|  return = 34
*/
```

### basenum (x, X)

- 출력문자는 va_arg(*ap, int) 해온 것 size_t로 형변환
- 숫자로 들어온거 convert base 해서 진수로 바꿈
- str1 = “abcdef”,   str2 = NULL

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("p   : |%p|%p|%p|", 1, 0, -1) | |0x1|0x0|0xffffffff| | 16 |  |
| printf("#   : |%#p|%#p|%#p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("-   : |%-p|%-p|%-p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 |  |
| printf("+   : |%+p|%+p|%+p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("' ' : |% p|% p|% p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("0   : |%0p|%0p|%0p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf(".   : |%.p|%.p|%.p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf(".0  : |%.0p|%.0p|%.0p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf("4   : |%4p|%4p|%4p|", 1, 0, -1); | | 0x1| 0x0|0xffffffff| | 18 |  |
| printf("8   : |%8p|%8p|%8p|", 1, 0, -1); | |     0x1|     0x0|0xffffffff| | 26 |  |
| printf(".8  : |%.8p|%.8p|%.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 | undefine |
| printf(".4  : |%.4p|%.4p|%.4p|", 1, 0, -1); | |0x0001|0x0000|0xffffffff| | 22 | undefine |
| printf("-8  : |%-8p|%-8p|%-8p|", 1, 0, -1); | |0x1     |0x0     |0xffffffff| | 26 |  |
| printf("-4  : |%-4p|%-4p|%-4p|", 1, 0, -1); | |0x1 |0x0 |0xffffffff| | 18 |  |
| printf("-4.8: |%-4.8p|%-4.8p|%-4.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 |  |
| printf("-8.4: |%-8.4p|%-8.4p|%-8.4p|", 1, 0, -1); | |0x0001  |0x0000  |0xffffffff| | 26 |  |
| printf("4.8: |%4.8p|%4.8p|%4.8p|", 1, 0, -1) | |0x00000001|0x00000000|0xffffffff| | 29 |  |
| printf("8.4: |%8.4p|%8.4p|%8.4p|", 1, 0, -1) | |  0x0001|  0x0000|0xffffffff| | 25 |  |
- . 있는데 . 뒤의 숫자 0이면 0x로 출력(0 출력 안함)
- prec(.num) > numlen 이면, 0x 출력, prec - numlen 만큼 0 출력, num 출력
- digit ≤ numlen(+prec) 이면 위처럼 출력.
digit > numlen(+prec) 이면, 차이 만큼 버퍼 출력하고 위 출력

```c
int a, b;

	a = printf("x   : |%x|%x|%x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("#   : |%#x|%#x|%#x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-   : |%-x|%-x|%-x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("+   : |%+x|%+x|%+x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("' ' : |% x|% x|% x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("0   : |%0x|%0x|%0x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".   : |%.x|%.x|%.x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".0  : |%.0x|%.0x|%.0x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("4   : |%4x|%4x|%4x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("8   : |%8x|%8x|%8x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".8  : |%.8x|%.8x|%.8x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".4  : |%.4x|%.4x|%.4x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-8  : |%-8x|%-8x|%-8x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-4  : |%-4x|%-4x|%-4x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8x|%-4.8x|%-4.8x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4x|%-8.4x|%-8.4x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8x|%4.8x|%4.8x|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4x|%8.4x|%8.4x|", 187, 0, -187);printf("  return = %d\n", a);

/*  출력 결과
x   : |bb|0|ffffff45|  return = 21
#   : |0xbb|0|0xffffff45|  return = 25
-   : |bb|0|ffffff45|  return = 21
+   : |bb|0|ffffff45|  return = 21
' ' : |bb|0|ffffff45|  return = 21
0   : |bb|0|ffffff45|  return = 21
.   : |bb||ffffff45|  return = 20
.0  : |bb||ffffff45|  return = 20
4   : |  bb|   0|ffffff45|  return = 26
8   : |      bb|       0|ffffff45|  return = 34
.8  : |000000bb|00000000|ffffff45|  return = 34
.4  : |00bb|0000|ffffff45|  return = 26
-8  : |bb      |0       |ffffff45|  return = 34
-4  : |bb  |0   |ffffff45|  return = 26
-4.8: |000000bb|00000000|ffffff45|  return = 34
-8.4: |00bb    |0000    |ffffff45|  return = 34
4.8 : |000000bb|00000000|ffffff45|  return = 34
8.4 : |    00bb|    0000|0xffffff45|  return = 36
*/
```

### basenum (o, O)

- 출력문자는 va_arg(*ap, int) 해온 것 size_t로 형변환
- 숫자로 들어온거 convert base 해서 진수로 바꿈
- str1 = “abcdef”,   str2 = NULL

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("p   : |%p|%p|%p|", 1, 0, -1) | |0x1|0x0|0xffffffff| | 16 |  |
| printf("#   : |%#p|%#p|%#p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("-   : |%-p|%-p|%-p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 |  |
| printf("+   : |%+p|%+p|%+p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("' ' : |% p|% p|% p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf("0   : |%0p|%0p|%0p|", 1, 0, -1); | |0x1|0x0|0xffffffff| | 16 | undefine |
| printf(".   : |%.p|%.p|%.p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf(".0  : |%.0p|%.0p|%.0p|", 1, 0, -1); | |0x1|0x|0xffffffff| | 15 |  |
| printf("4   : |%4p|%4p|%4p|", 1, 0, -1); | | 0x1| 0x0|0xffffffff| | 18 |  |
| printf("8   : |%8p|%8p|%8p|", 1, 0, -1); | |     0x1|     0x0|0xffffffff| | 26 |  |
| printf(".8  : |%.8p|%.8p|%.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 | undefine |
| printf(".4  : |%.4p|%.4p|%.4p|", 1, 0, -1); | |0x0001|0x0000|0xffffffff| | 22 | undefine |
| printf("-8  : |%-8p|%-8p|%-8p|", 1, 0, -1); | |0x1     |0x0     |0xffffffff| | 26 |  |
| printf("-4  : |%-4p|%-4p|%-4p|", 1, 0, -1); | |0x1 |0x0 |0xffffffff| | 18 |  |
| printf("-4.8: |%-4.8p|%-4.8p|%-4.8p|", 1, 0, -1); | |0x00000001|0x00000000|0xffffffff| | 30 |  |
| printf("-8.4: |%-8.4p|%-8.4p|%-8.4p|", 1, 0, -1); | |0x0001  |0x0000  |0xffffffff| | 26 |  |
| printf("4.8: |%4.8p|%4.8p|%4.8p|", 1, 0, -1) | |0x00000001|0x00000000|0xffffffff| | 29 |  |
| printf("8.4: |%8.4p|%8.4p|%8.4p|", 1, 0, -1) | |  0x0001|  0x0000|0xffffffff| | 25 |  |
- . 있는데 . 뒤의 숫자 0이면 0x로 출력(0 출력 안함)
- prec(.num) > numlen 이면, 0x 출력, prec - numlen 만큼 0 출력, num 출력
- digit ≤ numlen(+prec) 이면 위처럼 출력.
digit > numlen(+prec) 이면, 차이 만큼 버퍼 출력하고 위 출력

```c
int a, b;

	a = printf("o   : |%o|%o|%o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("#   : |%#o|%#o|%#o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-   : |%-o|%-o|%-o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("+   : |%+o|%+o|%+o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("' ' : |% o|% o|% o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("0   : |%0o|%0o|%0o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".   : |%.o|%.o|%.o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".0  : |%.0o|%.0o|%.0o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("4   : |%4o|%4o|%4o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("8   : |%8o|%8o|%8o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".8  : |%.8o|%.8o|%.8o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf(".4  : |%.4o|%.4o|%.4o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-8  : |%-8o|%-8o|%-8o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-4  : |%-4o|%-4o|%-4o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8o|%-4.8o|%-4.8o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4o|%-8.4o|%-8.4o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("4.8 : |%4.8o|%4.8o|%4.8o|", 187, 0, -187);printf("  return = %d\n", a);
	a = printf("8.4 : |%8.4o|%8.4o|%8.4p|", 187, 0, -187);printf("  return = %d\n", a);

/*  출력 결과
o : |273|0|37777777505|  return = 25
#   : |0273|0|037777777505|  return = 27
-   : |273|0|37777777505|  return = 25
+   : |273|0|37777777505|  return = 25
' ' : |273|0|37777777505|  return = 25
0   : |273|0|37777777505|  return = 25
.   : |273||37777777505|  return = 24
.0  : |273||37777777505|  return = 24
4   : | 273|   0|37777777505|  return = 29
8   : |     273|       0|37777777505|  return = 37
.8  : |00000273|00000000|37777777505|  return = 37
.4  : |0273|0000|37777777505|  return = 29
-8  : |273     |0       |37777777505|  return = 37
-4  : |273 |0   |37777777505|  return = 29
-4.8: |00000273|00000000|37777777505|  return = 37
-8.4: |0273    |0000    |37777777505|  return = 37
4.8 : |00000273|00000000|37777777505|  return = 37
8.4 : |    0273|    0000|0xffffff45|  return = 36
*/
```

### %

- c1 = a,   c2 = 0

| printf 형식 | 출력 결과 | 리턴값 | 비고 |
| --- | --- | --- | --- |
| printf("s   : %s %s|\n", c1, c2);     | |a|| | 2 |  |
| printf("#   : %#s %#s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("-   : %-s %-s|\n", c1, c2); | |a|| | 2 |  |
| printf("+   : %+s %+s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("' ' : % s % s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("0   : %0s %0s|\n", c1, c2); | |a|| | 2 | undefine |
| printf(".   : %.s %.s|\n", c1, c2); | |a|| | 2 |  |
| printf(".0 : |%.0s|%.0s|", c1, c2); | |a|| | 2 | undefine |
| printf("4   : %4s %4s|\n", c1, c2); | |   a|   | | 8 |  |
| printf("8   : %8s %8s|\n", c1, c2); | |       a|       | | 16 |  |
| printf(".8  : %.8s %.8s|\n", c1, c2); | |a|| | 2 | undefine |
| printf(".4  : %.4s %.4s|\n", c1, c2); | |a|| | 2 | undefine |
| printf("-8  : %-8s %-8s|\n", c1, c2); | |a       |       | | 16 |  |
| printf("-4  : %-4s %-4s|\n", c1, c2); | |a   |   | | 8 |  |
| printf("-4.8: %-4.8s %-4.8s|\n", c1, c2); | |a   |   | | 8 | undefine |
| printf("-8.4: %-8.4s %-8.4s|\n", c1, c2; | |a       |       | | 16 | undefine |
| printf("4.8: |%4.8c|%4.8c|", c1, c2); | |   a|   | |  |  |
| printf("8.5: |%8.4c|%8.4c|", c1, c2); | |       a|       | |  |  |
- c = 0 출력하면 아무것도 안나오지만 return 값은 1
- digit ≤ strlen 다 출력.
digit > strlen 차이 만큼 버퍼 더 출력

```c
int a;

	a = printf("%%   : |%%|");printf("  return = %d\n", a);
	a = printf("#   : |%#%|");printf("  return = %d\n", a);
	a = printf("-   : |%-%|");printf("  return = %d\n", a);
	a = printf("+   : |%+%|");printf("  return = %d\n", a);
	a = printf("' ' : |% %|");printf("  return = %d\n", a);
	a = printf("0   : |%0%|");printf("  return = %d\n", a);
	a = printf(".   : |%.%|");printf("  return = %d\n", a);
	a = printf(".0  : |%.0%|");printf("  return = %d\n", a);
	a = printf("4   : |%4%|");printf("  return = %d\n", a);
	a = printf("8   : |%8%|");printf("  return = %d\n", a);
	a = printf(".8  : |%.8%|");printf("  return = %d\n", a);
	a = printf(".4  : |%.4%|");printf("  return = %d\n", a);
	a = printf("-8  : |%-8%|");printf("  return = %d\n", a);
	a = printf("-4  : |%-4%|");printf("  return = %d\n", a);
	a = printf("-4.8: |%-4.8%|");printf("  return = %d\n", a);
	a = printf("-8.4: |%-8.4%|");printf("  return = %d\n", a);
	a = printf("4.8: |%4.8%|");printf("  return = %d\n", a);
	a = printf("8.4: |%8.4%|");printf("  return = %d\n", a);

/*  출력 결과
%   : |%|  return = 9
#   : |%|  return = 9
-   : |%|  return = 9
+   : |%|  return = 9
' ' : |%|  return = 9
0   : |%|  return = 9
.   : |%|  return = 9
.0  : |%|  return = 9
4   : |   %|  return = 12
8   : |       %|  return = 16
.8  : |%|  return = 9
.4  : |%|  return = 9
-8  : |%       |  return = 16
-4  : |%   |  return = 12
-4.8: |%   |  return = 12
-8.4: |%       |  return = 16
4.8: |   %|  return = 11
8.4: |       %|  return = 15
*/
```

# 테스트 돌려보던 중 잘 안된 것

```c
	a = printf("%-15.i\n", 0);printf("  return = %d\n", a);
		: 0 출력 안하니까 패딩 길이를 +1 해줘야함
		
	a = printf("%020d\n", -42000);printf("  return = %d\n", a);
		: digit만 있고 dot이 없는 경우, 공백이 아니라 0으로 채워줘야 함
		: ft_make_fill에서 buffer와 padding 값을 바꿔줘야 함.
```

# 전체적으로 2번 뒤집은 이유

### 1. 서브젝트 분석 실수

- 구현해야하는 flag가 6가지였는데, 2개를 빼고 생각했어서 처음부터 다시...

### 2. printf 출력 사례 분석 부족

- 전체 출력 폭에 맞춰 공간을 만들고, 버퍼, 패딩, prefix, sign, 문자들을 넣어지는 식으로 구현했었음
→ 필요한 함수들이 너무 많고, 경우를 나누는 것이 복잡해짐..
- 자료형과 플래그를 다양하게 넣었을 때의 출력 결과들을 미리 더 분석 해봤어야함
- 테스트 돌리다보니까 처음 구현할 때 생각하지 못한 경우의 수들이 더 많았음
- 그 모든 경우를 담기에 부족했던 구조

 

# 추가적으로 알게된 점

- flag가 많아졌을때, 비트연산자를 활용해주면 1바이트에 플래그 8개 사용 가능(메모리 줄일 수 있음)
