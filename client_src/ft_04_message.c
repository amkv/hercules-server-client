/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_03_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:48:03 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/18 14:48:04 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		ft_get_message(t_set *set)
{
	char	*input;

	set->ret_read = 0;
	set->ret_read = get_next_line(STD_IN, &input);
	if (set->ret_read < 0)
		ft_exit_error(set, ERR_READING_STDIN);
	set->buf = ft_strjoin(input, "\n");
	free(input);
	input = NULL;
}

void		ft_check_command(t_set *set)
{
	int		(*cmp)(const char*, const char*);

	cmp = &ft_strcmp;
	if (cmp(set->buf, "quit") == 0 || cmp(set->buf, "quit\n") == 0)
		set->quit = 1;
	else if (cmp(set->buf, "kill") == 0 || cmp(set->buf, "kill\n") == 0)
		set->exit = 1;
}
