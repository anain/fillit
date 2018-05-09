/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finaltab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:54:08 by asavann           #+#    #+#             */
/*   Updated: 2017/03/13 17:29:03 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_measure(t_tetri *tab, int i)
{
	int x;
	int y;

	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (tab[i].buff[y][x] != '\0')
		{
			if (tab[i].buff[y][x] == '#')
			{
				if (y >= tab[i].length)
					tab[i].length = y + 1;
				if (x >= tab[i].width)
					tab[i].width = x + 1;
				tab[i].dim[y]++;
			}
			x++;
		}
		if (y > 0 && tab[i].buff[0][0] == '.' && tab[i].buff[y][0] != '.')
			tab[i].dim[y] = -1 * tab[i].dim[y];
		y++;
	}
}

static void		ft_move_j(t_tetri *tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i].buff != NULL)
	{
		j = 0;
		while (ft_strcmp(tab[i].buff[j], "....\n") == 0)
		{
			while (j <= 2 && ft_strcmp(tab[i].buff[j], "....\n") == 0)
			{
				ft_strcpy(tab[i].buff[j], tab[i].buff[j + 1]);
				ft_strcpy(tab[i].buff[j + 1], "....\n");
				j++;
			}
			j = 0;
		}
		i++;
	}
}

static int		ft_param_move_k(t_tetri *tab, int i)
{
	int j;
	int k;
	int l;

	j = 0;
	k = 0;
	l = 0;
	while (tab[i].buff[j][k] != '#' && tab[i].buff[j][k])
	{
		while (j <= 3 && tab[i].buff[j][k] != '#')
		{
			j++;
			l++;
		}
		j = 0;
		k++;
	}
	l = l / 4;
	return (l);
}

static void		ft_move_k(t_tetri *tab, int i, int l)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (k + l <= 3 && l != 0)
	{
		while (j <= 3 && tab[i].buff[j][0] != '\0')
		{
			if (tab[i].buff[j][k] != tab[i].buff[j][k + l])
			{
				tab[i].buff[j][k] = tab[i].buff[j][k + l];
				tab[i].buff[j][k + l] = '.';
			}
			j++;
		}
		k++;
		j = 0;
	}
}

int				ft_finaltab(t_tetri *tab)
{
	int i;
	int l;

	i = 0;
	ft_move_j(tab);
	while (tab[i].buff != NULL)
	{
		l = 0;
		l = ft_param_move_k(tab, i);
		ft_move_k(tab, i, l);
		ft_measure(tab, i);
		i++;
	}
	return (i);
}
