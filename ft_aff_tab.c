/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfrely <hfrely@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:14:06 by hfrely            #+#    #+#             */
/*   Updated: 2015/12/17 17:04:32 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_aff_tab(char **tab, int size_tab)
{
	int	i;
	int	j;

	j = 0;
	while (j < size_tab)
	{
		i = 0;
		while (i < size_tab)
		{
			if (ft_isalpha(tab[j][i]))
				ft_putchar(tab[j][i]);
			else
				ft_putchar('.');
			i++;
		}
		j++;
		ft_putchar('\n');
	}
}
