# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 14:47:05 by akalmyko          #+#    #+#              #
#    Updated: 2017/02/18 17:19:02 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = hydra
NAME_C = client
LIBFTA = libft.a

LIBFT_F = libft/
FOLDER_S = server_src/
FOLDER_C = client_src/

all: 
	@make $(LIBFTA) 
	@make $(NAME_S)
	@make $(NAME_C)

$(LIBFTA):
	@make -C $(LIBFT_F)

$(NAME_S):
	@make -C $(FOLDER_S)

$(NAME_C):
	@make -C $(FOLDER_C)

clean:
	@make -C $(LIBFT_F) clean
	@make -C $(FOLDER_S) clean
	@make -C $(FOLDER_C) clean

fclean: clean
	@make -C $(LIBFT_F) fclean
	@make -C $(FOLDER_S) fclean
	@make -C $(FOLDER_C) fclean

re: fclean all

.PHONY: all clean fclean re $(NAME_S) $(NAME_C) $(LIBFTA)
