/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:31:35 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/27 12:35:46 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_thread(char *msg, t_data *d, pthread_mutex_t *f)
{
	int	i;

	i = 0;
	if (msg)
	{
		while (msg[i] != '\0')
		{
			write (1, &msg[i], 1);
			i++;
		}
		write (1, "\n", 1);
	}
	pthread_mutex_destroy(&d->write_lock);
	pthread_mutex_destroy(&d->meal_lock);
	pthread_mutex_destroy(&d->dead_lock);
	i = 0;
	while (i < d->philos[0].nbr_philos)
	{
		pthread_mutex_destroy(&f[i]);
		i++;
	}
}
