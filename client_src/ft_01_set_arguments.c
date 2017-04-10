/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_01_set_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:24:08 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/18 16:24:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static t_set	*ft_new_set(void)
{
	t_set	*set;

	set = (t_set*)malloc(sizeof(t_set) * 1);
	set->port = 0;
	set->fd_socket = -1;
	set->ret_read = -1;
	set->quit = -1;
	set->exit = -1;
	set->buf = NULL;
	set->ret_write = -1;
	return (set);
}

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

t_set			*ft_set_arguments(char **argv, t_set *set)
{
	set = ft_new_set();
	set->server = gethostbyname(argv[1]);
	if (set->server == NULL)
		ft_exit_error(set, ERR_HOST_DOES_NOT_EXIST);
	set->port = ft_return_port_number(argv[2], set);
	return (set);
}
