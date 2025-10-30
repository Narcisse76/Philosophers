/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:51:57 by narcisse          #+#    #+#             */
/*   Updated: 2025/10/28 19:15:43 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

/*
number_of_philosophers, time_to_die time_to_eat, time_to_sleep, 
[number_of_times_each_philosopher_must_eat]

• Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

# define DEBUG_MOD 0

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mutex		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		nb_meal;
	bool		full;
	long		last_meal;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mutex		philo_mutex;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long		philo_nb;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nb_limit_meal;
	long		start_time;
	bool		end_simulation;
	bool		all_threads_ready;
	long		threads_running_nbr;
	pthread_t	monitor;
	t_mutex		table_mutex;
	t_mutex		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
}				t_table;

void		dinner_start(t_table *table);
void		clean(t_table *table);
void		thinking(t_philo *philo, bool pre_simulation);
void		write_status(t_philo_status status, t_philo *philo, bool debug);
void		parse_input(t_table *table, char **argv);
void		error_exit(const char *error);
long		gettime(t_time_code time_code);
void		precise_usleep(long usec, t_table *table);
void		*monitor_dinner(void *data);
void		wait_all_threads(t_table *table);
bool		all_threads_running(t_mutex *mutex, long *threads, long philo_nbr);
void		increase_long(t_mutex *mutex, long *value);
void		safe_thread_handle(pthread_t *thread, void *(*foo) (void *),
				void *data, t_opcode opcode);
void		safe_mutex_handle(t_mutex *mutex, t_opcode opcode);
void		*safe_malloc(size_t	bytes);
void		de_synchronize_philos(t_philo *philo);
void		data_init(t_table *table);
bool		simulation_finished(t_table *table);
long		get_long(t_mutex *mutex, long *value);
void		set_long(t_mutex *mutex, long *dest, long value);
bool		get_bool(t_mutex *mutex, bool *value);
void		set_bool(t_mutex *mutex, bool *dest, bool value);
bool		ft_isdigit(char c);

#endif
