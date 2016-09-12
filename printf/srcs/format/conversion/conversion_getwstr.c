/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 13:54:56 by atamano           #+#    #+#             */
/*   Updated: 2014/12/20 13:55:19 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "conversion.h"

char		*conversion_getwstr(t_conversion *c, wchar_t *str)
{
	int		total;
	int		len;
	char	*new_str;
	char	*wchar;
	t_list	*list;

	total = 0;
	list = NULL;
	new_str = ft_strnew(1);
	while (*str)
	{
		wchar = conversion_getwchar(*str);
		new_str = ft_strfjoin(new_str, wchar);
		len = (int)ft_strlen(wchar);
		ft_lstadd_back(&list, ft_lstnew((int *)&len, sizeof(int *)));
		str++;
	}
	c->input_length = list;
	return (new_str);
}
