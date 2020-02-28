/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   untilsiso.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 23:23:12 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 04:52:09 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_node	**set_xy_iso(t_node **node, t_map map)
{
	int i;
	int j;

	i = 0;
	while (i < map.sizey)
	{
		j = 1;
		while (j < (map.sizex))
		{
			node[i][j].x = node[i][j - 1].x + map.df_gapx;
			node[i][j].y = node[i][j - 1].y + map.df_gapy;
			j++;
		}
		i++;
		if (i < map.sizey)
		{
			node[i][0].x = node[i - 1][0].x - map.df_gapx;
			node[i][0].y = node[i - 1][0].y + map.df_gapy;
		}
	}
	return (node);
}

t_node	**set_z_iso(t_node **node, t_map map)
{
	int i;
	int j;

	i = 0;
	while (i < map.sizey)
	{
		j = 0;
		while (j < (map.sizex))
		{
			node[i][j].z = map.tab[i][j];
			node[i][j].y -= (float)node[i][j].z * 0.2 * (float)map.df_gapy *
				(1 + map.move_z);
			j++;
		}
		i++;
	}
	return (node);
}

t_node	**isometrie(t_map *map, t_node **node, t_ma *master)
{
	t_win_map	win_map;
	int			origine[2];

	map_iso(map, &win_map, master, 10);
	origine[0] = win_map.df_start_posx + map->move_x;
	origine[1] = win_map.df_start_posy + map->move_y;
	node[0][0].x = origine[0];
	node[0][0].y = origine[1];
	node = set_xy_iso(node, *map);
	node = set_z_iso(node, *map);
	return (node);
}
