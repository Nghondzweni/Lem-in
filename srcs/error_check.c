/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:52:04 by tnghondz          #+#    #+#             */
/*   Updated: 2018/09/09 12:52:12 by tnghondz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	no_rooms(t_lem_data *lem)
{
	if (lem->rooms <= 0 || lem->rooms > 1000)
	{
		ft_putstr("Error : Invalid rooms\n");
		return (1);
	}
	return (0);
}

int	no_ants(t_lem_data *lem)
{
	if (lem->ants <= 0 || lem->ants > 100)
	{
		ft_putstr("Error : Invalid ants/links\n");
		return (1);
	}
	return (0);
}

int	no_man_comm(t_lem_data *lem)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (lem->data[i])
	{
		if (!ft_strcmp("##start", lem->data[i]) ||
				!ft_strcmp("##end", lem->data[i]))
			flag++;
		i++;
	}
	if (flag < 2)
	{
		ft_putstr("Error : Invalid mandatory commands\n");
		return (1);
	}
	return (0);
}

int	error_check(t_lem_data *lem)
{
	if (no_ants(lem) || no_rooms(lem) || no_man_comm(lem))
		return (1);
	return (0);
}
