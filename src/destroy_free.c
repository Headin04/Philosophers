#include "philo.h"

int	join_thread(t_main *main)
{
	size_t i;

	i = 0;
	while (i < main->param.nb_philo)
	{
		if (pthread_join(main->philo[i].mutex, NULL) != 0)
			return (1);
		printf("trade %zu has finished\n", i);
		i++;
	}
	return (0);
}