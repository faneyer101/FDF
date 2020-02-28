/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 17:22:56 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:21:23 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (s == NULL || !(s2 = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[start] != '\0')
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
