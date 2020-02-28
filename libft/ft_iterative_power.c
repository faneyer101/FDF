/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:09:49 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:04:01 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_power(int nb, int power)
{
	int i;

	i = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (power > 0)
	{
		i = i * nb;
		power--;
	}
	return (i);
}
