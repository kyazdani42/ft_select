/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:20:56 by kyazdani          #+#    #+#             */
/*   Updated: 2018/01/25 12:54:37 by kyazdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include "libft.h"

typedef struct			s_content
{
	int					index;
	int					check;
	int					x;
	int					y;
	char				*elem;
	struct s_content	*next;
}						t_content;
/*
** init_attrs
*/
void					ft_cfmakeraw(struct termios *my_state);
void					ft_cfmakedefault(struct termios *my_state);
/*
** init_terms
*/
char					*get_ttyname(void);
int						init_termcaps(void);
/*
** mooves
*/
int						go_up(t_content **content, t_content *current);
int						go_down(t_content **content, t_content *current);
int						go_left(t_content **content, t_content *current);
int						go_right(t_content **content, t_content *current);
/*
** mount_list
*/
int						count_list(t_content **list);
void					mount_list(t_content **content, char **av);
/*
** stdin_read (underline and read)
*/
void					print_color(int check, int index, t_content **content);
void					print_under(int check, int index, t_content **content);
void					select_readtype(t_content **content);
/*
** display
*/
int						display(int co, int li, t_content **content);
#endif
