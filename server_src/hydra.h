/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:19:58 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/16 11:20:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HYDRA_H
# define HYDRA_H

# include "../libft/libft/libft.h"
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <errno.h>
# include <netdb.h>
# define SUCCESS 0
# define FAILURE 1
# define STD_ERROR 2
# define STD_IN 0
# define D_FLAG 'D'
# define I_FLAG 'I'
# define ERR_OPENING_SOCKET 2
# define ERR_BIND_FAILURE 3
# define ERR_LISTEN_FAILURE 4
# define ERR_ACCEPT_FAILURE 5
# define ERR_READING_FROM_SOCKET 6
# define ERR_WRITING_TO_SOCKET 7
# define ERR_FORK 8
# define RED "\e[31m"
# define WHT "\e[1m"
# define CLN "\e[0m"
# define QUEUE 5

typedef struct	s_set
{
	int					argc;
	int					flag;
	int					port;
	int					exit;
	int					quit;
	int					password;
	int					fd_socket;
	int					bind;
	int					listen;
	int					fd_accept;
	ssize_t				ret_read;
	char				*buf;
	ssize_t				ret_write;
	socklen_t			clilen;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	cli_addr;
	struct hostent		*server;
	int					fork_id;
}				t_set;

void			ft_show_usage(t_set *set);
t_set			*ft_set_arguments(int argc, char **arguments, t_set *set);
void			ft_exit_error(t_set *set, int error);
void			ft_open_socket(t_set *set);
void			ft_bind_socket(t_set *set);
void			ft_listen_socket(t_set *set);
void			ft_accept_con(t_set *set);
void			ft_receive(t_set *set);
void			ft_send(t_set *set, char *message);
void			ft_run_the_server(t_set *set);
void			ft_run_as_daemon(t_set *set);
void			ft_check_command(t_set *set);

#endif
