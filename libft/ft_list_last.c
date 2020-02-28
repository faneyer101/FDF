/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_last.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:07:37 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:04:31 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *lst)
{
	if (lst->next == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
