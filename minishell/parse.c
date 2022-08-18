#include <stdlib.h>
#include "c.h"

void    add_cmd(t_info *info, char *cmd)
{
    t_cmd   *new_cmd;
    t_cmd   *temp;

    new_cmd = init_cmd(info->env);
    if (info->first_cmd == NULL)
        info->first_cmd = new_cmd;
    else
    {
        temp = info->first_cmd;
        while (temp->next_cmd != NULL)
            temp = temp->next_cmd;
        temp->next_cmd =new_cmd;
    }
}

char    *split_to_space(char *input)
{
    int i;
    char *word;

    i = 0;
    while (input[i] != ' ' && input[i] != '\0')
        i++;
    word = malloc(sizeof(char) * i + 1);
    if (word == NULL)
        system_error_exit();
    word[i] = '\0';
    while(--i >= 0)
        word[i] = input[i];
    return (word);
}

// int ft_isprint(char c) //
// {
//     if (32 <= c && c <= 126)
//         return (TRUE);
//     else
//         return (FALSE);
// }

int get_token_cnt(char *input)
{
    int cnt;
    int i;

    if (input == NULL || input[0] == '\0')
        return (0);
    i = -1;
    cnt = 0;
    while (input[++i])
    {
        while (input[i] == ' ')
            i++;
        if (input[i] == '\0')
            break ;
        else if (input[i] == '(')
            i += parentheses_pair_long(&(input[i]));
        else
        {
            while (input[i] != '|'  && input[i] != '\0')
                i++;
            if (input[i] == '\0')
                i--;
        }
        cnt++;
    }
    return (cnt);
}

char    *split_input(char *input, int len)
{
    char    *new;
    int     i;

    new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
        system_error_exit();
    i = -1;
    while (++i < len)
        new[i] = input[i];
    new[i] = '\0';
    return (new);
}

void    input_to_token(char *input, char **token, int token_cnt)
{
    int i;
    int len;
    int token_idx;

    i = -1;
    token_idx = -1;
    while (input[++i])
    {
        len = 0;
        while (input[i] == ' ')// 다음 함수에서 처리해줘도 됨
            i++;
        if (input[i] == '(')
            len = parentheses_pair_long(&input[i]);
        while (input[i + len] != '(' && input[i + len] != '\0')
        {
            len++;
            if ((i > 1 && input[i + len] == '&' && input[i + len - 1] == '&') \
            || (i > 1 && input[i + len] == '|' && input[i + len - 1] == '|') \
            || (input[i + len] == '|' && input[i + len + 1] != '|'))
                break ;
        }
        token[++token_idx] = split_input(&input[i], len);
        i += len - 1;
    }
    token[token_cnt] = NULL;
}

int get_argc_cnt(char *token)
{
    int cnt;
    int i;

    if (token == NULL || token[0] == '\0')
        return (0);
    i = -1;
    cnt = 0;
    while (token[++i])
    {
        if (token[i] == '\'' || token[i] == '\"')
            i += quote_pair_long(&(token[i]));
        else
        {
            while (token[i] != ' ' && token[i] != '\0')
                i++;
        }
        while (token[i] == ' ' && token[i] != '\0')
            i++;
        cnt++;
    }
    return (cnt);
}

int get_argv_len(char *token)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (token[i] != ' ' && token[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}

char    *duple_word(char *token, int len)
{
    char    *word;
    int i;

    word = malloc(sizeof(char) * (len + 1));
    if (word == NULL)
        system_error_exit();
    i = -1;
    while (++i < len)
        word[i] = token[i];
    word[i] = '\0';
    return (word);
}

char    **split_token(char *token, int cnt)
{
    char **argv;
    int argv_idx;
    int i;
    int argv_len;

    argv = malloc(sizeof(char *) * (cnt + 1));
    if (argv == NULL)
        system_error_exit();
    i = 0;
    argv_idx = 0;
    while (token[i])
    {
        if (token[i] == '\'' || token[i] == '\"')
            argv_len = quote_pair_long(&(token[i]));
        else
            argv_len = get_argv_len(&token[i]);
        argv[argv_idx++] = duple_word(&token[i], argv_len);
        i += argv_len;
        while (token[i] == ' ')
            i++;
    }
    argv[argv_idx] = NULL;
    return (argv);
}

void    token_to_argv(char *token, t_info *info, int idx)
{
    t_cmd   *cmd;

    cmd = info->first_cmd;
    while (cmd->cmd_num != idx)
        cmd = cmd->next_cmd;
    cmd->argc = get_argc_cnt(token);
    cmd->argv = split_token(token, cmd->argc);//
}


char *token_trim(char *token, char *set)
{
    char    *del;

    del = token;
    token = ft_strtrim(token, set);
    if (token == NULL)
        system_error_exit();
    free(del);
    return (token);
}

int is_rdr(char *argv)// 확인 다시하기
{
    if (!ft_strncmp(argv, ">", 2) || !ft_strncmp(argv, "<", 2) || \
    !ft_strncmp(argv, ">>", 3) || !ft_strncmp(argv, "<<", 3))
        return (TRUE);
    else
        return (FALSE);
}

void    pull_two_argv(char **argv, int cnt)
{
    int i;

    i = -1;
    while (++i < cnt - 2)
        argv[i] = argv[i + 2];
    argv[i] = NULL;
}

void    extract_rdr(t_info *info, int idx)
{
    t_cmd *cmd;
    t_rdr *rdr;
    int i;

    cmd = info->first_cmd;
    while (cmd->cmd_num != idx)
        cmd = cmd->next_cmd;
    i = -1;
    while (++i < cmd->argc)
    {
        // argv 를 돌면서 > 가 있는지 찾음
        if (is_rdr(cmd->argv[i]))
        {
            // 해당 argv와 다음거(file name)을 rdr로 빼냄
            add_new_rdr_node(cmd, cmd->argv[i], cmd->argv[i + 1]);
            // argv에서 위 두개 없애줘
            pull_two_argv(&(cmd->argv[i]), cmd->argc - i - 1);
            i++;
        }
    }
}

void    set_cmd(t_info *info, int idx)
{
    t_cmd   *cmd;

    cmd = info->first_cmd;
    while (cmd->cmd_num != idx)
        cmd = cmd->next_cmd;
    cmd->cmd = ft_strdup(cmd->argv[0]);
    if (cmd->cmd == NULL)
        system_error_exit();
}

void parsing(t_info *info)
{
    //char **token 만들기 (개수 세고 쪼개기)
    char    **token;
    int     token_cnt;
    int     i;

    token_cnt = get_token_cnt(info->input);
    token = malloc(sizeof(char *) * token_cnt + 1);
    if (token == NULL)
        system_error_exit();
    input_to_token(info->input, token, token_cnt);

    // token to word(token, info)
    i = 0;
    while (i < token_cnt)
    {
        // t_cmd 만들어서 info->cmd 에 넣기
        add_new_cmd_node(info);
        // trim(" ") 하기
        token[i] = token_trim(token[i], " ");
        // token을 cmd->argc, argv 에 넣기
        token_to_argv(token[i], info, i);
        // 쭉 돌면서 rdr 찾아서 처리하고 나머지 문자들만 남기기
        extract_rdr(info, i);
        // 남은 것 중 가장 첫 단어가 cmd (cmd도 argv 에 남기기. execve 에 그대로 써도돼)
        set_cmd(info, i);
        // if (i > 0)
        //     set_bridge(info, i);
        i++;
    }
}

int main(int argc, char **argv, char **env)
{
    char *str = "   echo  abc > file    |  cat file1";
    t_info *info = init_info(env, str);
    parsing(info);
    sleep(1);
}

// int parsing(t_info *info)
// {
//     int i;
//     char    *word;

//     i = -1;
//     while (info->input[++i])
//     {
//         while (info->input[i] == ' ')
//             i++;
//         if (info->input[i] == '(')
//             i += parentheses_pair_long(&info->input[i]);
//         else if (info->input[i] == '\'' || info->input[i] == '\"')
//             i += quote_pair_long(&info->input[i]);
//         else if (ft_isprint(info->input[i]))
//         {
//             word = split_to_space(&(info->input[i]));
//             // 단어로 쪼개기
//             // < | && || 인지  영단어 인지 확인

//             // 길이만큼 복사
//         }
//     }
// }



/// rdr 띄어쓰기 없을때 만들어주기
