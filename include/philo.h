/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:00:22 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/30 17:22:07 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define FALSE 1
# define TRUE  0

typedef struct s_thread
{
    pthread_t       *philo;
    pthread_mutex_t mutex;
}   t_thread;


typedef struct s_param
{
    size_t          nb_philo;
    size_t          time_to_die;
    size_t          time_to_eat;
    size_t          time_to_sleep;
    size_t          must_end;

}   t_param;

typedef struct s_philo
{
    size_t          id;
    size_t          nb_of_eat;
    size_t          time_until_death;
}   t_philo;

typedef struct s_main
{
    t_param         param;
    t_thread        thread;
    t_philo         *philo;
}   t_main;

/*MAIN*/
int	    f_philo(t_main *main);

/*HANDLING_ERRORS*/
int     handling_errors(int argc, char **argv);

/*INITIALIZE_PHILO*/
void    initialize_param(t_main *philo, int argc, char **argv);
int     initialize_philo(t_main *main);

/*GANDLING_THREAD*/
void	*routine(void *args);
int	    create_thread(t_main *main, t_thread *thread);
int	    join_thread(t_main *main, t_thread *thread);

/*UTILS*/
int     check_numbers(char **argv);
int     ft_isdigit(int c);
int	    ft_atoi(const char *str);

#endif