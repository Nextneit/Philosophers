/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:00:50 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/28 12:58:21 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
		printf("gettimeofay() failure\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(char *str, t_philo *p, int id)
{
	size_t	time;

	pthread_mutex_lock(p->write_lock);
	time = get_time() - p->start_time;
	if (!dead_loop(p))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(p->write_lock);
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
	return (EXIT_SUCCESS);
}
