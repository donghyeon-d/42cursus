#ifndef PIPEX_H
#define PIPEX_H

#define FALSE 0
#define TRUE 0

typedef struct s_cmd_parm{
    char *parm;
    t_cmd_parm *next;
}   t_cmd_parm;

typedef struct s_list{
    int     curr_count;
    void    *head;
}   t_list;

typedef struct s_cmd_node{
    int     idx;
    pid_t   pid;
    char    *name;
    char    *tempfile;
    t_list  *parm;
    t_cmd_node *next;
}   t_cmd_node;

typedef struct s_cmd{
    int     curr_count;
    t_cmd_node *head;
}   t_cmd;

typedef struct s_info{
    int argc;
    char **argv;
    int idx;
    int pipe[2];
    char *first_file;
    char *temp_file;
    pid_t child;
    t_list *cmd;

}   t_info;

char	*ft_strjoin(char const *s1, char const *s2);

void	print_error_exit(void);

int	command_check(char *command);
int	file_check(char *filename);
void arg_check(int argc, char *argv[]);

void    pipe_child(t_info *info);
void    pipeline(t_info *info, char *filename);

#endif
