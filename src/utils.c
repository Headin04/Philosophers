/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:18:28 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/22 13:49:19 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_numbers(char **argv)
{
    int i;
    int y;

    i = 1;
    while (argv[i] != NULL)
    {
        y = 0;
        while (argv[i][y] != '\0')
        {   
            if (ft_isdigit(argv[i][y]) == 0)
                return (FALSE);
            y++;
        }
        i++;
    }
    return (TRUE);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	a;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	signe = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (signe * a);
}