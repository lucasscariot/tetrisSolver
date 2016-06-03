/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <lscariot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:52:27 by lscariot          #+#    #+#             */
/*   Updated: 2016/01/14 00:23:05 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>

# define BUFF_SIZE 21

typedef struct	s_piece
{
	char	piece[4][4];
	char	name;
	int		dim_x;
	int		dim_y;
}				t_piece;
void			ft_error(void);
int				ft_open_file(char *file);
void			ft_aff_piece(t_piece *tetriminos);
void			ft_put_piece(char *str, t_piece *tetriminos);
t_piece			*ft_read(char *file, int *s, int caca);
void			ft_check_char(char c);
void			ft_check_piece(t_piece *tetriminos);
void			ft_check_struct(t_piece *tetriminos, int z);
int				ft_place_piece(t_piece *tetriminos, int size_tab, char **tab);
void			ft_aff_tab(char **tab, int size_tab);
int				ft_resolve(t_piece *tetriminos, char **tab, int s, int i);
void			ft_clean_tab(char **tab, int size_tab);
void			ft_clean_name(char **tab, int size_tab, char c);
void			ft_dim(t_piece *tetriminos, int s);

#endif
