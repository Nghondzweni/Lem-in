/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:52:27 by tnghondz          #+#    #+#             */
/*   Updated: 2018/09/09 12:52:28 by tnghondz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		nav_right(t_lem_data *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		nav_right(lem, lst, y, x + 1);
		lst = add_room(lem, lst, x);
		nav_up(lem, lst, y - 1, x);
		nav_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		nav_right(lem, lst, y, x + 1);
	return (0);
}

int		nav_left(t_lem_data *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		nav_left(lem, lst, y, x - 1);
		lst = add_room(lem, lst, x);
		nav_up(lem, lst, y - 1, x);
		nav_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		nav_left(lem, lst, y, x - 1);
	return (0);
}

int		nav_up(t_lem_data *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		nav_up(lem, lst, y - 1, x);
		lst = add_room(lem, lst, y);
		nav_left(lem, lst, y, x - 1);
		nav_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		nav_up(lem, lst, y - 1, x);
	return (0);
}

int		nav_down(t_lem_data *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		nav_down(lem, lst, y + 1, x);
		lst = add_room(lem, lst, y);
		nav_left(lem, lst, y, x - 1);
		nav_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		nav_down(lem, lst, y + 1, x);
	return (0);
}

void	nav(t_lem_data *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	nav_right(lem, tmp, 0, 0);
	free(tmp);
}
