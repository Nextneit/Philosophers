/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:45:51 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/19 12:09:11 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_argv(char **argv, int argc, int i, int j)
{
	if (argc < 5 || argc > 6)
		return (printf("Error: Numero de argumentos invalido\n"),
			EXIT_FAILURE);
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_atoi(argv[i]) == 0)
				return (printf("Error: Argumento invalido\n"), EXIT_FAILURE);
			if (is_digit(argv[i][j]) == EXIT_FAILURE)
				return (printf("Error: Argumento invalido\n"),
					EXIT_FAILURE);
			else
				j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return (printf("Error: Numero de filosofos incorrecto\n"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
