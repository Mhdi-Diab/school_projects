/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:42:21 by atamano           #+#    #+#             */
/*   Updated: 2014/11/03 18:23:11 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctypes.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}
