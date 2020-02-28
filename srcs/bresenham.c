/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 00:30:24 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 20:11:05 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_line(t_node node1, t_node node2, t_bresenham *line)
{
	line->ex = fabs(node2.x - node1.x);
	line->ey = fabs(node2.y - node1.y);
	line->dx[0] = 2 * line->ex;
	line->dx[1] = line->ex;
	line->dy[0] = 2 * line->ey;
	line->dy[1] = line->ey;
	if (node1.x > node2.x)
		line->x_incr = -1;
	else
		line->x_incr = 1;
	if (node1.y > node2.y)
		line->y_incr = -1;
	else
		line->y_incr = 1;
}

void	fill_pixel(int **img, int x, int y, int color)
{
	unsigned long long	i;

	if ((x >= 99) && (x < (WINDOW_LARGE - 98)) && (y >= 99) &&
			(y < (WINDOW_HIGHT - 98)))
	{
		i = x + WINDOW_LARGE * y;
		(*img)[i] = color;
	}
	else
		return ;
}

int		chose_colors(t_node node1, t_node node2, t_map *map)
{
	int	color;

	color = 0;
	if ((node1.z == 0 && node2.z == 0) || map->move_z == -1)
		color = GREEN;
	else if (((node1.z > 0 || node2.z > 0) && map->move_z > -1) ||
			((node1.z < 0 || node2.z < 0) && map->move_z < -1))
		color = RED;
	else if (((node1.z <= 0 && node2.z <= 0) && map->move_z > -1) ||
			((node1.z > 0 || node2.z > 0) && map->move_z < -1))
		color = BLUE;
	return (color);
}

void	norme_bresenham(int color, int **img, t_bresenham line, int *i)
{
	if (line.dx[1] < line.dy[1])
		while (++i[2] <= line.dy[1])
		{
			fill_pixel(img, i[0], i[1], color);
			i[1] += line.y_incr;
			line.ey -= line.dx[0];
			if (line.ey < 0)
			{
				i[0] += line.x_incr;
				line.ey += line.dy[0];
			}
		}
	else if (line.dx[1] == line.dy[1] || line.dy[1] == 0)
		while (++i[2] <= line.dx[1])
		{
			fill_pixel(img, i[0], i[1], color);
			line.dy[1] != 0 ? (i[0] += line.x_incr) : 0;
			i[1] += line.y_incr;
		}
	else if (line.dx[1] == 0)
		while (++i[2] <= line.dy[1])
		{
			fill_pixel(img, i[0], i[1], color);
			i[0] += line.x_incr;
		}
}

void	bresenham(t_node node1, t_node node2, t_map *map, int **img)
{
	t_bresenham	line;
	int			color;
	int			i[3];

	i[0] = node1.x;
	i[1] = node1.y;
	color = chose_colors(node1, node2, map);
	i[2] = -1;
	init_line(node1, node2, &line);
	if (line.dx[1] > line.dy[1])
		while (++i[2] <= line.dx[1])
		{
			fill_pixel(img, i[0], i[1], color);
			i[0] += line.x_incr;
			line.ex -= line.dy[0];
			if (line.ex < 0)
			{
				i[1] += line.y_incr;
				line.ex += line.dx[0];
			}
		}
	norme_bresenham(color, img, line, i);
}
