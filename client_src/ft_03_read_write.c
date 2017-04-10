/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_01_read_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:47:20 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/18 14:47:21 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			ft_receive(t_set *set)
{
	char		*buffer;

	buffer = ft_strnew(READ_BUF_SIZE);
	set->ret_read = read(set->fd_socket, buffer, READ_BUF_SIZE - 1);
	if (set->ret_read < 0)
		ft_exit_error(set, ERR_READING_SOCKET);
	ft_printf("%s\n", buffer);
	free(buffer);
	buffer = NULL;
}

void			ft_send(t_set *set)
{
	ft_printf("write the message: ");
	ft_get_message(set);
	ft_check_command(set);
	set->ret_write = write(set->fd_socket, set->buf, strlen(set->buf));
	if (set->ret_write < 0)
		ft_exit_error(set, ERR_WRITE_TO_FD);
}
