/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_iso.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 03:43:49 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 07:27:01 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	range_height_max(t_map *map, t_win_map *win_map)
{
	int	x;
	int	y;

	y = 0;
	win_map->df_y_max = map->tab[y][0] / 5;
	win_map->df_y_min = map->tab[y][0] / 5;
	while (y < (int)map->sizey)
	{
		x = 0;
		while (x < (int)map->sizex)
		{
			if (win_map->df_y_min > ((x + y) - (float)(map->tab[y][x]) / 5))
				win_map->df_y_min = (x + y) - (float)(map->tab[y][x]) / 5;
			else if (win_map->df_y_max < ((x + y) \
						- (float)(map->tab[y][x]) / 5))
				win_map->df_y_max = (x + y) - (float)(map->tab[y][x]) / 5;
			x++;
		}
		y++;
	}
	win_map->df_hight_map = win_map->df_y_max - win_map->df_y_min;
}

void	zoom(t_map *map)
{
	static float zoom = 1;

	if (map->save_key == 31)
	{
		zoom = zoom / 1.25;
		map->df_gapx = map->df_gapx / 1.25;
		map->df_gapy = map->df_gapy / 1.25;
	}
	else if (map->save_key == 0)
	{
		map->df_gapx = map->df_gapx / zoom;
		map->df_gapy = map->df_gapy / zoom;
		zoom = 1;
	}
	else
	{
		zoom = zoom * 1.25;
		map->df_gapx = map->df_gapx * 1.25;
		map->df_gapy = map->df_gapy * 1.25;
	}
}

void	map_iso(t_map *map, t_win_map *win_map, t_ma *master, int marge)
{
	win_map->df_y_min = 0;
	win_map->df_y_max = 0;
	range_height_max(map, win_map);
	win_map->df_large_map = map->sizex + map->sizey - 2;
	win_map->df_sizex_map = WINDOW_LARGE * (100 - 2 * marge) / 100;
	win_map->df_sizey_map = WINDOW_HIGHT * (100 - 2 * marge) / 100;
	if (map->df_gapx == 0 || map->df_gapy == 0)
	{
		map->df_gapx = win_map->df_sizex_map / (map->sizex + map->sizey - 2);
		map->df_gapy = win_map->df_sizey_map / (win_map->df_hight_map);
		(map->df_gapy < map->df_gapx * (tan(M_PI / 6))) ? (map->df_gapx =
				map->df_gapy / (tan(M_PI / 6))) : (map->df_gapy = map->df_gapx *
				(tan(M_PI / 6)));
	}
	win_map->df_start_posx =
		(WINDOW_LARGE - win_map->df_large_map * map->df_gapx) / 2
		+ (map->sizey - 1) * map->df_gapx;
	win_map->df_start_posy =
		(WINDOW_HIGHT - win_map->df_hight_map * map->df_gapy) / 2
		+ (win_map->df_hight_map - win_map->df_y_max) * win_map->df_sizey_map
		/ win_map->df_hight_map;
	if (map->save_key == 31 || map->save_key == 34 || map->save_key == 0)
		zoom(map);
	master->twinmap = win_map;
}
