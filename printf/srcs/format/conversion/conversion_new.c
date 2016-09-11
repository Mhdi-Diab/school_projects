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
	c->func[13] = conversion_handle_big_c;
}

t_conversion	*conversion_new(char *str)
{
	t_conversion	*conversion;

	conversion = ft_memalloc(sizeof(*conversion));
	if (!conversion)
		return (NULL);
	conversion->c = conversion_parse(str);
	conversion->func_index = conversion_parse_func_index(conversion->c);
	conversion_set_handlers(conversion);
	return (conversion);
}
