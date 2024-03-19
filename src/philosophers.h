/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:21:22 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/19 12:02:14 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int		dead_flag;
	
}				t_data;

/*--- CHECK ---*/
int	check_argv(char **argv, int argc, int i, int j);

/*--- UTILS ---*/
int	ft_atoi(char *str);

#endif
