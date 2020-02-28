/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: davfelix <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/05 07:53:34 by davfelix     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/05 10:29:07 by davfelix    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	a_to_i(int *len, char **tmp, t_map *map)
{
	int i[2];

	i[0] = 0;
	i[1] = -1;
	while (tmp[++i[1]])
	{
		if (ft_atoi(tmp[i[1]]) > 2147483647 || ft_atoi(tmp[i[1]]) < -2147483648)
		{
			free_tmp(tmp);
			return (-2);
		}
		map->tab[len[0]][i[0]] = ft_atoi(tmp[i[1]]);
		i[0]++;
	}
	return (0);
}

int	ft_parting_norme2(t_map *map, t_line *list, int *len, t_line *beg_list)
{
	char	**tmp;

	while (list)
	{
		if (!(map->tab[len[0]] = (float*)malloc(sizeof(float) * (map->sizex)))
				|| !(tmp = ft_strsplit(list->line[0], ' ')))
		{
			free_list(beg_list);
			return (-2);
		}
		if (a_to_i(len, tmp, map) == -2)
			return (-2);
		free_tmp(tmp);
		len[0]++;
		list = list->next;
	}
	return (0);
}

int	ft_parting_norme3(int *len, t_line **list, t_map *map, char *line)
{
	if (map->sizex == 0)
	{
		if (ft_countword(line, ' ') < 2)
		{
			ft_putstr("Deux points sur la meme ligne pour une map OK\n");
			return (-1);
		}
		map->sizex = ft_countword(line, ' ');
	}
	else if (map->sizex != (int)ft_countword(line, ' '))
	{
		ft_strdel(&line);
		free_list(list[0]);
		write(2, "fichier mal formate\n", 20);
		return (-1);
	}
	push_back_list(list, line);
	len[0]++;
	ft_strdel(&line);
	return (0);
}

int	ft_parting_norme1(int fd, int *len, t_line **list, t_map *map)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
		{
			ft_strdel(&line);
			write(2, "fichier mal formate\n", 20);
			return (-1);
		}
		if (ft_parting_norme3(len, list, map, line) == -1)
			return (-1);
	}
	return (0);
}

int	ft_parsing(char *file, t_map *map, int len)
{
	int		fd;
	int		ret;
	t_line	*list;
	t_line	*begin_list;

	list = NULL;
	map->sizex = 0;
	if ((fd = open(file, O_RDONLY)) == -1 ||
			ft_parting_norme1(fd, &len, &list, map) == -1)
		return (usage(2));
	if (len == 0)
		return (-1);
	begin_list = list;
	map->sizey = len;
	if (!(map->tab = (float**)malloc(sizeof(float*) * (map->sizey))))
	{
		free_list(begin_list);
		return (-1);
	}
	len = 0;
	ret = ft_parting_norme2(map, list, &len, begin_list);
	list = begin_list;
	if (list)
		free_list(list);
	return (ret);
}
