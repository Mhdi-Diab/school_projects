/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:52:21 by atamano           #+#    #+#             */
/*   Updated: 2014/11/05 17:01:21 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
