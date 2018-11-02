/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:21:28 by tnghondz          #+#    #+#             */
/*   Updated: 2018/09/09 12:52:21 by tnghondz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_lem_data(t_lem_data *lem)
{
	read_data(lem);
	ft_store(lem);
	if (error_check(lem))
		exit(0);
	ft_convert_links(lem);
	nav(lem);
	if (!lem->lst)
	{
		ft_putstr("Error : No valid solution\n");
		exit(0);
	}
	sort_rooms(lem);
	ft_print_links(lem);
	write(1, "\n", 1);
	move_ants(lem);
}

void	free_mem(t_lem_data *lem)
{
	int i;

	i = 0;
	free(lem->data);
	free(lem->rm);
	while (lem->links[i])
	{
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->lst);
	free(lem->rmf);
}

int		main(void)
{
	t_lem_data	*lem;

	lem = init();
	ft_lem_data(lem);
	free_mem(lem);
	free(lem);
	return (0);
}
