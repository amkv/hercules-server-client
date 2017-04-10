/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_05_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:43:46 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/17 22:43:47 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

void			ft_check_command(t_set *set)
{
	int			(*cmp)(const char *, const char *);

	cmp = &ft_strcmp;
	if (cmp(set->buf, "ping") == 0 || cmp(set->buf, "ping\n") == 0)
		ft_send(set, "pong\npong\n");
	else if (cmp(set->buf, "kill") == 0 || cmp(set->buf, "kill\n") == 0)
	{
		ft_send(set, "for kill the hydra, input password:\n");
		set->password = 1;
		ft_receive(set);
		if (cmp(set->buf, "hydra") == 0 || cmp(set->buf, "hydra\n") == 0)
			set->exit = 1;
		else
		{
			ft_send(set, "wrong password, send command\n");
			set->password = -1;
		}
	}
	else if (cmp(set->buf, "quit") == 0 || cmp(set->buf, "quit\n") == 0)
	{
		ft_send(set, "OK, quit!\n");
		set->quit = 1;
	}
	else
		ft_send(set, "send me \"ping\"!\n");
}
