/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asavann <asavann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:49:15 by asavann           #+#    #+#             */
/*   Updated: 2017/03/13 17:01:35 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deltab(t_tetri *tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i].buff != NULL)
	{
		while (tab[i].buff[j] != NULL)
		{
			free(tab[i].buff[j]);
			j++;
		}
		j = 0;
		free(tab[i].buff);
		i++;
	}
	free(tab);
}

void	ft_delmap(t_tetri map)
{
	int i;

	i = 0;
	while (map.buff[i] != NULL)
	{
		free(map.buff[i]);
		i++;
	}
	free(map.buff);
}
