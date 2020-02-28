/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:54:09 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:05:55 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	if (lst != NULL)
	{
		if (!(lst2 = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		lst2 = f(lst);
		lst2->next = ft_lstmap(lst->next, f);
		return (lst2);
	}
	return (NULL);
}
