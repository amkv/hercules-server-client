/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:02:07 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/16 15:02:45 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

static int		ft_return_port_number(char *argument, t_set *set)
{
	long int	number;
	int			index;

	index = 0;
	while (argument[index] != '\0')
	{
		if (!ft_isdigit(argument[index]))
			ft_show_usage(set);
		index++;
	}
	number = ft_atoi(argument);
	if (number <= 0 || number > 65535)
		ft_show_usage(set);
	return ((int)number);
}

static int		ft_return_flag(char *argument, t_set *set)
{
	if (argument[0] != '-')
		ft_show_usage(set);
	if (argument[1] == 'D')
		return (D_FLAG);
	else if (argument[1] == 'I')
		return (I_FLAG);
	else
		ft_show_usage(set);
	return (-1);
}

static t_set	*ft_new_set(void)
{
	t_set		*set;

	set = (t_set*)malloc(sizeof(t_set) * 1);
	set->argc = 0;
	set->flag = 0;
	set->port = 0;
	set->exit = -1;
	set->quit = -1;
	set->fd_socket = -1;
	set->bind = -1;
	set->listen = -1;
	set->fd_accept = -1;
	set->ret_read = -1;
	set->buf = NULL;
	set->ret_write = -1;
	set->fork_id = -1;
	set->password = -1;
	return (set);
}

t_set			*ft_set_arguments(int argc, char **arguments, t_set *set)
{
	set = ft_new_set();
	if (argc == 2)
	{
		set->port = ft_return_port_number(arguments[1], set);
		set->argc = 1;
	}
	else if (argc == 3)
	{
		set->flag = ft_return_flag(arguments[1], set);
		set->port = ft_return_port_number(arguments[2], set);
		set->argc = 2;
	}
	return (set);
}
