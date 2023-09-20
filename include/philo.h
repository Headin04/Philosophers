/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:00:22 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/09/20 17:01:00 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <curses.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_thread
{
	pthread_t		*philo;
	pthread_mutex_t	mutex;
}					t_thread;

typedef struct s_param
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_end;
	size_t			alive;
}					t_param;

typedef struct s_fork
{
	size_t			left;
	size_t			right;
}					t_fork;

typedef struct s_philo
{
	size_t			id;
	size_t			nb_of_eat;
	size_t			last_eat;
	size_t			start_eat;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	count_mutex;
	t_fork			fork;
	pthread_t		mutex;
}					t_philo;

typedef struct s_main
{
	int				current_id;
	t_param			param;
	t_philo			*philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	currentid_mutex;
}					t_main;

/*HANDLE_TIME*/
size_t				get_the_time(void);

/*MAIN*/
int					initialize(t_main *main, int argc, char **argv);
int					handling_errors(int argc, char **argv);
void				initialize_param(t_main *philo, int argc, char **argv);
int					f_philo(t_main *main);
void				*routine(void *args);
int					create_thread(t_main *main);
int					join_thread(t_main *main);

/*UTILS*/
int					check_numbers(char **argv);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);

#endif