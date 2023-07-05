/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:52:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/30 17:22:57 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_philo(t_main *main)
{
	create_thread(main, &main->thread);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_main	main;	

	if (handling_errors(argc, argv) == 0)
		return (FALSE);
	initialize_param(&main, argc, argv);
	initialize_philo(&main);
	f_philo(&main);
	printf("all good\n");
	free(main.philo);
	return (TRUE);
}
