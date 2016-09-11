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
#include "exec.h"

static void		conversion_set_handlers(t_conversion *c)
{
	c->func[0] = exec_s;
	c->func[1] = exec_big_s;
	c->func[2] = exec_p;
	c->func[3] = exec_d;
	c->func[4] = exec_d;
	c->func[5] = exec_d;
	c->func[6] = exec_o;
	c->func[7] = exec_o;
	c->func[8] = exec_u;
	c->func[9] = exec_u;
	c->func[10] = exec_x;
	c->func[11] = exec_x;
	c->func[12] = exec_c;
	c->func[13] = exec_big_c;
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
