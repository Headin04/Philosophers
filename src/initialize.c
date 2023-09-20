/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:21:10 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/09/20 16:01:24 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_other_mutex(t_main *main)
{
	if (pthread_mutex_init(&main->printf_mutex, NULL) == 0)
		return (FALSE);
	if (pthread_mutex_init(&main->currentid_mutex, NULL) == 0)
		return (FALSE);
	if (pthread_mutex_init(&main->alive_mutex, NULL) == 0)
		return (FALSE);
	return (TRUE);
}

int	initialize_fork(t_main *main)
{
	size_t	i;

	i = 0;
	main->fork_mutex = malloc(sizeof(pthread_mutex_t) * (main->param.nb_philo
			+ 1));
	if (main->fork_mutex == NULL)
		return (FALSE);
	while (i < main->param.nb_philo)
	{
		if (pthread_mutex_init(&main->fork_mutex[i], NULL) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	initialize_param(t_main *main, int argc, char **argv)
{
	if (argc == 6)
		main->param.must_end = ft_atoi(argv[5]);
	else
		main->param.must_end = -1;
	main->param.nb_philo = ft_atoi(argv[1]);
	main->param.time_to_die = ft_atoi(argv[2]);
	main->param.time_to_die = ft_atoi(argv[3]);
	main->param.time_to_sleep = ft_atoi(argv[4]);
}

int	initialize_philo(t_main *main)
{
	size_t	i;

	i = 0;
	main->philo = malloc(sizeof(t_philo) * (main->param.nb_philo + 1));
	if (main->philo == NULL)
		return (FALSE);
	while (i < main->param.nb_philo)
	{
		if (pthread_mutex_init(&main->philo[i].time_mutex, NULL) != 0
			|| pthread_mutex_init(&main->philo[i].count_mutex, NULL) != 0)
			return (FALSE);
		main->philo[i].id = i + 1;
		main->philo[i].nb_of_eat = 0;
		main->philo[i].last_eat = 0;
		main->philo[i].start_eat = 0;
		main->philo[i].fork.left = i;
		main->philo[i].fork.right = i + 1;
		if (main->philo[i].fork.right >= main->param.nb_philo)
			main->philo[i].fork.right = 0;
		i++;
	}
	main->current_id = 0;
	return (TRUE);
}
int	initialize(t_main *main, int argc, char **argv)
{
	initialize_param(main, argc, argv);
	if (initialize_philo(main) == FALSE)
		return (FALSE);
	if (initialize_fork(main) == FALSE)
		return (FALSE);
	if (initialize_other_mutex(main) == FALSE)
		return (FALSE);
	return (TRUE);
}