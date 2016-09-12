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

#include "width.h"
#include "option.h"

static void		handle_big_s(t_format *f)
{
	int		bigs_len;
	int		tmp;
	t_list	*list;

	bigs_len = 0;
	list = (t_list *)f->conversion->input_length;
	while (list)
	{
		tmp = *(int *)list->content;
		if (bigs_len + tmp > f->precision)
		{
			f->precision = bigs_len;
			break ;
		}
		bigs_len += tmp;
		list = list->next;
	}
}

char			*precision_handle_sS(t_format *f, char *str)
{
	int		len;
	char	*new_str;

	len = (int)ft_strlen(str);
	if (f->precision >= len || f->precision <= 0)
		return (str);
	if (f->conversion->c == 'S')
		handle_big_s(f);
	new_str = ft_strsub(str, 0, f->precision);
	ft_strdel(&str);
	return (new_str);
}
