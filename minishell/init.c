#include "c.h"
#include <stdlib.h>

// input
t_info *init_info(char *env[], char *input)
{
    t_info  *new_info;

    new_info = malloc(sizeof(t_info));
    if (new_info == NULL)
        system_error_exit();
    new_info->input = input;
    new_info->env = env;
    new_info->first_cmd = NULL;
    return (new_info);
}

t_cmd *init_cmd(char **env)
{
    t_cmd   *new_cmd;

    new_cmd = malloc(sizeof(t_cmd));
    if (new_cmd == NULL)
        system_error_exit();
    new_cmd->cmd = NULL;
    new_cmd->opt = NULL;
    new_cmd->argc = 0;
    new_cmd->argv = NULL;
    new_cmd->env = env;
    new_cmd->fd_in = 0;
    new_cmd->fd_out = 1;
    new_cmd->fd_err = 2;
    new_cmd->subshell = FALSE;
    new_cmd->exec_flag = TRUE;
    new_cmd->next_cmd = NULL;
    new_cmd->rdr = NULL;
    return (new_cmd);
}

void    add_new_cmd_node(t_info *info)
{
    t_cmd   *new;
    t_cmd   *temp;

    new = init_cmd(info->env);
    new->cmd_num = 0;
    temp = info->first_cmd;
    if (temp == NULL)
        info->first_cmd = new;
    else
    {
        new->cmd_num++;
        while (temp->next_cmd != NULL)
        {
            temp = temp->next_cmd;
            new->cmd_num++;
        }
        temp->next_cmd = new;
    }
    info->cmd_cnt++;
}

t_rdr *init_rdr(char *rdr, char *file)
{
    t_rdr   *new_rdr;

    new_rdr = malloc(sizeof(t_rdr));
    if (new_rdr == NULL)
        system_error_exit();
    new_rdr->rdr = rdr;
    new_rdr->file = file;
    new_rdr->in = 0;
    new_rdr->out = 0;
    new_rdr->out = 0;
    return (new_rdr);
}

void    add_new_rdr_node(t_cmd  *cmd, char *rdr, char *file)
{
    t_rdr   *new;
    t_rdr   *temp;

    new = init_rdr(rdr, file);
    // new 의 in, out, err 바꿔주기
    temp = cmd->rdr;
    if (temp == NULL)
        cmd->rdr = new;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
