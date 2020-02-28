/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scale.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 04:36:11 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 07:24:47 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_scale(t_ma *master, float reduction)
{
	int	i;
	int	j;

	i = 0;
	while (i < master->tmap->sizey)
	{
		j = 0;
		while (j < master->tmap->sizex)
		{
			master->tmap->tab[i][j] = master->tmap->tab[i][j] / reduction;
			j++;
		}
		i++;
	}
}

void	scale(t_ma *master)
{
	int		i;
	int		j;
	float	z_max_abs;
	float	reduction;

	i = 0;
	z_max_abs = 0;
	reduction = 0;
	while (i < master->tmap->sizey)
	{
		j = 0;
		while (j < master->tmap->sizex)
		{
			if (fabs(master->tmap->tab[i][j]) > z_max_abs)
				z_max_abs = fabs(master->tmap->tab[i][j]);
			j++;
		}
		i++;
	}
	if (z_max_abs > 2)
	{
		reduction = z_max_abs / 2;
		set_scale(master, reduction);
	}
}
