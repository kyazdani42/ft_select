/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyazdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 08:30:52 by kyazdani          #+#    #+#             */
/*   Updated: 2018/01/24 18:21:56 by kyazdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*get_ttyname(void)
{
	char	*tty;

	tty = NULL;
	if (!isatty(STDIN_FILENO))
		return (0);
	if (!(tty = getenv("TERM")))
		return ("xterm-256color");
	return (tty);
}

int		init_termcaps(void)
{
	int		value;
	char	*buf;
	char	*term;

	buf = NULL;
	term = NULL;
	value = 0;
	if (!(term = get_ttyname()))
	{
		ft_putendl("error: Stdin is not a tty");
		return (0);
	}
	value = tgetent(buf, term);
	if (value == 0)
	{
		ft_printf_fd(STDERR_FILENO, "Terminal type %s is not defined\n", term);
		return (0);
	}
	if (value < 0)
	{
		ft_putendl_fd("Could not access the termcap database", STDERR_FILENO);
		return (0);
	}
	return (1);
}
