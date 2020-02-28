/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 05:17:32 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 09:50:17 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display(t_ma *master)
{
	scale(master);
	if (master->tmap->save_view == 83)
		master->tnode = cavaliere(master->tmap, master->tnode, master);
	else if (master->tmap->save_view == 84)
		master->tnode = isometrie(master->tmap, master->tnode, master);
	tracer(master->tmap, master->tnode, master->tenv->img, 0);
	trace_frame(0, 0, (int**)&master->tenv->img);
	mlx_put_image_to_window(master->tenv->mlx_ptr, master->tenv->win_ptr,
			master->tenv->img_ptr, 0, 0);
	inithud(master);
}

int		key_event4(int key, t_ma *master)
{
	if (key == 31)
	{
		clean_new(master);
		display(master);
	}
	else if (key == 8)
	{
		clean_new(master);
		master->tmap->move_x = 0;
		master->tmap->move_y = 0;
		display(master);
	}
	return (0);
}

int		key_event3(int key, t_ma *master)
{
	if (key == 126)
	{
		clean_new(master);
		master->tmap->move_y -= 100;
	}
	else if (key == 69)
	{
		clean_new(master);
		master->tmap->move_z += 0.25;
	}
	else if (key == 78)
	{
		clean_new(master);
		master->tmap->move_z -= 0.25;
	}
	else if (key == 34)
		clean_new(master);
	else
		return (key_event4(key, master));
	display(master);
	return (0);
}

int		key_event2(int key, t_ma *master)
{
	if (key == 84)
		clean_new(master);
	else if (key == 123)
	{
		clean_new(master);
		master->tmap->move_x -= 100;
	}
	else if (key == 124)
	{
		clean_new(master);
		master->tmap->move_x += 100;
	}
	else if (key == 125)
	{
		clean_new(master);
		master->tmap->move_y += 100;
	}
	else
		return (key_event3(key, master));
	display(master);
	return (0);
}

int		key_event(int key, t_ma *master)
{
	if (key == master->tmap->save_view)
		return (0);
	else
	{
		master->tmap->save_key = key;
		if (key == 83)
			master->tmap->save_view = 83;
		else if (key == 84)
			master->tmap->save_view = 84;
	}
	if (key == 53)
	{
		free_exit(master);
		exit(0);
	}
	else if (key == 83)
	{
		clean_new(master);
		display(master);
	}
	else
		return (key_event2(key, master));
	return (0);
}
