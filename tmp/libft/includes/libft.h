/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:16:55 by lunovill          #+#    #+#             */
/*   Updated: 2022/10/09 09:10:51 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"
# include "gbg_collector.h"
# define BUFFER_SIZE 42

void			ft_bzero(void *s, size_t n);
void			ft_foreach(int *tab, size_t len, void (*f)(int));
void			ft_free(void *zone);
void			ft_ftab(char **tab);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

int				ft_abs(int n);
int				ft_atoi(const char *str);
int				ft_count_if(char **tabs, int (*f)(char *));
int				ft_display_file(const char *file);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isset(int c, const char *set);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				get_next_line(int fd, char **line, int set);

unsigned int	ft_atoui(const char *str);

size_t			ft_putnbr(int n);
size_t			ft_putnbr_fd(int n, int fd);
size_t			ft_putstr(const char *s);
size_t			ft_putstr_fd(const char *s, int fd);
size_t			ft_putsub(char const *s, unsigned int start, size_t len);
size_t			ft_putunbr(unsigned int n);
size_t			ft_putunbr_fd(unsigned int n, int fd);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
size_t			ft_tablen(const char **tab);

ssize_t			ft_strichr(const char *s, int c);
ssize_t			ft_strirchr(const char *s, int c);
ssize_t			ft_strischr(const char *s, const char *set);

void			*ft_calloc(size_t count, size_t size);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_realloc(void *ptr, size_t size);

char			*ft_itoa(int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinf(char *s1, char *s2, int set);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t size);
char			*ft_strndup(const char *s1, size_t size);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hstck, const char *ndle, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strrchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_uitoa(unsigned int n);
char			*ft_xtoa(unsigned long long ptr);

char			**ft_split(const char *s, char c);
char			**ft_tabdup(const char **tab);

#endif
