/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 06:33:35 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 18:52:50 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trace_frame(int x, int y, int **img)
{
	x = 100 - 1;
	y = 100 - 1;
	while (x < (WINDOW_LARGE - (100 - 1)))
	{
		fill_pixel(img, x, y, 0xCC0000);
		x++;
	}
	while (y < (WINDOW_HIGHT - (100 - 1)))
	{
		fill_pixel(img, x, y, 0xCC0000);
		y++;
	}
	while (x > (100 - 1))
	{
		fill_pixel(img, x, y, 0xCC0000);
		x--;
	}
	while (y > (100 - 1))
	{
		fill_pixel(img, x, y, 0xCC0000);
		y--;
	}
}

void	inithud(t_ma *master)
{
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.2 *
			WINDOW_LARGE, 15, 0x0000FF, "deplacement a gauche: <");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.2 *
			WINDOW_LARGE, 30, 0x0000FF, "deplacement a droite: >");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.2 *
			WINDOW_LARGE, 45, 0x0000FF, "deplacement en haut:  ^");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.2 *
			WINDOW_LARGE, 60, 0x0000FF, "deplacement en bas:   v");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.45 *
			WINDOW_LARGE, 15, 0x0000FF, "Zoom in:     i");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.45 *
			WINDOW_LARGE, 30, 0x0000FF, "Zoom out:    o");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.45 *
			WINDOW_LARGE, 45, 0x0000FF, "Augmenter Z: +");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.45 *
			WINDOW_LARGE, 60, 0x0000FF, "Diminuer Z:  -");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.7 *
			WINDOW_LARGE, 15, 0x0000FF, "Projection Isometrique: 2");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.7 *
			WINDOW_LARGE, 30, 0x0000FF, "Projection Cavaliere:   1");
	mlx_string_put(master->tenv->mlx_ptr, master->tenv->win_ptr, 0.7 *
			WINDOW_LARGE, 45, 0x0000FF, "Centrer Vue:            c");
}
