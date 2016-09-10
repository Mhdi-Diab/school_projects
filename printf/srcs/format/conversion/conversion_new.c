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
// # define CONVERSION_FORMAT "sSpdDioOuUxXcC"
static void		conversion_set_handlers(t_conversion *c)
{
	c->func[0] = conversion_handle_s;
	c->func[1] = conversion_handle_big_s;
	c->func[2] = conversion_handle_p;
	c->func[3] = conversion_handle_d;
	c->func[4] = conversion_handle_d;
	c->func[5] = conversion_handle_d;
	c->func[6] = conversion_handle_o;
	c->func[7] = conversion_handle_o;
	c->func[8] = conversion_handle_u;
	c->func[9] = conversion_handle_u;
	c->func[10] = conversion_handle_x;
	c->func[11] = conversion_handle_x;
	c->func[12] = conversion_handle_c;
	c->func[13] = conversion_handle_c; //TODO: a remplacer
}

t_conversion	*conversion_new(char *str)
{
	t_conversion	*c;

	c = ft_memalloc(sizeof(*c));
	if (!c)
		return (NULL);
	c->conversion = conversion_get(str);
	c->func_index = conversion_get_func_index(c->conversion);
	conversion_set_handlers(c);
	return (c);
}
