/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:03:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/08/02 17:25:48 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	pthread_t	*pth;
	t_status	status;
	int			fork[2];
	int			eat_cnt;
	int			last_eat;
}	t_philo;

typedef struct s_forks{
	pthread_mutex_t	*mutex;
}	t_forks;

typedef struct s_data {
	int				philo_cnt;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				t_id;
	int				end;
	struct timeval	start_time;
	int				time;
	int				start;
	pthread_t		*monitor;
	t_philo			*philo;
	t_forks			*forks;
}	t_data;

t_data	*init_data(int argc, char *argv[]);
int		make_philo(t_data *data);
int		make_forks(t_data *data);
int		make_thread(t_data *data);

void	*pthread_main(void *data);

void	get_forks(t_data *data, int thread_id);
void	start_eating(t_data *data, int thread_id);
void	putdown_forks(t_data *data, int thread_id);
void	start_sleeping(t_data *data, int thread_id);
void	start_thinking(t_data *data, int thread_id);

int		die_check(t_data *data, int thread_id);

void	print_status(t_data *data, t_status status, int thread_id);

int		get_curr_time(struct timeval start_time);
int		put_delay(t_data *data, int delay_time, int thread_id);

int		make_monitor(t_data *data);
void	*monitoring_main(void *data);

int		ft_atoi_positive(char *str);
int		ft_isdigit(char c);

#endif
