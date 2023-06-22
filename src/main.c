/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:52:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/22 14:55:31 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	n = 0;

void	*routine(void *args)
{
	t_thread	*thread;
	thread = (t_thread *)args;
	pthread_mutex_lock(&thread->mutex);
	if ( n != 5)
		n++;
	printf("%i\n", n);
	pthread_mutex_unlock(&thread->mutex);
	return 0;
}

int	create_thread(t_philo *philo, t_thread *thread)
{
	pthread_t	mycki[philo->nb_philo];
	size_t		i;
	
	i = 0;
	thread->philo = mycki;
	pthread_mutex_init(&thread->mutex, NULL);
	while (i < philo->nb_philo)
	{
		if (pthread_create(&thread->philo[i], NULL, &routine, (void *)thread) != 0)
		{
			printf("failed to create thread\n");
			return (1);
		}
		printf("trade %zu has started\n", i);
		i++;
	}
	return (0);
}

int	join_thread(t_philo *philo, t_thread *thread)
{
	size_t	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_join(thread->philo[i], NULL) != 0)
			return (1);
		printf("trade %zu has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&thread->mutex);
	return (0);
}

int	f_philo(t_philo *philo)
{
	t_thread	thread;
	
	create_thread(philo, &thread);
	join_thread(philo, &thread);
	return (0);
}

void	initialize_philo(t_philo *philo, int argc, char **argv)
{
	if (argc == 6)
		philo->must_end = ft_atoi(argv[5]);
	else
		philo->must_end = -1;
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc  != 6 && argc != 5)
	{
		printf("Too much or not enough arguments\n");
		return (0);
	}
	if (check_numbers(argv) == 0)
	{
		printf("wrongs caracters\n");
		return 0;
	}
	initialize_philo(&philo, argc, argv);
	f_philo(&philo);
	printf("all good\n");
	return (1);
}
