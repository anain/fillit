/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filltab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:16:23 by asavann           #+#    #+#             */
/*   Updated: 2017/03/09 16:58:33 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_tabtab(char **str)
{
	int i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i <= 4)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * 6)))
			return (NULL);
		i++;
	}
	return (str);
}

static int		ft_findl(char *str, int *l)
{
	while (str[*l] != '\n')
		*l = *l + 1;
	return (*l);
}

static char		*ft_copyline(char *str, int l, char *line)
{
	int i;

	i = 0;
	while (str[l] != '\n')
	{
		line[i] = str[l];
		i++;
		l++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

void			ft_initi_measure(t_tetri *tab)
{
	int		i;

	i = 0;
	while (tab[i].buff != NULL)
	{
		tab[i].length = 0;
		tab[i].width = 0;
		tab[i].pos = 0;
		tab[i].ref = i;
		i++;
		tab[i].dim[0] = 0;
		tab[i].dim[1] = 0;
		tab[i].dim[2] = 0;
		tab[i].dim[3] = 0;
	}
}

void			ft_filltab(char *str, t_tetri *tab)
{
	int i;
	int j;
	int l;

	l = 0;
	j = 0;
	i = 0;
	while (str[l] != '\0')
	{
		tab[i].buff = ft_tabtab(tab[i].buff);
		while (j < 4)
		{
			tab[i].buff[j] = ft_copyline(str, l, tab[i].buff[j]);
			ft_findl(str, &l);
			l++;
			j++;
		}
		tab[i].buff[j] = NULL;
		j = 0;
		if (str[l] != '\0')
			l++;
		i++;
	}
	tab[i].buff = NULL;
	ft_initi_measure(tab);
}
