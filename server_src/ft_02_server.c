/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_02_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:41:26 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/17 22:41:27 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

void		ft_exit_error(t_set *set, int error)
{
	ft_putstr_fd(RED"ERROR: "CLN, STD_ERROR);
	ft_putstr_fd("(", STD_ERROR);
	ft_putnbr_fd(error, STD_ERROR);
	ft_putstr_fd(") ", STD_ERROR);
	ft_putstr_fd(strerror(errno), STD_ERROR);
	ft_putchar_fd('\n', STD_ERROR);
	close(set->fd_accept);
	close(set->fd_socket);
	free(set);
	exit(error);
}

void		ft_run_the_hydra(t_set *set)
{
	while (set->exit == -1)
	{
		set->quit = -1;
		set->fork_id = fork();
		if (set->fork_id < 0)
			ft_exit_error(set, ERR_FORK);
		ft_listen_socket(set);
		ft_accept_con(set);
		while (set->quit == -1 && set->exit == -1)
			ft_receive(set);
		close(set->fd_accept);
	}
}

void		ft_run_the_server(t_set *set)
{
	ft_open_socket(set);
	ft_bind_socket(set);
	if (set->flag == D_FLAG)
		ft_run_as_daemon(set);
	else
		ft_run_the_hydra(set);
	close(set->fd_accept);
	close(set->fd_socket);
	if (set->flag == I_FLAG)
		ft_printf("turn off the server\n");
}

void		ft_run_as_daemon(t_set *set)
{
	set->fork_id = fork();
	if (set->fork_id < 0)
		ft_exit_error(set, ERR_FORK);
	else if (set->fork_id > 0)
	{
		ft_printf("daemon is LISTENING on port: " WHT"%d"CLN"\n", set->port);
		free(set);
		exit(SUCCESS);
	}
	ft_run_the_hydra(set);
	close(set->fd_accept);
	close(set->fd_socket);
	if (set->flag == I_FLAG)
		ft_printf("turn off the server\n");
}
