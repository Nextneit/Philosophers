# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 10:48:05 by ncruz-ga          #+#    #+#              #
#    Updated: 2024/03/18 10:51:56 by ncruz-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

PHILOSOPHERS = philosophers.a

LIB = ar rcs

SRCS = ./src/check_argv.c\


OBJS = $(SRCS:.c=.o)

$(NAME):		$(OBJS)
					@$(LIB) $(PHILOSOPHERS) $(OBJS)
					@$(CC) $(CFLAGS) $(PHILOSOPHERS) -o $(NAME)

$(OBJS):		src/%.o : src/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:			
				@rm -f $(OBJS)

fclean:			
				@rm -f $(NAME) $(OBJS) $(PHILOSOPHERS)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean