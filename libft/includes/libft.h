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

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 100

typedef enum		e_rb_color
{
	RB_BLACK,
	RB_RED
}					t_rb_color;

typedef struct		s_atof
{
	double			integer;
	double			fraction;
	int				divisor;
	int				sign;
	int				in_fraction;
}					t_atof;

typedef enum		e_str_color
{
	BOLD,
	BLACK,
	RED,
	GREEN,
	BROWN,
	MAGENTA,
	CYAN,
	GRAY,
	BLUE,
	NONE
}					t_str_color;

typedef struct		s_buffer
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
}					t_buffer;

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	char			*index;
	char			*content;
	enum e_rb_color	color;
}					t_btree;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_circ
{
	char			*data;
	struct s_circ	*prev;
	struct s_circ	*next;
}					t_circ;

double				ft_atof(char *str);
int					ft_lst_size(t_list *list);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *dst, const char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				ft_putnbr(int n);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
void				ft_print_tab(char **tab);
void				ft_sort_params(char **argv);
void				ft_strswap(char **s1, char **s2);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				rb_insert(t_btree **r, char *index, char *str,
	int (*cmp)(char *, char *));
void				btree_search(t_btree *r, char *k,
	int (*cmp)(char *, char *), t_list **list);
t_btree				*btree_create_node(char *index, char *data);
void				tree_insert(t_btree **root, t_btree *x,
	int (*cmp)(char *, char *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_merge_sort(t_list **begin, int (*f)(void *, void *));
t_circ				*circ_get_arg(char **arg);
void				circ_push_back(t_circ **begin, char *data);
t_circ				*circ_create(char *data);
int					ft_tabsize(char **tab);
void				ft_putcstr(char *str, t_str_color color);
void				ft_putcolor_fd(int fd, char *str, t_str_color color);
int					ft_tablen(char **tab);
void				circ_push_front(t_circ **begin, char *data);
void				ft_tabdel(char **tab);
int					get_next_line(int fd, char **line);

#endif
