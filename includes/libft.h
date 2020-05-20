/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:42:11 by alzaynou          #+#    #+#             */
/*   Updated: 2020/02/12 10:56:48 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
*** includes
*/

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

/*
*** macros
*/

# define U_CHAR unsigned char
# define U_INT unsigned int

/*
*** data struct
*/
typedef struct		s_list
{
	void		*content;
	size_t		content_size;
	struct s_list	*next;
}			t_list;

/*
*** functions convert
*/

char			*ft_ltoa(long int n);
char			*ft_lltoa(long long int n);
long			ft_atol(char *str);
long			ft_atol_all(char *str);
long long		ft_atoll(char *str);
long long		ft_atoll_all(char *str);
int			ft_atoi_all(char *str);
int			ft_all_digit(char *str);
char			*ft_itoa(int n);
int			ft_atoi(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi_base(const char *str, int str_base);
int			ft_power(int nbr, int power);
char			*ft_itoa_base(int value, int base);

/*
*** functions count
*/

size_t			ft_strlen(const char *s);
int			ft_intlen(long long int n);
size_t			ft_strnlen(char *str, char *c);
int			ft_count_char(char *str, char c);
int			count_words(char *str, char *c);
int			**start_end_words(char *str, char *c);

/*
*** functions edit
*/

void			ft_bzero(void *s, size_t n);
void			remove_last_sapce(char *str);
size_t			ft_skip_char(char *str, char *c);
void			ft_strclr(char *s);

/*
*** functions is
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

/*
*** functions lst
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
*** functions mem
*/

void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);

/*
*** functions put
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
*** functions srch
*/

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
			size_t len);
int			ft_strchrstr(char *str, char *c);

/*
*** functions str
*/

char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strndup(const char *str, char c);
char			**ft_split_by_str(char *str, char *c);

/*
*** functions free
*/

void			ft_free_rev(void **tab, int len);
void			ft_free_tab_char(char **tab);
void			ft_strdel(char **as);

#endif
