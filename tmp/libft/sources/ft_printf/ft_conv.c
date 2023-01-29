/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:39:25 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/17 12:03:41 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*tb_negatif(int *ftab)
{
	if (ftab[FIELD] < 0)
	{
		ftab[HYPHEN] = ft_abs(ftab[FIELD]);
		ftab[FIELD] = 0;
	}
	if (ftab[ZERO] < 0)
	{
		ftab[HYPHEN] = ft_abs(ftab[ZERO]);
		ftab[ZERO] = 0;
	}
	ftab[HYPHEN] = ft_abs(ftab[HYPHEN]);
	if (ftab[PERIOD] < 0)
	{
		ftab[PERIOD] = 0;
		ftab[BE_PRD] = 0;
	}
	return (ftab);
}

static int	*tb_param(const char *s, size_t conv, va_list args)
{
	unsigned int	flag;
	int				*ftab;

	flag = 0;
	ftab = (int *)ft_memalloc(sizeof(int) * NFLAGS);
	while (flag < conv)
	{
		if (s[flag] == '*' || (ft_isdigit(s[flag]) && (s[flag] != '0')))
			fg_fldzr(s, &ftab, &flag, args);
		else if (s[flag] == '0')
			fg_fldzr(s, &ftab, &flag, args);
		else if (s[flag] == '-')
			fg_hyphen(s, &ftab, &flag, args);
		else if (s[flag] == '.')
			fg_period(s, &ftab, &flag, args);
	}
	if (ftab[BE_HPH])
	{
		ftab[ZERO] = 0;
		ftab[FIELD] = 0;
	}
	ftab = tb_negatif(ftab);
	return (ftab);
}

static size_t	ft_convall(int *ftab, va_list args, char c, size_t size)
{
	if (c == 'c' || c == '%')
		size = ft_convc(ftab, args, size, c);
	else if (c == 's')
		size = ft_convs(ftab, args, size);
	else if (c == 'p')
		size = ft_convp(ftab, args, size);
	else if (c == 'd' || c == 'i')
		size = ft_convi(ftab, args, size);
	else if (c == 'x' || c == 'X' || c == 'u')
		size = ft_convn(ftab, args, size, c);
	return (size);
}

size_t	ft_conv(const char *s, va_list args, size_t size)
{
	size_t	len;
	int		*ftab;
	ssize_t	start;

	start = ft_strichr(s, '%');
	while (start != -1)
	{
		size += ft_putsub(s, 0, start);
		start++;
		len = start + ft_strischr(s + start, CONVS);
		ftab = tb_param(s + start, len - start, args);
		size = ft_convall(ftab, args, s[len], size);
		free(ftab);
		s += len + 1;
		start = ft_strichr(s, '%');
	}
	return (size + ft_putstr(s));
}
