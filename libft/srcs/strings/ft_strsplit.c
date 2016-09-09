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

#include "strings.h"

static int		count_words(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int		count_char(char *str, char c)
{
	int		count;

	count = 0;
	while (*str && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

static char		**get_array(char *str, char c)
{
	char	**array;
	int		nb_char;
	int		i;

	i = 0;
	array = ft_memalloc((sizeof(char *) * count_words(str, c) + 1));
	if (array)
	{
		while (*str)
		{
			while (*str && *str == c)
				str++;
			if (*str)
			{
				nb_char = count_char(str, c);
				array[i] = ft_memalloc((sizeof(char) * nb_char + 1));
				ft_strncpy(array[i++], str, nb_char);
				str += nb_char;
			}
		}
		array[i] = NULL;
	}
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s || !c)
		return (NULL);
	return (get_array((char *)s, c));
}
