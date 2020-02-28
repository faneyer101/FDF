/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:21:19 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:18:03 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	long int	pos;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if (pos != -1)
		return ((char *)&s[pos]);
	if (s[i] == '\0' && (char)c == '\0')
		return ((char*)&s[ft_strlen(s)]);
	return (NULL);
}
