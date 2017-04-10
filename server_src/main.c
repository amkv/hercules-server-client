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

void			ft_show_usage(t_set *set)
{
	ft_printf(WHT"usage:"CLN"\t./hydra <flag> <port>\n\n");
	ft_printf("\t<flag> "WHT"-D"CLN"\t\trun as daemon\n");
	ft_printf("\t<flag> "WHT"-I"CLN"\t\tshow extra info\n");
	ft_printf("\t<port>\t\t\trange "WHT"1-65535\n"CLN);
	if (set)
		free(set);
	exit(FAILURE);
}

static void		ft_free_set(t_set *set)
{
	if (set->buf)
		free(set->buf);
	free(set);
}

int				main(int argc, char *argv[])
{
	t_set		*set;

	if (argc <= 1 || argc >= 4)
		ft_show_usage(NULL);
	set = ft_set_arguments(argc, argv, NULL);
	ft_run_the_server(set);
	ft_free_set(set);
	return (SUCCESS);
}
