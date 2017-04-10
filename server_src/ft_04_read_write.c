/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_03_read_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:12:50 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/17 14:12:51 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

static void		ft_delete_non_print_char(t_set *set)
{
	size_t		index;
	size_t		len;

	index = 0;
	len = ft_strlen(set->buf);
	while (ft_isprint(set->buf[index]) == 1)
		index++;
	while (index < len)
	{
		set->buf[index] = '\0';
		index++;
	}
}

void			ft_receive(t_set *set)
{
	set->ret_read = get_next_line(set->fd_accept, &set->buf);
	if (set->ret_read < 0)
		ft_exit_error(set, ERR_READING_FROM_SOCKET);
	ft_delete_non_print_char(set);
	if (set->flag == I_FLAG)
		ft_printf("5. read() %d client: >>%s<<\n", set->ret_read, set->buf);
	if (set->password == -1)
		ft_check_command(set);
}

void			ft_send(t_set *set, char *message)
{
	size_t	len;
	int		ret;

	len = ft_strlen(message);
	if (!message || set->fd_accept < 0 || len == 0)
		ft_exit_error(set, ERR_WRITING_TO_SOCKET);
	ret = (int)write(set->fd_accept, message, len);
	if (ret < 0)
		ft_exit_error(set, ERR_WRITING_TO_SOCKET);
	if (set->flag == I_FLAG)
		ft_printf("6. write() server: >>%s<<\n", message);
}
