/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_02_open_socket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:02:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/17 14:02:19 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

void		ft_open_socket(t_set *set)
{
	set->fd_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (set->fd_socket < 0)
		ft_exit_error(set, ERR_OPENING_SOCKET);
	ft_bzero((char*)&set->serv_addr, sizeof(set->serv_addr));
	set->serv_addr.sin_family = PF_INET;
	set->serv_addr.sin_addr.s_addr = INADDR_ANY;
	set->serv_addr.sin_port = htons(set->port);
	if (set->flag == I_FLAG)
	{
		ft_printf("0. port number: "WHT"%d\n"CLN, set->port);
		ft_printf("1. socket() %d:\n", set->fd_socket);
	}
}

void		ft_bind_socket(t_set *set)
{
	set->bind = bind(set->fd_socket,
				(struct sockaddr*)&set->serv_addr, sizeof(set->serv_addr));
	if (set->bind < 0)
		ft_exit_error(set, ERR_BIND_FAILURE);
	if (set->flag == I_FLAG)
		ft_printf("2. bind() %d:\n", set->bind);
}

void		ft_listen_socket(t_set *set)
{
	set->listen = listen(set->fd_socket, QUEUE);
	if (set->listen < 0)
		ft_exit_error(set, ERR_LISTEN_FAILURE);
	if (set->flag == I_FLAG)
		ft_printf("3. listen() %d listening...\n", set->listen);
}

void		ft_accept_con(t_set *set)
{
	set->clilen = sizeof(set->cli_addr);
	set->fd_accept = accept(set->fd_socket,
						(struct sockaddr*)&set->cli_addr, &set->clilen);
	if (set->fd_accept < 0)
		ft_exit_error(set, ERR_ACCEPT_FAILURE);
	if (set->flag == I_FLAG)
		ft_printf("4. accept() %d:\n", set->fd_accept);
}
