/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:00:22 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/22 15:32:53 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_thread
{
    pthread_t       *philo;
    pthread_mutex_t mutex;
}   t_thread;


typedef struct s_philo
{
    size_t  nb_philo;
    size_t  time_to_die;
    size_t  time_to_eat;
    size_t  time_to_sleep;
    size_t  must_end;

}   t_philo;

/*MAIN*/
void	initialize_philo(t_philo *philo, int argc, char **argv);
int	join_thread(t_philo *main, t_thread *thread);

/*UTILS*/
int check_numbers(char **argv);
int ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif