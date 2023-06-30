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

int	create_thread(t_philo *main, t_thread *thread)
{
	pthread_t	tmp[main->nb_philo];
	size_t		i;
	
	i = 0;
	thread->philo = tmp;
	pthread_mutex_init(&thread->mutex, NULL);
	while (i < main->nb_philo)
	{
		if (pthread_create(&thread->philo[i], NULL, &routine, (void *)thread) != 0)
		{
			printf("failed to create thread\n");
			return (1);
		}
		printf("trade %zu has started\n", i);
		i++;
	}
	join_thread(main, thread);
	return (0);
}

int	join_thread(t_philo *main, t_thread *thread)
{
	size_t	i;

	i = 0;
	while (i < main->nb_philo)
	{
		if (pthread_join(thread->philo[i], NULL) != 0)
			return (1);
		printf("trade %zu has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&thread->mutex);
	return (0);
}

int	f_philo(t_philo *main)
{
	t_thread	thread;
	
	create_thread(main, &thread);
	return (0);
}

void	initialize_philo(t_philo *main, int argc, char **argv)
{
	if (argc == 6)
		main->must_end = ft_atoi(argv[5]);
	else
		main->must_end = -1;
	main->nb_philo = ft_atoi(argv[1]);
	main->time_to_die = ft_atoi(argv[2]);
	main->time_to_eat = ft_atoi(argv[3]);
	main->time_to_sleep = ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_philo	main;

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
	initialize_philo(&main, argc, argv);
	f_philo(&main);
	printf("all good\n");
	return (1);
}
