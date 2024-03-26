/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:43:43 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/26 12:06:30 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].nbr_philos)
	{
		if (dead_philo(&philo[i], ))
		{
			
		}
		i++;
	}
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
