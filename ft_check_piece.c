/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:44:00 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/13 23:40:48 by hfrely           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_char(char c)
{
	if (c == '.' || c == '#')
		return ;
	ft_error();
}

void	ft_check_piece(t_piece *tetriminos)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			ft_check_char(tetriminos->piece[x][y]);
			y++;
		}
		y = 0;
		x++;
	}
}

int		ft_check_connexion(t_piece *tetriminos, int x, int y, int co)
{
	if (tetriminos->piece[x + 1][y] == '#' && x < 3)
		co++;
	if (tetriminos->piece[x][y + 1] == '#' && y < 3)
		co++;
	return (co);
}

void	ft_connexion(t_piece *tetriminos)
{
	int x;
	int y;
	int co;
	int	diese;

	diese = 0;
	co = 0;
	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			if (tetriminos->piece[x][y] == '#')
			{
				co = ft_check_connexion(tetriminos, x, y, co);
				diese++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	if ((co != 3 && co != 4) || diese != 4)
		ft_error();
}

void	ft_check_struct(t_piece *tetriminos, int z)
{
	int	i;

	i = 0;
	while (i < z)
	{
		ft_check_piece(&tetriminos[i]);
		ft_connexion(&tetriminos[i]);
		i++;
	}
}
