/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:10:59 by atamano           #+#    #+#             */
/*   Updated: 2015/03/24 16:11:28 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_lstschfd(t_list **lst, int fd)
{
	t_list		*current;
	t_buffer	*buf;

	if (lst == NULL)
		return (NULL);
	current = *lst;
	while (current != NULL)
	{
		if ((buf = (t_buffer *)current->content))
		{
			if (buf->fd == fd)
				return (current);
		}
		current = current->next;
	}
	return (NULL);
}

static void		ft_read_loop2(char **line, char *n_pos,
	long *ret, t_buffer *buf)
{
	char *tmp2;

	if (n_pos && *ret > 0)
	{
		if (!(tmp2 = (char*)malloc(sizeof(char)
			* (ft_strlen(*line) + BUFF_SIZE + 1))))
		{
			*ret = -1;
			return ;
		}
		ft_bzero(tmp2, ft_strlen(*line) + BUFF_SIZE + 1);
		ft_strcat(tmp2, *line);
		ft_strncat(tmp2, buf->buf, n_pos - buf->buf);
		free(*line);
		*line = tmp2;
		tmp2 = ft_strdup(buf->buf + (n_pos - buf->buf) + 1);
		ft_bzero(buf->buf, BUFF_SIZE + 1);
		ft_memcpy(buf->buf, tmp2, ft_strlen(tmp2));
		ft_strdel(&tmp2);
	}
}

static void		ft_read_loop(char **line, int const *fd,
						long *ret, t_buffer *buf)
{
	char *n_pos;
	char *tmp;

	n_pos = NULL;
	while (*ret > 0 && !(n_pos = ft_strchr(buf->buf, '\n')))
	{
		if (!(tmp = (char*)malloc(sizeof(char)
			* (ft_strlen(*line) + BUFF_SIZE + 1))))
		{
			*ret = -1;
			return ;
		}
		ft_bzero(tmp, ft_strlen(*line) + BUFF_SIZE + 1);
		ft_strcat(tmp, *line);
		ft_strcat(tmp, buf->buf);
		free(*line);
		*line = tmp;
		ft_bzero(buf->buf, BUFF_SIZE + 1);
		*ret = read(*fd, buf->buf, BUFF_SIZE);
		if (*ret < 0)
			return ;
	}
	ft_read_loop2(line, n_pos, ret, buf);
}

static void		ft_get_line(int const *fd, char **line,
					t_list **list, long *ret)
{
	t_list			*elem;
	t_buffer		*buf;

	if (!(elem = ft_lstschfd(list, *fd)))
	{
		buf = ft_memalloc(sizeof(t_buffer));
		buf->fd = *fd;
		elem = ft_lstnew(buf, sizeof(t_buffer));
		free(buf);
		ft_bzero(((t_buffer*)(elem->content))->buf, BUFF_SIZE);
		if (list == NULL)
			list = &elem;
		else
			ft_lstadd(list, elem);
	}
	*line = (char*)malloc(BUFF_SIZE);
	ft_bzero(*line, BUFF_SIZE);
	if (!*line && (*ret = -1))
		return ;
	ft_read_loop(line, fd, ret, (t_buffer*)elem->content);
}

int				get_next_line(int const fd, char **line)
{
	long			ret;
	static t_list	*list = NULL;
	t_list			*elem;

	if (fd < 0 || !line)
		return (-1);
	ret = BUFF_SIZE;
	ft_get_line(&fd, line, &list, &ret);
	if (ret == 0 && **line != 0)
		return (1);
	else if (ret <= 0)
	{
		elem = ft_lstschfd(&list, fd);
		ft_bzero(((t_buffer*)(elem->content))->buf, BUFF_SIZE);
		((t_buffer*)(elem->content))->fd = 0;
		return (ret);
	}
	return (1);
}
