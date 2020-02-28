/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   untils_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 20:24:58 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 10:32:33 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_exit(t_ma *master)
{
	int i;
	int	j;

	i = 0;
	while (master->tmap->sizey > i)
	{
		j = 0;
		free(master->tmap->tab[i]);
		i++;
	}
	free(master->tmap->tab);
	i = 0;
	while (master->tnode[i] != NULL)
	{
		free(master->tnode[i]);
		master->tnode[i] = NULL;
		i++;
	}
	free(master->tnode[i]);
	free(master->tnode);
}

void	clean_new(t_ma *master)
{
	mlx_destroy_image(master->tenv->mlx_ptr, master->tenv->img_ptr);
	master->tenv->img_ptr = mlx_new_image(master->tenv->mlx_ptr,
			WINDOW_LARGE, WINDOW_HIGHT);
	master->tenv->img = mlx_get_data_addr(master->tenv->img_ptr,
			&(master->tenv->bpp), &(master->tenv->s_l),
			&(master->tenv->endian));
}

void	free_tmp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_line *list)
{
	t_line	*next_list;

	next_list = list->next;
	while (list != NULL)
	{
		list->next = NULL;
		ft_strdel(list->line);
		free(list->line);
		free(list);
		list = next_list;
		if (next_list != NULL)
			next_list = next_list->next;
	}
}

int		usage(int bolean)
{
	if (bolean == 1)
		ft_putstr("Usage: ./fdf file\n");
	else if (bolean == 2)
		ft_putstr("fichier vide, minimum 2 points par ligne\n");
	return (-1);
}
