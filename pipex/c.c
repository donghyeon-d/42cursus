#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "c.h"
// a.out file1 cmd cmd file2

extern char **environ;


int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	result[s1_len + s2_len] = '\0';
	i = -1;
	while (((char *)s1)[++i])
		result[i] = ((char *)s1)[i];
	i = -1;
	while (((char *)s2)[++i])
		result[i + s1_len] = ((char *)s2)[i];
	return (result);
}

void	print_error_exit(void)
{
    perror(NULL);
    exit(1);
}

int	command_check(char *command)
{
	char	*str;

    if (command == NULL)
        return (FALSE);
	str = "/usr/bin/";
	str = ft_strjoin(str, command);
    if (access(str, X_OK) == -1)
    {
        free(str);
        // print_error_exit();
        return (FALSE);
    }
    free(str);
    return (TRUE);
}

int	infile_check(char *filename)
{
    int fd;

    if (filename == NULL)
        return (FALSE);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        // print_error_exit();
        return (FALSE);
    }
    else
    {
        close(fd);
        return (TRUE);
    }
}

void arg_check(int argc, char *argv[])
{
    int i;

	if (argc != 5)
    {
        printf("argc != 5\n");
		exit(1);
    }
    if (infile_check(argv[1]) == FALSE || argv[argc - 1] == NULL)
    {
        printf("first or last argv is not a file\n");
        exit(1);
    }
    i = 1;
    while (++i < argc - 1)
    {
        if (command_check(argv[i]) == FALSE)
        {
            printf("command error!\n");
            exit(1);
        }
    }
}

// void	execute_cmd(t_info *info, char *cmd)//cmd랑 parm 만 받으면 될듯. pipe_fd는 여기 안에서 정적으로 만들기
// {
// 	// ㅅㅣㄹ해ㅇ해서 결결과과를  temp에 저장
// 	pid_t	pid;
// 	int		fd;
// 	char	*cmd_file;
// 	char	**ar;
// 		char str[10];

// 	unlink("./parm.temp");
// 	pipe(info->pipe);
// 	ar = malloc(sizeof(char *) * 3);
// 	ar[0] = "echo";
// 	ar[1] = info->infile;
// 	ar[2] = NULL;
// 	fd = open("./parm.temp", O_RDWR | O_CREAT);
// 	if (fd == -1)
// 		print_error_exit();
// 	cmd_file = ft_strjoin("/bin/", cmd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2(info->pipe[1], 1);
// 		dup2(info->pipe[1], 2);
// 		execve(cmd_file, ar, environ);
// 	}
// 	else if (pid > 0)
// 	{
// 		waitpid(pid, NULL, 0);
// 		int a = read(info->pipe[0], str, 2);
// 		write(fd, str, 2);
// 		// while (write(fd, str, 1) == 1)
// 		// 	read(info->pipe[0], str, 1);
// 		close(fd);
// 	}
// 	free(cmd_file);
// 	fd = open("./parm.temp", O_RDWR);
// 	read(fd, str, 2);
// 		write(1, str, 2);
// 	// while (read(fd, str, 1) == 1)
// 	// 	write(1, str, 1);
// 	close(fd);
// 	// sleep(1);
// 	unlink("./parm.temp");
// }


void	execute_cmd(t_info *info, char *cmd, char **parm)//cmd랑 parm 만 받으면 될듯. pipe_fd는 여기 안에서 정적으로 만들기
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(cmd, parm, environ);
	else if (pid > 0)
	{
		if (waitpid(pid, NULL, 0) < 0)
			print_error_exit();
	}
	else
		print_error_exit();
}

void	execute_cmd_next(t_info *info, char *cmd, char **parm)//cmd랑 parm 만 받으면 될듯. pipe_fd는 여기 안에서 정적으로 만들기
{
	pid_t	pid;
	int		p[2];
	int		fd;

	unlink(info->out_file);//
	pipe(p);
	fd = open(info->out_file, O_RDWR | O_CREAT);
	if (fd == -1)
		print_error_exit();
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		dup2(p[1], 2);
		execve(cmd, parm, environ);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);//실패시 else if 조건으로 올려도 될듯
		from_pipe_to_outfile(p, fd);
		if (close(fd) < 0)
			print_error_exit();
	}
	else
		print_error_exit();
}

void	from_pipe_to_outfile(int p[2], int fd)
{
	int		n;
	char	str[1];

	n = read(p[0], str, 1);
	while (n > 0)
	{
		if (write(fd, str, 1) < 0)
			print_error_exit();
		n = read(p[0], str, 1);
	}
	if (n < 0)
		print_error_exit();
}


char *get_pipe_argv(char cmd_right, char *outfil)
{
	char	*str;
	int		len;

	write(1, "\npipe> ", 7);
	str = get_next_line(0);
	while (*str == '\n')
	{
		write(1, "\npipe> ", 7);
		str = get_next_line(0);
	}
	len = ft_strlen(str);
	str[len - 1] = '\0';
}

void    pipe_line(t_info *info, char *outfile_left, char *cmd_right)
{
	char	*ar[3];
	pid_t pid;

	if (outfile_left == NULL)
		// print (zsh: parse error near `|')
		exit(1);
	if (cmd_right == NULL) // *cmd_right == '\0'으로 들어오나?
		cmd_right = get_pipe_command();
	ar[0] = cmd_right;
	ar[1] = outfile_left;
	ar[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve(cmd_right, ar, environ);
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
		print_error_exit();
}

void    pipe_line_next(t_info *info, char *outfile_left, char *cmd_right)
{
	int	p[2];
	int	fd;
	char	*ar[3];
	pid_t pid;

	if (outfile_left == NULL)
		// print (zsh: parse error near `|')
		exit(1);
	if (cmd_right == NULL) // *cmd_right == '\0'으로 들어오나?
		cmd_right = get_pipe_command();
	ar[0] = cmd_right;
	ar[1] = outfile_left;
	ar[2] = NULL;
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		dup2(p[1], 2);
		execve(cmd_right, ar, environ);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		unlink(info->out_file);
		fd = open(info->out_file, O_RDWR | O_CREAT);
		from_pipe_to_outfile(p, fd);
		if (close(fd) < 0)
			print_error_exit();
	}
	else
		print_error_exit();
}

void    form_outfile_to_pipe(int p[2], int fd);

void	redirect_to_left(t_info *info, char *parm_left, char *cmd_right, int next_flag)
{
	char	*ar[3];
	pid_t	pid;

	if (parm_left == NULL)

	ar[0] = cmd_right;
	ar[1] = parm_left;
	ar[2] = NULL;
	pid = fork();
	if (parm_left == NULL)

	else if (pid == 0)
	{
		if (next_flag)
			pipe_cmd(info, cmd_right, ar);
		else
			execve(cmd_right, ar, environ);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
		print_error_exit();
}

void	from_file_to_file(int from_fd, int to_fd) // gnl로 받아야되나
{
	int		n;
	char	*str;

	str = get_next_line(from_fd); // gnl 안에서 errno(exit) 설정 필요
	n = ft_strlen(str);
	while (str != NULL)
	{
		if (write(to_fd, str, n) < 0)
			print_error_exit();
		free(str);
		str = get_next_line(from_fd);
		n = ft_strlen(str);
	}
}

// void	from_file_to_file(int from_fd, int to_fd) // gnl로 받아야되나
// {
// 	int		n;
// 	char	str[1];

// 	n = read(from_fd, str, 1);
// 	while (n > 0)
// 	{
// 		if (write(to_fd, str, 1) < 0)
// 			print_error_exit();
// 		n = read(from_fd, str, 1);
// 	}
// 	if (n < 0)
// 		print_error_exit();
// }

// pipe한다음에 outfile을 파일로 저장해줌
void	redirect_to_right(t_info *info, char *pipefile_left, char *file_right)
{
	int	from_fd;
	int	to_fd;

	if (file_right == NULL) // zsh: parse error near `\n'
		exit(0);
	if (pipefile_left == NULL)
		from_fd = 1;
	else
		from_fd = open(pipefile_left, O_RDWR);
	to_fd = open(file_right, O_RDWR | O_CREAT);
	if (to_fd < 0 || from_fd < 0)
		print_error_exit();
	from_file_to_file(from_fd, to_fd);
}


int main(int argc, char *argv[])
{
	int i;
    t_info *info;

	i = 0;
    info = malloc(sizeof(t_info));
    if (info == NULL)
        exit(0);
	// arg_check(argc, argv);
    info->infile = argv[1];
	info->out_file = argv[3];
	execute_cmd(info, argv[2]);
	// execve("/bin/cat", argv, environ);
}
