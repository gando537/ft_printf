/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:03:10 by mdiallo           #+#    #+#             */
/*   Updated: 2021/01/23 09:24:12 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void				*ft_memset(void *pointer, int value, size_t size);
void				ft_bzero(void *pointer, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memchr(const void *mem_block, \
					int search_char, size_t size);

int					ft_memcmp(const void *p1, const void *p2, size_t size);
void				*ft_calloc(size_t element_count, size_t element_size);

char				*ft_strdup(const char *src);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strchr(const char *str, int search_char);
char				*ft_strrchr(const char *str, int search_char);
char				*ft_strnstr(const char *str, \
					const char *substr, size_t size);
int					ft_strncmp(const char *first, \
					const char *second, size_t length);

size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_toupper(int car);
int					ft_tolower(int car);
char				*ft_strtrim(char const *s, char const *set);

int					ft_isalpha(int car);
int					ft_isdigit(int car);
int					ft_isalnum(int car);
int					ft_isascii(int car);
int					ft_isprint(int car);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, \
					void *(*f)(void *), void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
