#ifndef MINISHELL_H
#define MINISHELL_H

typedef enum e_rdr_type
{
    left,
    right,
    append,
    heredoc
} t_rdr_type;

typedef struct s_cmd
{
    char    *cmd;
    char    *parm;
    t_rdr   *next_rdr;
    t_cmd   *next_cmd;
} t_cmd;

typedef struct s_rdr
{
    t_rdr_type  type;
    char        *word;
    t_rdr       *next;
} t_rdr;



#endif
