/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:48:24 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/17 14:48:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		ft_show_usage(t_set *set)
{
	ft_printf(WHT"usage:"CLN"\t./client <address> <port>");
	ft_printf(" [range "WHT"1-65535"CLN"]\n");
	if (set)
		free(set);
	exit(SUCCESS);
}

void		ft_exit_error(t_set *set, int error)
{
	ft_putstr_fd(RED"ERROR: "CLN, STD_ERROR);
	ft_putstr_fd("(", STD_ERROR);
	ft_putnbr_fd(error, STD_ERROR);
	ft_putstr_fd(") ", STD_ERROR);
	ft_putstr_fd(strerror(errno), STD_ERROR);
	ft_putchar_fd('\n', STD_ERROR);
	if (set->buf)
		free(set->buf);
	free(set);
	exit(error);
}

int			main(int argc, char *argv[])
{
	t_set	*set;

	if (argc < 3 || argc > 3)
		ft_show_usage(NULL);
	set = ft_set_arguments(argv, NULL);
	ft_socket(set);
	ft_connect(set);
	while (set->quit == -1)
	{
		ft_send(set);
		if (set->exit == 1)
		{
			ft_receive(set);
			ft_send(set);
			set->quit = 1;
		}
		if (set->quit == -1 && set->exit == -1)
			ft_receive(set);
	}
	return (SUCCESS);
}
