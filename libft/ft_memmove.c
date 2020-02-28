/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 20:14:35 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:07:50 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		while (n--)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (dest);
}
