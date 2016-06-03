/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 08:31:17 by lscariot          #+#    #+#             */
/*   Updated: 2015/12/17 15:53:26 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_save(t_gnl *baboom, char **line)
{
	while (baboom->read--)
	{
		if (baboom->buff[baboom->ret] == '\n')
		{
			baboom->ret++;
			return (1);
		}
		(*line)[baboom->i] = baboom->buff[baboom->ret++];
		baboom->i++;
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	static t_gnl	baboom;
	char			*buff;
	int				r;

	baboom.i = 0;
	*line = ft_memalloc(1000);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (baboom.read > 0)
	{
		if (ft_save(&baboom, line))
			return (1);
	}
	baboom.ret = 0;
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		if (r == -1)
			return (-1);
		baboom.buff = ft_strdup(buff);
		baboom.read = r;
		if (ft_save(&baboom, line))
			return (1);
		ft_strdel(&baboom.buff);
		baboom.ret = 0;
	}
	return (0);
}
