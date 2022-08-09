#ifndef C_H
#define C_H

#define FALSE 0
#define TRUE 0

typedef struct s_info{
    int pipe[2];
    char    *tempfile;
    char *infile;
    char    *cmd;
    char *out_file;// = "./parm.temp";
    pid_t child;
}   t_info;

char	*ft_strjoin(char const *s1, char const *s2);

void	print_error_exit(void);

int	command_check(char *command);
int	file_check(char *filename);
void arg_check(int argc, char *argv[]);

/* execute command */ // info->out_file 에 저장됨
void	execute_cmd(t_info *info, char *cmd, char **parm); // 명령어 하나 실행
void	execute_cmd_next(t_info *info, char *cmd, char **parm); // 명령어 하나 실행하고 outfile에 저장
void	from_pipe_to_outfile(int p[2], int fd); //pipe에 들어가있는거 outfile에 저장 (execute_cmd_next 안에 있음)

/* pipe line */
void    pipe_line(t_info *info, char *outfile_left, char *cmd_right, int next_flag); //outfile에 있는거 command로 실행
// void    pipe_line_next(); // outfile에 있는거 command로 실행하고 outfile에 담음

/* redirect to left < */
void	redirect_to_left(t_info *info, char *parm_left, char *cmd_right, int next_flag);

/* redirect to right > */ // pipe 한 결과를 인자로 넣어줌 ㅇㅋㅇㅋ // Gnl perror 확인
void	redirect_to_right(t_info *info, char *pipefile_left, char *file_right, int next_flag);
void	from_file_to_file(int from_fd, int to_fd);

/* >> */
void	append_to_right(t_info *info, char *outfile_left, char *file_right, int next_flag)

/* heer */


char **file_to_parm(char *file, char *cmd);

// void    replace_file(t_info *info, char *file_name);

#endif
