# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 10:48:05 by ncruz-ga          #+#    #+#              #
#    Updated: 2024/03/19 14:34:46 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra

PHILO = philo.a

SRCS = src/philo.c\
		src/check_argv.c\
		src/philo_utils.c\
		src/init_program.c\

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@ ar rcs $(PHILO) $(OBJS)
			@ gcc $(CFLAGS) $(PHILO) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
				@ gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:			
				@rm -f $(OBJS)

fclean:			
				@rm -f $(NAME) $(OBJS) $(PHILO)

re: fclean all

.PHONY: all re fclean clean