/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anain <anain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:30:00 by anain             #+#    #+#             */
/*   Updated: 2017/03/10 17:42:24 by asavann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define COUNT 21

typedef struct	s_tetri
{
	char	**buff;
	int		width;
	int		length;
	int		pos;
	int		ref;
	int		dim[4];
}				t_tetri;

int				ft_isupper(int c);
void			ft_filltab(char *str, t_tetri *tab);
void			ft_initi_measure(t_tetri *tab);
char			*ft_check(int fd);
char			**ft_bricks(t_tetri *tab);
int				ft_finaltab(t_tetri *tab);
t_tetri			ft_square(t_tetri *tab, t_tetri map, int xo, int yo);
int				ft_map(t_tetri *tab, t_tetri map, int i);
void			ft_error(void);
void			ft_measure(t_tetri *tab, int i);
void			ft_printmap(t_tetri map);
t_tetri			ft_memmap(t_tetri map);
int				ft_findpos(t_tetri map, int pos, t_tetri tab);
int				ft_firsthash(t_tetri tab);
void			ft_delmap(t_tetri map);
void			ft_deltab(t_tetri *tab);

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr(char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
void			ft_putchar(char c);
size_t			ft_strlen(const char *str);
void			ft_bzero(void *str, size_t n);

#endif
