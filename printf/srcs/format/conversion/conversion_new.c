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

#include "conversion.h"

static void		conversion_set_handlers(t_conversion *c)
{
	c->func[0] = conversion_handle_s;
}

t_conversion	*conversion_new(char *str)
{
	t_conversion	*c;

	c = ft_memalloc(sizeof(c));
	if (!c)
		return (NULL);
	c->conversion = conversion_get(str);
	c->func_index = conversion_get_func_index(c->conversion);
	conversion_set_handlers(c);
	return (c);
}
