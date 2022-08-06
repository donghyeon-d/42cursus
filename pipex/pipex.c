#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

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
	char const	*str;

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

int	file_check(char *filename)
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
    if (file_check(argv[1]) == FALSE || file_check(argv[argc - 1]) == FALSE)
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

void    pipe_child(t_info *info)
{
    int temp_file;
    char    *str;

    unlink("/tmp/pip_temp_file");
    temp_file = open("/tmp/pipe_temp_file", O_RDWR | O_CREAT);
    close(info->pipe[0]);
    while (read(info->pipe[1], str, 1) == 0)
        write(temp_file, str, 1);
}

void    pipeline(t_info *info, char *filename)
{
    // file 열고
    // pipe 만들고
    // 자식프로세스 만들고
    // pipe 연결해주고
    // 부모에서는 파이프에서 써주고
    // 자식에서는 파이프에서 읽어서 임시 파일에 저장했다가
    // 부모는 자식 끝날때 까지 기다렸다가
    // 자식이 만들었던 임시 파일을 읽어서 fd로 갖고 있어 (모든 파이프 돌아준 다음에 출력하고 임시파일 unlink)
    int fd;
    char str[1];
    pid_t   pid;

    fd = open(filename, O_RDWR);
    pipe(info->pipe);
    pid = fork();
    if (pid == 0)//자식
    {
        pipe_child(info);
        exit(1);
    }
    else if (pid > 0)
    {
        info->child = pid;
        close(info->pipe[1]);
        // dup2(info->pipe[0], fd);
        while (read(fd, str, 1) == 0)
            write(info->pipe[0], str, 1);
        waitpid(info->child, NULL, 0);
        close(fd);
    }
    else
        exit(1);
}



// t_info  *init_info()

int main(int argc, char *argv[])
{
	int i;
    t_info *info;

	i = 0;
    info = malloc(sizeof(t_info));
    if (info == NULL)
        exit(0);
    info->temp_file = NULL;
	arg_check(argc, argv);
	while (++i < argc)
	{
		if (argv[i] == '|')
        {

            pipeline(info, )
        }
		else if (argv[i] == '<')
		else if (argv[i] == '>')
		else if (argv[i] == '<<')
		else if (argv[i] == '>>')
		else
		{

		}
	}
}
