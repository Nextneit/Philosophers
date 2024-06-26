/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:29:11 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/04/01 14:54:23 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_thread(t_data *d, pthread_mutex_t *f, int nbr)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < nbr)
	{
		if (pthread_create(&d->philos[i].thread, NULL, &routine,
				&d->philos[i]) != 0)
			destroy_thread("Thread creation error", d, f);
		i++;
	}
	if (pthread_create(&monitor, NULL, &observer, d->philos) != 0)
		destroy_thread("Thread creation error", d, f);
	if (pthread_join(monitor, NULL) != 0)
		destroy_thread("Thread join error", d, f);
	i = 0;
	while (i < nbr)
	{
		if (pthread_join(d->philos[i].thread, NULL) != 0)
			destroy_thread("Thread join error", d, f);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	init_arg(t_philo *philo, char **argv)
{
	philo->nbr_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philo->nbr_time_eat = ft_atoi(argv[5]);
	else
		philo->nbr_time_eat = -1;
}

void	init_philos(t_philo *philos, t_data *d, pthread_mutex_t *f, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		init_arg(&philos[i], argv);
		philos[i].write_lock = &d->write_lock;
		philos[i].dead_lock = &d->dead_lock;
		philos[i].meal_lock = &d->meal_lock;
		philos[i].dead = &d->dead_flag;
		philos[i].l_fork = &f[i];
		if (i == 0)
			philos[i].r_fork = &f[ft_atoi(argv[1]) - 1];
		else
			philos[i].r_fork = &f[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
