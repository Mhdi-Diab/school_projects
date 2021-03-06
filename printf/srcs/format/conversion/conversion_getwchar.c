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

	count = ft_strlen(str) / 8;
	grid = (char **)malloc(sizeof(char *) * count + 1);
	i = -1;
	while (++i < count)
		grid[i] = ft_strsub(str, i * 8, 8);
	grid[i] = NULL;
	return (grid);
}

static char		*fill_unicode_mask(char *mask, char *bin, int bin_len)
{
	int mask_len;

	mask_len = ft_strlen(mask) - 1;
	bin_len -= 1;
	while (bin_len >= 0 && mask_len >= 0)
	{
		if (mask[mask_len] == 'x')
			mask[mask_len--] = bin[bin_len--];
		else
			mask_len--;
	}
	while (mask_len >= 0)
	{
		if (mask[mask_len] == 'x')
			mask[mask_len] = '0';
		mask_len--;
	}
	return (mask);
}

char			*get_wchart_string(char **grid)
{
	char	*str;
	int		grid_len;
	int		len;
	int		index;

	index = 0;
	len = 0;
	grid_len = ft_tablen(grid);
	str = ft_memalloc(sizeof(char) * (grid_len + 1));
	while (index < grid_len)
	{
		str[index] = ft_binary_string_to_decimal(grid[index]);
		index++;
	}
	str[index] = 0;
	return (str);
}

static char		**get_octal_strings(char *bin)
{
	int		index;
	int		bin_len;
	char	**tab;

	tab = ft_memalloc(sizeof(char *) * 5);
	tab[0] = ft_strdup("0xxxxxxx");
	tab[1] = ft_strdup("110xxxxx10xxxxxx");
	tab[2] = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	tab[3] = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	tab[4] = NULL;
	bin_len = ft_strlen(bin);
	index = bin_len / 7;
	tab[index] = fill_unicode_mask(tab[index], bin, bin_len);
	return (split_octal(tab[index]));
}

char			*conversion_getwchar(wint_t wchar)
{
	char			**grid;
	char			*bin;
	char			*str;
	char			buf[2];
	unsigned int	i;

	i = (unsigned int)wchar;
	bin = ft_get_binary_string(i);
	ft_bzero(buf, 2);
	if (ft_strlen(bin) < 8)
	{
		buf[0] = i;
		return (ft_strdup(buf));
	}
	grid = get_octal_strings(bin);
	if (grid)
	{
		str = get_wchart_string(grid);
		ft_strdel(&bin);
		return (str);
	}
	ft_tabdel(grid);
	return (NULL);
}
