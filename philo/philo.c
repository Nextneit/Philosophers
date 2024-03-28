/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:27:20 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/28 16:52:24 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void ft_leaks(void)
{
	system("leaks -q philo");
}atexit(ft_leaks); */

static void	init_struct(t_data *d, t_philo *philos)
{
	d->dead_flag = 0;
	d->philos = philos;
	pthread_mutex_init(&d->dead_lock, NULL);
	pthread_mutex_init(&d->write_lock, NULL);
	pthread_mutex_init(&d->meal_lock, NULL);
}

int	main(int argc, char **argv)
{
	t_data			*d;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (check_argv(argv, argc, 1, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	d = malloc(sizeof(t_data *));
	init_struct(d, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, d, forks, argv);
	init_thread(d, forks, ft_atoi(argv[1]));
	destroy_thread(NULL, d, forks);
	return (EXIT_SUCCESS);
}
