/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:52:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/21 17:07:32 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc  == 6 || argc == 5)
	{
		printf("all good\n");
		return (0);
	}
	printf("Too much or not enough arguments\n");
	return (0);
}
