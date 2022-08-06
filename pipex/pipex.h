#ifndef PIPEX_H
#define PIPEX_H

#define FALSE 0
#define TRUE 0

typedef struct s_info{
    int idx;
    int pipe[2];
    char *temp_file;
    pid_t child;
}   t_info;

char	*ft_strjoin(char const *s1, char const *s2);

void	print_error_exit(void);

int	command_check(char *command);
int	file_check(char *filename);
void arg_check(int argc, char *argv[]);

void    pipe_child(t_info *info);
void    pipeline(t_info *info, char *filename);

#endif
