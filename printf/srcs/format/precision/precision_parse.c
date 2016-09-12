/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:13:00 by atamano           #+#    #+#             */
/*   Updated: 2014/12/20 19:37:38 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

int	precision_parse(char *str)
{
	char	*sub_str;
	int		prec;

	sub_str = ft_strchr(str, '.');
	prec = 0;
	if (!sub_str)
		return (0);
	if (++sub_str && (!ft_isdigit(*sub_str) || *sub_str == '0'))
		prec = -1;
	else if (sub_str)
		prec = ft_atoi(sub_str);
	return (prec);
}
