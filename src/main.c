/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:52:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/09/20 16:53:23 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	f_philo(t_main *main)
// {
// 	create_thread(main);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_main	main;

	if (handling_errors(argc, argv) == 0)
		return (0);
	initialize(&main, argc, argv);
	create_thread(&main);
	printf("all good\n");
	free(main.philo);
	return (1);
}
