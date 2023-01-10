/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:33:37 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/17 12:21:27 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVS "cspdiuxX%"
# define FLAGS "-0.*"
# define NFLAGS 7
# define FIELD 0
# define ZERO 1
# define HYPHEN 2
# define PERIOD 3
# define BE_FDZ 4
# define BE_HPH 5
# define BE_PRD 6
# include "libft.h"
# include <stdarg.h>

int		fg_check(const char *s);
void	fg_fldzr(const char *s, int **ftab, unsigned int *flag, va_list args);
void	fg_hyphen(const char *s, int **ftab, unsigned int *flag, va_list args);
void	fg_period(const char *s, int **ftab, unsigned int *flag, va_list args);
int		ft_atrkornb(const char *s, unsigned int *flag, va_list args);

size_t	ft_conv(const char *s, va_list args, size_t size);
size_t	ft_convc(int *ftab, va_list args, size_t size, int conv);
size_t	ft_convs(int *ftab, va_list args, size_t size);
size_t	ft_convp(int *ftab, va_list args, size_t size);
size_t	ft_convi(int *ftab, va_list args, size_t size);
size_t	ft_convn(int *ftab, va_list args, size_t size, int conv);
size_t	ft_convpc(int *ftab, size_t size);

size_t	ft_field(int field, size_t sconv, size_t size);
size_t	ft_zero(int zero, size_t sconv, size_t size);

int		ft_printf(const char *format, ...);

#endif
