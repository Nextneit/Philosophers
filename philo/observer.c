/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:43:43 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/28 14:42:26 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_meal(t_philo *philo)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	if (philo[0].nbr_time_eat == -1)
		return (0);
	while (i < philo[0].nbr_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].nbr_time_eat)
			end++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (end == philo[0].nbr_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	dead_philo(t_philo *philo, size_t time_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_die)
		return (pthread_mutex_unlock(philo->meal_lock), EXIT_FAILURE);
	return (pthread_mutex_unlock(philo->meal_lock), EXIT_SUCCESS);
}

static int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].nbr_philos)
	{
		if (dead_philo(&philo[i], philo[i].time_to_die))
		{
			print_msg("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	*observer(void *monitor)
{
	t_philo	*m;

	m = monitor;
	while (12)
		if (check_dead(m) == 1 || check_meal(m) == 1)
			break ;
	return (monitor);
}
