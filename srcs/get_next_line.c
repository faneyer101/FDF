/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 15:46:59 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 18:50:16 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_norme(char **line, char **s, int r, char *tmp)
{
	if (ft_strlen_c(*s, '\n') != -1)
	{
		if (!(*line = ft_strsub(*s, 0, ft_strlen_c(*s, '\n'))))
			return (-1);
		if (!(tmp = ft_strsub(*s, ft_strlen_c(*s, '\n') + 1, ft_strlen(*s))))
			return (-1);
		ft_strdel(s);
		if (!(*s = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
		r = 1;
	}
	else if (ft_strlen(*s) > 0)
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
		r = 1;
	}
	else
		*line = NULL;
	return (r);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[10000];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	int			r;

	if (fd < 0 || line == NULL || fd > 10000 || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	r = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		r = 1;
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buf)))
			return (-1);
		ft_strdel(&str[fd]);
		if (!(str[fd] = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	return (ft_norme(line, &str[fd], r, tmp));
}
