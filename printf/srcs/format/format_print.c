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

#include "format.h"
#include "option.h"
#include "precision.h"
#include "modifier.h"
#include "width.h"

void		format_print(t_format *f)
{
	const char	opt[] = {'#', '0', '-', '+', ' '};
	const char	*modifiers[] = {"hh", "h", "ll", "l", "j", "z"};

	PN("\n\n");
	P("Conversion: %c\n", f->conversion->conversion);
	for (int i = 0; i < NB_OPTIONS; i++) {
		if (f->options[i])
			P("Option: %c\n", opt[i]);
	}
	if (f->modifier != NO_MODIFIER)
		P("Modifier: %s\n", modifiers[f->modifier]);
	printf("Precision: %d\nWidth: %d\n", f->precision, f->width);
	PN("\n");
}
