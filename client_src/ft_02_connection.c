/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_01_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:47:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/18 14:47:49 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			ft_socket(t_set *set)
{
	char		*serv_addr;

	serv_addr = (char*)&set->serv_addr.sin_addr.s_addr;
	set->fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (set->fd_socket < 0)
		ft_exit_error(set, ERR_OPENING_SOCKET);
	bzero((char*)&set->serv_addr, sizeof(set->serv_addr));
	set->serv_addr.sin_family = AF_INET;
	bcopy(set->server->h_addr, serv_addr, (size_t)set->server->h_length);
	set->serv_addr.sin_port = htons(set->port);
}

void			ft_connect(t_set *set)
{
	const struct sockaddr	*serv_addr;
	socklen_t				size;

	serv_addr = (struct sockaddr*)&set->serv_addr;
	size = sizeof(set->serv_addr);
	set->connect = connect(set->fd_socket, serv_addr, size);
	if (set->connect < 0)
		ft_exit_error(set, ERR_CONNECT);
	ft_printf("connected.\n");
}
