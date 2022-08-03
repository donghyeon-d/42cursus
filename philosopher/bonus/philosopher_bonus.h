/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:43:25 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 17:25:34 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define FALSE 0
# define TRUE 1
# define USE 0
# define NOT_USE 1

typedef enum e_status {
	sleeping = 0,
	thinking = 1,
	getting = 2,
	eating = 3,
	forksdown = 4,
	die = -1,
	end = 10
}	t_status;

typedef struct s_philo {
	pid_t		pid;
	pthread_t	pth;
	int			use;
	t_status	status;
	int			eat_cnt;
	int			last_eat;
}	t_philo;

typedef struct s_data {
	int				philo_cnt;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				end;
	struct timeval	start_time;
	int				time;
	int				id;
	pid_t			monitor;
	t_philo			*philo;
	sem_t			*fork;
}	t_data;

t_data	*init_data(int argc, char *argv[]);
int		make_philo(t_data *data);
int		make_forks(t_data *data);

void	*philo_main(t_data *data, int num);

int		die_check(t_data *data, int thread_id);

void	print_status(t_data *data, t_status status, int thread_id);

void	get_forks(t_data *data, int thread_id);
void	start_eating(t_data *data, int thread_id);
void	putdown_forks(t_data *data, int thread_id);
void	start_sleeping(t_data *data, int thread_id);
void	start_thinking(t_data *data, int thread_id);

int		get_curr_time(struct timeval start_time, t_data *data);
int		put_delay(t_data *data, int delay_time, int thread_id);

int		make_monitor(t_data *data);

int		make_process(t_data *data);
int		kill_child(t_data *data);
void	*ps_check(void *data);

int		die_check(t_data *data, int thread_id);

void	print_status(t_data *data, t_status status, int thread_id);

int		ft_atoi_positive(char *str);
int		ft_isdigit(char c);

#endif
