/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:11 by ibotha            #+#    #+#             */
/*   Updated: 2018/07/05 14:15:04 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 16
# define FILEFIN 0
# define ENDL 1
# define ERROR -1
# define CONTINUE 2

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *bob);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				get_next_line(const int fd, char **line);
int				ft_atoi(const char *str);
double			ft_atod(const char *str);
void			*ft_bzero(void *str, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
char			*ft_itoa_b(int n, char *base);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
int				ft_atoi_b(const char *str, const char *base);
char			*ft_itoa_b(int n, char *base);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memrcpy(void *str1, const void *str2, size_t n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_b(int n, char *base);
void			ft_putnbr_b_fd(int n, char *base, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcat(char *ret, const char *str);
char			*ft_strchr(char *str, char c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *ret, const char *str);
void			ft_strdel(char **ap);
char			*ft_strdup(const char *str);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char *s, char (*f)(char));
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *ret, const char *str, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *ret, const char *str, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_strrchr(char *str, char c);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);

#endif
