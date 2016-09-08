/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:18:05 by atamano           #+#    #+#             */
/*   Updated: 2014/11/06 13:21:05 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_atoi2(const char *str, int i, int value, int neg)
{
	if (!str)
		return (0);
	while ((str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\r')
			&& str[i])
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '\0' || (str[i] < '0' && str[i] > '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = str[i] - '0' + value * 10;
		i++;
	}
	return (neg == 1 ? -value : value);
}

int				ft_atoi(const char *str)
{
	return (ft_atoi2(str, 0, 0, 0));
}
