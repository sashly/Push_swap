/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <sashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:11:36 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:44:46 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, \
			size_t len);
int				ft_atoi(const char *nptr);

char			*ft_strdup(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_isspace(int c);
char			*ft_strndup(const char *s, int len);
void			ft_strrev(char *str, int len);
int				ft_strcmp(char *s1, char *s2);
int				ft_str_is_alpha(char *str);
int				ft_str_is_numeric(char *str);
char			*ft_strupcase(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int				get_next_line(int fd, char **line);

int				ft_atoi_positive_safe(const char *nptr);
int				ft_atoi_check(const char *nptr, int *out);
void			ft_putstr3(char *s1, char *s2, char *s3);

char			**ft_split_charset(char *str, char *charset);

int				ft_split_free(char **split, int ret);
int				ft_split_size(char **split);
void			ft_split_print(char **split);

int				ft_max2i(int a, int b);
void			ft_quick_sort(int *nums, int nums_size);
int				ft_log2(unsigned int nbr);
int				ft_is_pow2(int nbr);

void			ft_putendl_fd_col(char *s, char *col, int fd);
void			ft_putstr_fd_col(char *s, char *col, int fd);

#endif
