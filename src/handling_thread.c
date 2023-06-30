/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:14:02 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/30 14:56:50 by ode-cleb         ###   ########.fr       */
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

int	create_thread(t_main *main, t_thread *thread)
{
	pthread_t	tmp[main->param.nb_philo];
	size_t		i;
	
	i = 0;
	thread->philo = tmp;
	pthread_mutex_init(&thread->mutex, NULL);
	while (i < main->param.nb_philo)
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

int	join_thread(t_main *main, t_thread *thread)
{
	size_t	i;

	i = 0;
	while (i < main->param.nb_philo)
	{
		if (pthread_join(thread->philo[i], NULL) != 0)
			return (1);
		printf("trade %zu has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&thread->mutex);
	return (0);
}
