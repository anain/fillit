/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:32:27 by anain             #+#    #+#             */
/*   Updated: 2017/03/13 17:28:14 by anain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

static void		ft_links(char *tmp)
{
	int l;
	int i;

	i = -1;
	l = 0;
	while (tmp[++i])
	{
		if ((tmp[i + 1] == '\n' && tmp[i + 2] == '\n') || !tmp[i + 1])
		{
			if (l < 3 || l > 4)
				ft_error();
			l = 0;
		}
		if (tmp[i] == '#')
		{
			if (tmp[i + 1] == '#')
				l++;
			if ((tmp[i + 1] && tmp[i + 2] && tmp[i + 3] && tmp[i + 4])
			&& tmp[i + 5] == '#' && !((tmp[i + 1] == '\n' &&
			tmp[i + 2] == '\n') || (tmp[i + 2] == '\n' && tmp[i + 3] == '\n')
			|| (tmp[i + 3] == '\n' && tmp[i + 4] == '\n')
			|| (tmp[i + 4] == '\n' && tmp[i + 5] == '\n')))
				l++;
		}
	}
}

static	int		ft_check_details(char *tmp)
{
	int i;
	int hash;
	int point;
	int line;

	i = -1;
	hash = 0;
	point = 0;
	line = 0;
	while (tmp[++i])
	{
		if ((tmp[i] != '#' && tmp[i] != '.' && tmp[i] != '\n')
			|| (tmp[i] == '\n' && tmp[i + 1] == '\n' && (((i - 19)) % 21) != 0))
			ft_error();
		if (tmp[i] == '#')
			hash++;
		if (tmp[i] == '.')
			point++;
		if (tmp[i] == '\n')
			line++;
	}
	if ((line < hash || line > 129) || (((hash % 4) != 0)
	|| ((point % 12) != 0)) || (tmp[i - 1] == '\n' && tmp[i - 2] == '\n'))
		ft_error();
	return (1);
}

static void		ft_validline(char *tmp)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (tmp[i])
	{
		if (tmp[i] != '\n')
			k++;
		if (tmp[i] == '\n' && tmp[i + 1] != '\n')
		{
			if (k != 4)
				ft_error();
			k = 0;
		}
		i++;
	}
}

char			*ft_check(int fd)
{
	int		ret;
	char	*buf;
	char	*tmp;

	tmp = ft_strnew(0);
	if (!(buf = malloc(sizeof(char) * (COUNT + 1))))
		return (NULL);
	while ((ret = read(fd, buf, COUNT)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	if (buf[0] == '\0')
		ft_error();
	free(buf);
	ft_validline(tmp);
	ft_check_details(tmp);
	ft_links(tmp);
	return (tmp);
}
