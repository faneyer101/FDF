/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 00:28:01 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 10:28:09 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tracer(t_map *map, t_node **node, char *img, int i)
{
	int		j;

	j = 1;
	while (i < (int)map->sizey)
	{
		while (j < ((int)map->sizex))
		{
			bresenham(node[i][j - 1], node[i][j], map, (int**)&img);
			j++;
		}
		j = 1;
		i++;
	}
	i = 1;
	j = 0;
	while (j < (int)map->sizex)
	{
		while (i < ((int)map->sizey))
		{
			bresenham(node[i - 1][j], node[i][j], map, (int**)&img);
			i++;
		}
		i = 1;
		j++;
	}
}

t_node	**malloc_node(t_node **node, t_map *map)
{
	int i;

	i = 0;
	if (!(node = (t_node**)malloc(sizeof(t_node*) * (map->sizey + 1))))
		return (NULL);
	while (i < (int)map->sizey)
	{
		if (!((node[i]) = (t_node*)malloc(sizeof(t_node) * (map->sizex))))
			return (NULL);
		i++;
	}
	node[i] = NULL;
	return (node);
}

void	initmaster(t_map *map, t_node **node, t_env envi, t_ma *master)
{
	master->tmap = map;
	master->tnode = node;
	master->tenv = &envi;
	map->save_key = 0;
	map->df_gapx = 0;
	map->df_gapy = 0;
}

int		norme_main(char *av, t_map *map, t_env *envi, t_node ***node)
{
	int	ret;
	int	i;

	ret = 0;
	if ((ret = ft_parsing(av, map, 0)) < 0)
	{
		mlx_destroy_image(envi->mlx_ptr, envi->img_ptr);
		if (ret == -2)
		{
			i = 0;
			while (map->sizey > i)
			{
				free(map->tab[i]);
				i++;
			}
			if (map->tab != NULL)
				free(map->tab);
		}
		exit(0);
	}
	if ((node[0] = malloc_node(node[0], map)) != NULL)
		return (0);
	return (-1);
}

int		main(int ac, char **av)
{
	t_map		map;
	t_node		**node;
	t_env		envi;
	t_ma		master;
	int			len;

	len = 0;
	node = NULL;
	map.move_x = 0;
	if (ac != 2)
		return (usage(1));
	envi.mlx_ptr = mlx_init();
	envi.img_ptr = mlx_new_image(envi.mlx_ptr, WINDOW_LARGE, WINDOW_HIGHT);
	envi.img = mlx_get_data_addr(envi.img_ptr, &(envi.bpp), &(envi.s_l),
			&(envi.endian));
	envi.win_ptr = mlx_new_window(envi.mlx_ptr, WINDOW_LARGE, WINDOW_HIGHT,
			"FDF.exe");
	if (norme_main(av[1], &map, &envi, &node) == -1)
		return (-1);
	initmaster(&map, node, envi, &master);
	key_event(84, &master);
	mlx_hook(envi.win_ptr, 2, 1L << 0, &key_event, &master);
	mlx_hook(envi.win_ptr, 17, 0, &close_event, &master);
	mlx_loop(envi.mlx_ptr);
	return (0);
}
