# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 10:48:05 by ncruz-ga          #+#    #+#              #
#    Updated: 2024/03/28 12:16:21 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra

PHILO = philo.a

SRCS = philo.c\
		check_argv.c\
		philo_utils.c\
		init_program.c\
		observer.c\
		routine.c\
		destroy_thread.c\
		

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@ ar rcs $(PHILO) $(OBJS)
			@ gcc $(CFLAGS) $(PHILO) -o $(NAME)

$(OBJS):		%.o : %.c
				@ gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:			
				@rm -f $(OBJS)

fclean:			
				@rm -f $(NAME) $(OBJS) $(PHILO)

re: fclean all

.PHONY: all re fclean clean