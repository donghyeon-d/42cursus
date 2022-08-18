#include <sys/errno.h>
#include <unistd.h>
#include "ft_libft/libft.h"



#ifndef CCC_H
#define CCC_H

extern int errno;

typedef enum e_error
{
    quote = 0,
    parentheses

}   t_error;

typedef struct s_rdr
{
    char *rdr; // &있는지도 확인하기
    char *file; // null 일수도 있음. 존재하지 않는 파일일 수도 있음
    int in; // true/false
    int out; // true/false
    int err; // true/false
    struct s_rdr *next;
}   t_rdr;

typedef struct s_cmd
{
    int cmd_num;
    char *cmd;
    char *opt;
    int argc;
    char **argv;
    char **env;
    int fd_in;// 0으로 초기화, rdr 에 따라 바뀜
    int fd_out;// 1으로 초기화, rdr 에 따라 바뀜
    int fd_err;// 2으로 초기화, rdr 에 따라 바뀜
    int subshell;// () or | default == 0
    int exec_flag; // true/false. default = true,&& || 에 따 라 바뀜
    struct s_cmd *next_cmd;// 단일 cmd 이면 NULL;
    t_rdr *rdr; // rdr 없으면 NULL
}   t_cmd;
// quote
// && ||
// ()
// *
//

typedef struct s_info
{
    char *input; // readline
    int shlvl; // env 에서 strncmp(readline, "SHLVL=") 찾아서 atoi
    char **env;
    t_cmd   *first_cmd;
    int cmd_cnt;
    // pid
} t_info;


//error.c
void    print_error_exit(t_error error);
void    system_error_exit(void);

//paircheck.c
int	parentheses_pair_long(char *input);
int quote_pair_long(char *input);


//init.c
t_info *init_info(char *env[], char *input);
t_cmd *init_cmd(char **env);
t_rdr *init_rdr(char *rdr, char *file);
void    add_new_cmd_node(t_info *info);// cmd를 init해서 info 뒤에 붙임
void    add_new_rdr_node(t_cmd  *cmd, char *rdr, char *file); // rdr을 init 해서 rdr 뒤에 붙임

// // parse.c
// void    add_cmd(t_info *info, char *cmd);
// char    *split_to_space(char *input);
// int ft_isprint(char c);

// int get_token_cnt(char *input);
// char    *split_input(char *input, int len);
// void    input_to_token(char *input, char **token, int token_cnt);
// int parsing(t_info *info);






// 0. input 으로 들어온 것은 char **token 으로 바꿈
int get_token_cnt(char *input); // input을 몇개의 token 으로 쪼갤지 (), | 로만 구분
void    input_to_token(char *input, char **token, int token_cnt); // input을 char **로 옮김

// 1. token 의 맨앞 맨뒤 필요없는 공백 제거
char *token_trim(char *token, char *set); // token의 양쪽의 set을 짤라냄. malloc, free 다 함

// 2. 각 token을 cmd -> argv로 넣어줌
void    token_to_argv(char *token, t_info *info, int idx);
int get_argc_cnt(char *token);
char    **split_token(char *token, int cnt);

// argv 에서 redirect 를 추출해줌
void    extract_rdr(t_info *info, int idx); // argv 에서 rdr을 빼서 t_rdr로
int is_rdr(char *argv);// redirection 인지 아닌지 true/false
void    pull_two_argv(char **argv, int cnt); // argv 에서 rdr을 빼고 그 자리 뒤에꺼로 덮어 씌워줌

// cmd->cmd = argv[0]
void    set_cmd(t_info *info, int idx);

void parsing(t_info *info);





#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
