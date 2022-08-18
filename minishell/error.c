#include <stdio.h>
#include "c.h"

void    print_error_exit(t_error error)
{
    if (error == quote)
        write(1, "quote is not closed\n", 20);
    else if (error == parentheses)
        write(1, "parentheses is not closed\n", 26);
    exit(1);
}

void    system_error_exit(void)
{
    perror("Error : ");// 확인해서 바꿔주기
    exit(errno); // 전역 변수 아니고 perror 에서 출력될거를 받아와서 숫자 찾아도 되긴 할 듯
}
