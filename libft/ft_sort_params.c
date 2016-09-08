/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:41:02 by atamano           #+#    #+#             */
/*   Updated: 2014/11/06 14:42:22 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params(char **argv)
{
	int i;
	int flag;

	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		i = 0;
		while (argv[i + 1])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) == 1)
			{
				ft_strswap(&argv[i], &argv[i + 1]);
				flag = 0;
			}
			i++;
		}
	}
}
