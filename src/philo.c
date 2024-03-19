/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:27:20 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/19 12:07:15 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* static void	init_struct(t_data *d, char **argv)
{
	d->dead_flag = 0;
} */

int	main(int argc, char **argv)
{
	t_data	*d;

	if (check_argv(argv, argc, 1, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	d = malloc(sizeof(t_data *));
	//init_struct(d, argv);
}
