/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 12:55:00 by atamano           #+#    #+#             */
/*   Updated: 2014/12/29 12:55:01 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	if (s[0] != 0 && s[0] != c)
		words++;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

static int	w_len(char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != 0 && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

void		ft_split1(char **array, char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*str != 0)
	{
		if (*str == c)
			str++;
		else
		{
			array[i] = (char *)malloc(w_len(str, c) + 1);
			if (array[i])
			{
				while (*str != c && *str != 0)
					array[i][j++] = *str++;
				array[i++][j] = 0;
				j = 0;
			}
		}
	}
	array[++i] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	char	*str;

	if (!s || !c)
		return (NULL);
	str = (char *)s;
	if ((array = ft_memalloc(sizeof(char *) * (ft_count_words(str, c) + 1))))
	{
		ft_split1(array, str, c);
	}
	return (array);
}
