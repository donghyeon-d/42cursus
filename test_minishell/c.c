#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #include <readline.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "c.h"

t_info *init_info(char *env[])
{
    t_info *new;

    //할당
    // get shell level
    // pointer membet = NULL;
    //return (new);
}


int get_shlvl(char **env)
{
    int i;
    int lvl;
    char *temp;

    i = -1;
    while(ft_strncmp(env[++i], "SHLVL=", 6))
        i++;
    if (env[i] == NULL) // SHLVL 을 못찾았을 때 처리
        return (-1);
    temp = env[i];
    lvl = ft_atoi(&temp[6]);
    return (lvl)
}

int main(int argc, char *argv[], char *env[])
{
    char *cmd;
    char *temp;
    //signal setting

        printf("\n!!%d\n", lvl);

    // while (1)
    // {
    //     cmd = readline("bash-3.2$ ");
    //     printf("%s\n",cmd);
    //     // parsing(cmd)
    //     // expanding
    //     // excute
    //     // system("leaks")
    //     free(cmd);
    // }
    // // read
}

// 전체 반복
// 1. readline
// 2. parsing
// 3. expanding
// 4. execute
// free(readline)

// 명령어 읽고나서 순서 (1,2 번 순서 맞는지 확인)
// 1. () 단위로 쪼개주기
// 2. | 파이프 단위로 쪼개주기 (cmd->next_cmd != NULL ->  subshell = true)
// 3. > 단위로 쪼개주기
// 4. cmd->argv expand *, ${ENV}

// 실행하기
// 1. builtin 인지 bash cmd인지 분기
// 2. subshell == true 인지 아닌지로 나눠줌
// 3. redirect 설정 해주기
// 4. 명령어 존재하는건지 탐색해보기
// 5. 첫번째 인자에 -(옵션) 있는지 확인하기
// 6. 명령어에 인자 넣으면서 실행하기
// 7. pipe 있으면 계속 해주기
