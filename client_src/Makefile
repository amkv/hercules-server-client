# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 14:47:24 by akalmyko          #+#    #+#              #
#    Updated: 2017/02/18 19:13:28 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run

NAME = client
CC = gcc
RM = /bin/rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT_F = ../libft/
LIBFT_L = libft.a
CFILES = main.c
CFILES += ft_01_set_arguments.c
CFILES += ft_02_connection.c
CFILES += ft_03_read_write.c
CFILES += ft_04_message.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(LIBFT_F)$(LIBFT_L) ]; then \
		make -C $(LIBFT_F); \
	fi
	@$(CC) $(CFLAGS) -c $(CFILES)
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT_F)$(LIBFT_L) -o $(NAME)
	@echo "$(NAME) compiled"

clean:
	@$(RM) $(OFILES)
	@echo "$(NAME) cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) fcleaned"

re: fclean all
