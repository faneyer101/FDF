/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_size.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:08:09 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:04:43 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *lst)
{
	int	compteur;

	compteur = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		compteur++;
	}
	return (compteur);
}
