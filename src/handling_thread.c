/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:14:02 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/09/20 16:55:37 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		n = 0;

void	*routine(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	pthread_mutex_lock(&thread->mutex);
	if (n != 5)
		n++;
	printf("%i\n", n);
	pthread_mutex_unlock(&thread->mutex);
	return (0);
}
int	create_thread(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->param.nb_philo)
	{
		pthread_mutex_lock(&main->currentid_mutex);
		main->current_id = i;
		pthread_mutex_unlock(&main->currentid_mutex);
		if (main->philo[i].start_eat == 0)
			main->philo[i].start_eat = get_the_time();
		if (pthread_create(&main->philo[i].mutex, NULL, &routine,
				(void *)main) != 0)
		{
			printf("failed to create thread\n");
			return (FALSE);
		}
		usleep(1000);
		printf("trade %zu has started\n", i);
		i++;
	}
	usleep(1000);
	if (join_thread(main) == FALSE)
		return (FALSE);
	return (TRUE);
}
