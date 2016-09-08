/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 11:21:47 by atamano           #+#    #+#             */
/*   Updated: 2015/02/10 11:21:51 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static	char	*get_color(t_str_color color)
{
	if (color == NONE)
		return ("\033[0m");
	if (color == BOLD)
		return ("\033[1m");
	if (color == BLACK)
		return ("\033[30m");
	if (color == RED)
		return ("\033[31m");
	if (color == GREEN)
		return ("\033[32m");
	if (color == BROWN)
		return ("\033[33m");
	if (color == BLUE)
		return ("\033[34m");
	if (color == MAGENTA)
		return ("\033[35m");
	if (color == CYAN)
		return ("\033[36m");
	if (color == GRAY)
		return ("\033[37m");
	return ("\033[0m");
}

void			ft_putcstr(char *str, t_str_color color)
{
	ft_putstr(get_color(color));
	ft_putstr(str);
	ft_putstr(get_color(NONE));
}

void			ft_putcolor_fd(int fd, char *str, t_str_color color)
{
	ft_putstr(get_color(color));
	ft_putstr_fd(str, fd);
	ft_putstr(get_color(NONE));
}
