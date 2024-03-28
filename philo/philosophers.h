/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:21:22 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/03/28 12:17:29 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				nbr_philos;
	int				nbr_time_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}				t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}				t_data;

/*--- INIT ---*/
void	init_forks(pthread_mutex_t *forks, int nbr);
int		init_thread(t_data *d, pthread_mutex_t *f, int nbr);
void	init_philos(t_philo *philos, t_data *d, pthread_mutex_t *f,
			char **argv);

/*--- ROUTINE ---*/
void	*routine(void *philo);
int		dead_loop(t_philo *philo);
void	think(t_philo *philo);
void	sleeping(t_philo *philo);
void	eat(t_philo *philo);

/*--- OBSERVER ---*/
void	*observer(void *monitor);

/*--- CHECK ---*/
int		check_argv(char **argv, int argc, int i, int j);

/*--- UTILS ---*/
int		ft_atoi(char *str);
size_t	get_time(void);
void	print_msg(char *str, t_philo *p, int id);
int		ft_usleep(size_t ms);
void	destroy_thread(char *msg, t_data *d, pthread_mutex_t *f);

#endif
