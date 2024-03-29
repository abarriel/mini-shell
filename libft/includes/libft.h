/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:11:10 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:44:22 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
int					len_tab(char **t1);
char				**concat_tab(char **t1, char **t2);
int					print_table(char **tab);
unsigned int		chatohi(unsigned char *str);
unsigned int		chatoi(unsigned char *str);
int					cmp_4_oct(unsigned char *one, unsigned char *two);
int					ft_pow_base(int x, unsigned int y);
int					btoi(int bin);
size_t				swap_st(size_t val);
unsigned short int	swap_usint(unsigned short int val);
short int			swap_sint(short int val);
unsigned int		swap_uint(unsigned int val);
int					swap_int(int val);
size_t				ft_strslen(const char *s, char *c);
size_t				ft_strlchr(char *s, int c);
char				*ft_strcchr(const char *s, int c, char stop);
size_t				ft_strclen(const char *s, char c);
char				*ft_strccpy(char *dest, const char *src, char c);
void				print_memory(const void *addr, size_t size);
char				*ft_strndup(const char *s, size_t i);
int					ft_strrncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrcpy(char *s);
int					ext(const char *message, int i);
void				free_tab(char **tab);
int					ft_sdigit(char *c);
long				ft_atol(const char *str);
int					ft_atoi_p(char **s);
int					ft_pow(int s1);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *l, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_sqrt(int nb);
size_t				ft_strnlen(const char *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int star, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s1, char c);
int					ft_recursive_factorial(int nb);
char				*ft_itoa(int n);
char				*ft_litoa(long int n);
char				*ft_luitoa(unsigned long int n);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(long int n, int nb_base, int i);
char				*ft_itoa_base_neg(unsigned int n, int nb_base, int i);
char				*ft_litoa_base_neg(unsigned long int n, int nb_base, int i);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					count_bits(unsigned int nbr);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *c);
void				ft_swap(int *a, int *b);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(wchar_t *c);
void				ft_exit(const char *message);
long				ft_max(long nb1, long nb2);
long				ft_min(long nb1, long nb2);

#endif
