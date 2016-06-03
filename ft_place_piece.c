/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:25:58 by lscariot          #+#    #+#             */
/*   Updated: 2015/12/13 13:42:15 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_insert_piece(t_piece tetriminos, char **tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetriminos.piece[j][i] == '#')
				tab[y + j][x + i] = tetriminos.name;
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_place_test(t_piece tetriminos, int size_tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetriminos.piece[j][i] == '#' && ((x + i >= size_tab
							|| y + j >= size_tab) || (x + i < 0 || y + j < 0)))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_piece_test(t_piece tetriminos, char **tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetriminos.piece[j][i] == '#' && ft_isalpha(tab[y + j][x + i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_place_piece(t_piece *tetriminos, int size_tab, char **tab)
{
	int	x;
	int	y;

	x = tetriminos->dim_x;
	y = tetriminos->dim_y;
	while (!ft_place_test(*tetriminos, size_tab, x, y)
			|| !ft_piece_test(*tetriminos, tab, x, y))
	{
		if (y == (size_tab - 1) && x == (size_tab - 1))
			return (0);
		else if (x < size_tab - 1)
			x++;
		else
		{
			y++;
			x = -3;
		}
	}
	tetriminos->dim_y = y;
	tetriminos->dim_x = x;
	ft_insert_piece(*tetriminos, tab, x, y);
	return (1);
}
