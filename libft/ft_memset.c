/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 19:22:05 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:08:05 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		return (s);
	while (i < n)
	{
		*((unsigned char*)s) = ((unsigned char)c);
		s++;
		i++;
	}
	return (s - i);
}
