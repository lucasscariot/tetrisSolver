/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:26:54 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/14 02:53:08 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_dim(t_piece *tetriminos, int s)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -3;
	y = -3;
	while (i <= s)
	{
		tetriminos[i].dim_x = x;
		tetriminos[i].dim_y = y;
		i++;
	}
}

void	ft_dim_piece(t_piece *tetriminos)
{
	tetriminos->dim_x = -3;
	tetriminos->dim_y = -3;
}

int		ft_inc_dim(t_piece *tetriminos, int size_tab)
{
	if (tetriminos->dim_x != (size_tab - 1))
	{
		tetriminos->dim_x++;
		return (1);
	}
	else if (tetriminos->dim_y != (size_tab - 1))
	{
		tetriminos->dim_x = -3;
		tetriminos->dim_y++;
		return (1);
	}
	return (0);
}

int		ft_resolve(t_piece *tetriminos, char **tab, int s, int i)
{
	int		size_tab;

	size_tab = ft_sqrt(s) * 2;
	while (42)
	{
		if (i >= s)
			return (size_tab);
		if (!ft_place_piece(&tetriminos[i], size_tab, tab))
		{
			ft_clean_name(tab, size_tab, tetriminos[i - 1].name);
			if (!ft_inc_dim(&tetriminos[i - 1], size_tab))
				ft_place_piece(&tetriminos[i], size_tab, tab);
			else
			{
				ft_dim_piece(&tetriminos[i]);
				if (i == 0)
					size_tab++;
				i--;
			}
		}
		else
			i++;
	}
}
