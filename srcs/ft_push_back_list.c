/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_push_back_list.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 09:36:55 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 18:34:21 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_line	*ft_create_elem(char *s)
{
	t_line	*box;

	box = NULL;
	box = (t_line*)malloc(sizeof(t_line));
	if (box == NULL)
		return (box);
	box->line = ft_strsplit(s, '\n');
	box->next = NULL;
	return (box);
}

void	push_back_list(t_line **begin_list, char *str)
{
	t_line	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = ft_create_elem(str);
		list = list->next;
	}
	else
		*begin_list = ft_create_elem(str);
}
