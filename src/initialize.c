/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:21:10 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/30 17:24:40 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (0);
	while (i < main->param.nb_philo)
	{
		main->philo[i].id = i + 1;
		main->philo[i].nb_of_eat = 0;
		main->philo[i].time_until_death = main->param.time_to_die;
		// printf("id == %zu\n", main->philo[i].id);
		i++;
	}
	return (1);
}