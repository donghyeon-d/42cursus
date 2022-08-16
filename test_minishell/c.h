#ifndef CCC_H
#define CCC_H

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
    char *cmd;
    int argc;
    char **argv;
    char **env;
    int fd_in;// 0으로 초기화, rdr 에 따라 바뀜
    int fd_out;// 1으로 초기화, rdr 에 따라 바뀜
    int fd_err;// 2으로 초기화, rdr 에 따라 바뀜
    int subshell;// () or |
    struct s_cmd *next_cmd;// 단일 cmd 이면 NULL;
    t_rdr *next_rdr; // rdr 없으면 NULL
}   t_cmd;

typedef struct s_info
{
    char *input; // readline
    int shlvl; // env 에서 strncmp(readline, "SHLVL=") 찾아서 atoi
    t_cmd   *first_cmd;
} t_info;


#endif
