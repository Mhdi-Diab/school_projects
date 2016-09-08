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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "array.h"
# include "ctype.h"
# include "linked_list.h"
# include "string.h"

# define BUFF_SIZE 100

typedef struct		s_buffer
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
}					t_buffer;

int					get_next_line(int fd, char **line);

#endif
