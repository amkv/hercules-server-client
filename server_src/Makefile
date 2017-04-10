# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 11:19:28 by akalmyko          #+#    #+#              #
#    Updated: 2017/02/18 19:15:53 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run

NAME = hydra
CC = gcc
RM = /bin/rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT_F = ../libft/
LIBFT_L = libft.a
CFILES = main.c
CFILES += ft_01_set.c
CFILES += ft_02_server.c
CFILES += ft_03_connection.c
CFILES += ft_04_read_write.c
CFILES += ft_05_messages.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(LIBFT_F)$(LIBFT_L) ]; then \
		make -C $(LIBFT_F); \
	fi
	@$(CC) $(CFLAGS) -c $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_F)$(LIBFT_L) -o $(NAME)
	@echo "$(NAME) compiled"

clean:
	@$(RM) $(OFILES)
	@echo "$(NAME) cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) fcleaned"

re: fclean all
