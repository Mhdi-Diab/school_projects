/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:02:21 by atamano           #+#    #+#             */
/*   Updated: 2015/03/24 16:10:16 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "strings.h"

typedef struct		s_atof
{
	double			integer;
	double			fraction;
	int				divisor;
	int				sign;
	int				in_fraction;
}					t_atof;

double				ft_atof(char *str);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);

#endif
