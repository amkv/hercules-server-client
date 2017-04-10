/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:49:48 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/18 14:49:50 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../libft/libft/libft.h"
# include <errno.h>
# include <netdb.h>
# define SUCCESS 0
# define FAILURE 1
# define STD_ERROR 2
# define STD_IN 0
# define ERR_OPENING_SOCKET 2
# define ERR_CONNECT 3
# define ERR_WRITE_TO_FD 4
# define ERR_READING_SOCKET 5
# define ERR_READING_STDIN 6
# define ERR_HOST_DOES_NOT_EXIST 7
# define RED "\e[31m"
# define WHT "\e[1m"
# define CLN "\e[0m"
# define READ_BUF_SIZE 256

typedef struct	s_set
{
	int					port;
	int					quit;
	int					exit;
	int					fd_socket;
	int					connect;
	ssize_t				ret_read;
	char				*buf;
	ssize_t				ret_write;
	struct sockaddr_in	serv_addr;
	struct hostent		*server;
}				t_set;

void			ft_socket(t_set *set);
void			ft_receive(t_set *set);
void			ft_send(t_set *set);
void			ft_exit_error(t_set *set, int error);
void			ft_connect(t_set *set);
void			ft_get_message(t_set *set);
void			ft_check_command(t_set *set);
void			ft_show_usage(t_set *set);
t_set			*ft_set_arguments(char **argv, t_set *set);

#endif
