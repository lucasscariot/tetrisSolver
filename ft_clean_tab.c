/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:14:37 by lscariot          #+#    #+#             */
/*   Updated: 2015/12/12 18:43:41 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_name(char **tab, int size_tab, char c)
{
	int		y;
	int		x;

	y = 0;
	while (y < size_tab)
	{
		x = 0;
		while (x < size_tab)
		{
			if (tab[y][x] == c)
				tab[y][x] = '\0';
			x++;
		}
		y++;
	}
}

void	ft_clean_tab(char **tab, int size_tab)
{
	int		y;
	int		x;

	y = 0;
	while (y < size_tab)
	{
		x = 0;
		while (x < size_tab)
		{
			tab[y][x] = '\0';
			x++;
		}
		y++;
	}
}
