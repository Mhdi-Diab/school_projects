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

static char		**split_octal(char *str)
{
	int		count;
	char	**grid;
	int		i;

	i = -1;
	count = ft_strlen(str) / 8;
	grid = (char **)malloc(sizeof(char *) * (count + 1));
	if (grid)
	{
		while (++i < count)
			grid[i] = ft_strsub(str, i * 8, (i + 1) * 8);
		grid[i] = NULL;
	}
	return (grid);
}

static char		*fill_unicode_mask(char *mask, char *bin, int bin_len)
{
	int mask_len;

	mask_len = ft_strlen(mask);
	while (--bin_len >= 0 && --mask_len >= 0)
	{
		if (mask[mask_len] == 'x')
			mask[mask_len] = bin[bin_len];
	}
	while (mask_len >= 0)
	{
		if (mask[mask_len] == 'x')
			mask[mask_len] = '0';
		mask_len--;
	}
	return (mask);
}

static int		print_wchart(char **grid)
{
	int grid_len;
	int index;

	index = 0;
	grid_len = ft_tablen(grid);
	while (index < grid_len)
	{
		ft_putchar(ft_binary_string_to_decimal(grid[index]));
		index++;
	}
	return (index);
}

static char		**get_octal_strings(char *bin)
{
	int		index;
	int		bin_len;
	char	*tab[] = {
		"0xxxxxxx",
		"110xxxxx10xxxxxx",
		"1110xxxx10xxxxxx10xxxxxx",
		"11110xxx10xxxxxx10xxxxxx10xxxxxx"
	};

	bin_len = ft_strlen(bin);
	index = bin_len % 7;
	tab[index] = fill_unicode_mask(tab[index], bin, bin_len);
	return (split_octal(tab[index]));
}

int				ft_putwchar(wint_t wchar)
{
	char			**grid;
	char			*bin;
	int				print_len;

	print_len = 0;
	bin = ft_get_binary_string((unsigned int)wchar);
	grid = get_octal_strings(bin);
	if (grid)
	{
		print_len = print_wchart(grid);
		ft_strdel(&bin);
	}
	ft_tabdel(grid);
	return (print_len);
}
