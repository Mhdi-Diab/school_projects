/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:02:21 by atamano           #+#    #+#             */
/*   Updated: 2015/03/24 16:10:16 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include "string.h"
# include "math.h"

typedef enum		e_str_color
{
	BOLD,
	BLACK,
	RED,
	GREEN,
	BROWN,
	MAGENTA,
	CYAN,
	GRAY,
	BLUE,
	NONE
}					t_str_color;


void				ft_print_tab(char **tab);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putcstr(char *str, t_str_color color);
void				ft_putcolor_fd(int fd, char *str, t_str_color color);
void				ft_putnbr(int n);

#endif
