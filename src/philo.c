/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:27:20 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/18 10:54:22 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_struct(t_philo *p, char **argv)
{
	p->nbr_philo = atoi(argv[1]);
	p->nbr_to_eat = atoi(argv[3]);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_argv(argv, argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo *));
	init_struct(philo, argv);
}
