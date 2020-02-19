/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:48:40 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:34:55 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "sort_algs.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/errno.h>

# define MAX_LONG		9223372036854775807
# define MAX_INTEGER	2147483647
# define MIN_INTEGER	-2147483648
# define MAX_PRECISION	2000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_word
{
	char			c;
	char			*str;
	int				pos;
	char			**res;
}					t_word;

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_itoa(int num);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_check_end_spaces(const char *s, size_t size);
size_t				ft_check_start_spaces(const char *s, size_t size);
long long int		ft_num_of_digits(long long int num);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *str, char c);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_numeric_with_spaces(char *str);
int					ft_isspace(char c);
char				*ft_convert_dec_base_to_str(int base,
		long long input_num, char sign);
int					ft_num_of_fields(long long int num);
int					ft_abs(int num);
long long			ft_atol(const char *str);
char				*ft_convert_undec_base_to_str(int base,
		unsigned long long input_num, char sign);
unsigned long long	ft_atoul(const char *str);
int					ft_unnum_of_fields(unsigned long long int num);
void				ft_putunbr(unsigned long long int nb);
void				ft_print_int_arr(int *num_arr, int in_line, size_t size);
void				ft_print_str_arr(char *arr, int in_line);
void				ft_print_pstr_arr(char **str, int in_line);
int					ft_get_number_of_substrings(char **str);
int					ft_str_is_numeric_no_spaces(char *str);
int					*ft_copy_int_arr(int *arr, size_t size);
void				ft_print_ll_arr(long long *num_arr,
					int in_line, size_t size);
void				ft_print_sizet_arr(size_t *num_arr,
					int in_line, size_t size);
int					ft_max_of_three(int a, int b, int c);
int					log2n(unsigned int n);

#endif
