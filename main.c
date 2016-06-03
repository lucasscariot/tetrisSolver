/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:53:45 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/14 17:01:05 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_aff_piece(t_piece *tetriminos)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tetriminos->piece[x][y] == '#')
				ft_putchar(tetriminos->name);
			else
				ft_putchar(tetriminos->piece[x][y]);
			y++;
		}
		ft_putchar('\n');
		y = 0;
		x++;
	}
}

void	ft_put_piece(char *str, t_piece *tetriminos)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
			tetriminos->piece[x][y++] = *str++;
		if (*str++ != '\n')
			ft_error();
		x++;
		y = 0;
	}
}

t_piece	*ft_name(char c)
{
	t_piece	*piece;

	piece = malloc(sizeof(t_piece));
	if (!piece)
		ft_error();
	piece->name = c;
	return (piece);
}

t_piece	*ft_read(char *file, int *s, int caca)
{
	int		ret;
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		z;
	t_piece	*tetriminos;

	z = 0;
	tetriminos = malloc(sizeof(tetriminos) * 25);
	ft_bzero(buff, sizeof(buff));
	fd = ft_open_file(file);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		z >= 26 ? ft_error() : 0;
		ft_put_piece(buff, &tetriminos[z]);
		caca = ret;
		tetriminos[z].name = 'A' + z;
		ft_strclr(buff);
		z++;
	}
	caca == 21 ? ft_error() : 0;
	!tetriminos[0].piece[0][0] ? ft_error() : 0;
	*s = z;
	close(fd);
	ft_check_struct(tetriminos, z);
	return (tetriminos);
}

int		main(int argc, char **argv)
{
	t_piece *tetriminos;
	int		s;
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char **) * 24);
	if (!tab)
		ft_error();
	while (i < 24)
	{
		tab[i] = (char *)malloc(sizeof(char *) * 24);
		if (!tab[i++])
			ft_error();
	}
	if (argc != 2)
		ft_error();
	tetriminos = ft_read(argv[1], &s, 0);
	ft_dim(tetriminos, s);
	i = ft_resolve(tetriminos, tab, s, 0);
	ft_aff_tab(tab, i);
	return (0);
}
