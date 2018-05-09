/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:52:31 by asavann           #+#    #+#             */
/*   Updated: 2017/03/13 17:46:17 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_firsthash(t_tetri tab)
{
	int i;

	i = 0;
	while (tab.buff[0][i] != '#')
		i++;
	return (i);
}

static int		ft_check_pos(t_tetri tab, t_tetri map, int x, int y)
{
	int i;
	int j;
	int nb;

	i = 0;
	nb = 0;
	j = ft_firsthash(tab);
	while (map.buff[y] != NULL && i < tab.length && x >= 0)
	{
		while (map.buff[y][x] != '\n' && j < tab.width)
		{
			if (tab.buff[i][j] == '#' && map.buff[y][x] == '.')
				nb++;
			if (nb == 4)
				return (1);
			j++;
			x++;
		}
		x = x - j;
		j = 0;
		i++;
		y++;
	}
	return (-1);
}

int				ft_findpos(t_tetri map, int pos, t_tetri tab)
{
	int i;
	int j;

	i = pos / map.length - 1;
	j = pos % map.length - 1;
	while (map.buff[++i] != NULL && i + tab.length < map.length + 1)
	{
		while (map.buff[i][++j] != '\n')
		{
			if (map.buff[i][j] == '.' && j + tab.dim[0] < map.length + 1)
			{
				if (ft_check_pos(tab, map, j, i) == 1)
					return (pos);
			}
			pos++;
		}
		j = -1;
	}
	return (-1);
}
