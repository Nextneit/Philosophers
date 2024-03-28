/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:46:20 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/28 13:07:25 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	print_msg("is thinking", philo, philo->id);
}

void	sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo, philo->id);
	if (philo->nbr_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), EXIT_FAILURE);
	pthread_mutex_unlock(philo->dead_lock);
	return (EXIT_SUCCESS);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (dead_loop(philo) == EXIT_SUCCESS)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (philo);
}
