/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_cav.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 00:53:03 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 07:23:38 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	range_height(t_map *map, t_win_map *win_map)
{
	int		x;
	int		y;

	y = 0;
	while (y < (int)map->sizey)
	{
		x = 0;
		while (x < map->sizex)
		{
			if (win_map->df_y_min > (y - (float)(map->tab[y][x]) / (10)))
			{
				win_map->df_y_min = (y - (float)(map->tab[y][x]) / (10));
			}
			else if (win_map->df_y_max < (y - (float)(map->tab[y][x]) / (10)))
			{
				win_map->df_y_max = (y - (float)(map->tab[y][x]) / (10));
			}
			x++;
		}
		y++;
	}
	win_map->df_hight_map = win_map->df_y_max - win_map->df_y_min;
}

void	map_cav(t_map *map, t_win_map *win_map, t_ma *master, int marge)
{
	win_map->df_y_min = 0;
	win_map->df_y_max = 0;
	range_height(map, win_map);
	win_map->df_large_map = map->sizex + 0.75 * (float)map->sizey - 1.75;
	win_map->df_sizex_map = WINDOW_LARGE * (100 - 2 * marge) / 100;
	win_map->df_sizey_map = WINDOW_HIGHT * (100 - 2 * marge) / 100;
	if (map->df_gapx == 0 || map->df_gapy == 0)
	{
		map->df_gapx = win_map->df_sizex_map / (win_map->df_large_map);
		map->df_gapy = win_map->df_sizey_map / (win_map->df_hight_map);
		if (map->df_gapy < 0.75 * map->df_gapx)
			map->df_gapx = map->df_gapy / 0.75;
		else
			map->df_gapy = map->df_gapx * 0.75;
	}
	win_map->df_start_posx = 												\
		(WINDOW_LARGE - win_map->df_large_map * map->df_gapx) / 2 		\
		+ (map->sizey - 1) * map->df_gapy;
	win_map->df_start_posy = 												\
		(WINDOW_HIGHT - win_map->df_hight_map * map->df_gapy) / 2 		\
		+ (win_map->df_hight_map - win_map->df_y_max) * win_map->df_sizey_map \
		/ win_map->df_hight_map;
	if (map->save_key == 31 || map->save_key == 34)
		zoom(map);
	master->twinmap = win_map;
}
