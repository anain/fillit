/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:20:25 by asavann           #+#    #+#             */
/*   Updated: 2017/03/13 17:46:47 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_printmap(t_tetri map)
{
	int j;

	j = 0;
	while (map.buff[j] != NULL)
	{
		ft_putstr(map.buff[j]);
		j++;
	}
}

t_tetri			ft_memmap(t_tetri map)
{
	int j;
	int k;

	j = -1;
	if (!(map.buff = (char **)malloc(sizeof(char *) * (map.length + 1))))
		ft_error();
	while (++j < map.length)
	{
		if (!(map.buff[j] = (char *)malloc(sizeof(char) * (map.length + 2))))
			ft_error();
	}
	j = -1;
	while (++j < map.length)
	{
		k = 0;
		while (k < map.length)
		{
			map.buff[j][k] = '.';
			k++;
		}
		map.buff[j][k] = '\n';
		map.buff[j][k + 1] = '\0';
	}
	map.buff[j] = 0;
	return (map);
}

static void		ft_puttetri(t_tetri tetri, t_tetri map, int x, int y)
{
	int j;
	int k;
	int nb;

	j = -1;
	nb = 0;
	k = ft_firsthash(tetri);
	while (tetri.buff[++j][0] != '\0')
	{
		while (tetri.buff[j][k] != '\0')
		{
			if (tetri.buff[j][k] == '#')
			{
				map.buff[y][x] = 'A' + tetri.ref;
				nb++;
			}
			if (nb == 4)
				return ;
			x++;
			k++;
		}
		x = x - k;
		k = 0;
		y++;
	}
}

static void		ft_clear(t_tetri map, t_tetri tab, int k, int j)
{
	int nb;

	nb = 0;
	while (map.buff[j] != 0)
	{
		while (map.buff[j][k] != '\0')
		{
			if (map.buff[j][k] == 'A' + tab.ref)
			{
				map.buff[j][k] = '.';
				nb++;
			}
			if (nb == 4)
				return ;
			k++;
		}
		k = 0;
		j++;
	}
}

int				ft_map(t_tetri *tab, t_tetri map, int i)
{
	int pos;
	int x;
	int y;

	pos = 0;
	if (tab[i].buff == NULL)
	{
		ft_printmap(map);
		ft_delmap(map);
		ft_deltab(tab);
		return (1);
	}
	while ((pos = ft_findpos(map, pos, tab[i])) != -1)
	{
		x = pos % map.length;
		y = pos / map.length;
		ft_puttetri(tab[i], map, x, y);
		if (ft_map(tab, map, i + 1) == 1)
			return (1);
		ft_clear(map, tab[i], x, y);
		pos++;
	}
	return (0);
}
