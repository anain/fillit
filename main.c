/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:40:10 by anain             #+#    #+#             */
/*   Updated: 2017/03/13 18:06:53 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void	ft_fillit(t_tetri *tab, char *str)
{
	int		i;
	t_tetri map;

	ft_filltab(str, tab);
	free(str);
	i = ft_finaltab(tab);
	map.length = ft_sqrt(i * 4);
	while (!ft_map(tab, ft_memmap(map), 0))
		map.length++;
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	t_tetri	*tab;
	int		i;

	str = NULL;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error();
		str = ft_check(fd);
		close(fd);
	}
	else
	{
		write(2, "usage: ./fillit [file]\n", 23);
		exit(EXIT_FAILURE);
	}
	if (!(tab = (t_tetri*)malloc(sizeof(t_tetri) * (26 + 1))))
		ft_error();
	ft_fillit(tab, str);
	return (0);
}
