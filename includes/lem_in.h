/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnghondz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:42:54 by tnghondz          #+#    #+#             */
/*   Updated: 2018/09/09 12:53:28 by tnghondz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_rm
{
	char	*name;
	int		x;
	int		y;
	int		size;
}				t_rm;

typedef struct	s_lem_in
{
	char	**data;
	int		ants;
	t_rm	*rm;
	char	**links;
	int		**map;
	int		rooms;
	int		link;
	int		start;
	int		end;
	char	*lst;
	int		len;
	int		*rmf;
}				t_lem_data;

t_lem_data		*init(void);
void			ft_print_links(t_lem_data *lem);
void			ft_convert_links(t_lem_data *lem);
void			ft_check_match(t_lem_data *lem, char **str, int i, int j);

int				read_data(t_lem_data *lem);
int				ft_store(t_lem_data *lem);
void			order_rooms(t_lem_data *lem);
void			store_room(t_lem_data *lem, char *str);
void			store_ants(t_lem_data *lem, char *str);

int				ft_is_in_list(char *node, char *list);
int				get_list_len(t_lem_data *lem);
char			*add_room(t_lem_data *lem, char *lst, int rm);
int				nav_count(char *lst);

void			nav(t_lem_data *lem);
int				nav_down (t_lem_data *lem, char *lst, int y, int x);
int				nav_up (t_lem_data *lem, char *lst, int y, int x);
int				nav_left (t_lem_data *lem, char *lst, int y, int x);
int				nav_right (t_lem_data *lem, char *lst, int y, int x);

void			sort_rooms(t_lem_data *lem);
void			move_ants(t_lem_data *lem);
void			print_ants(t_lem_data *lem, int ant, int rm);
int				move_rec(t_lem_data *lem, int ant, int rm, int count);

int				error_check(t_lem_data *lem);
void			viz(t_lem_data *lem);
#endif
