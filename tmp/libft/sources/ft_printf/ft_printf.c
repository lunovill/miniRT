/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:19:23 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 06:40:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		check;
	size_t	size;
	va_list	args;

	size = 0;
	check = fg_check(format);
	if (check == -1)
		return (-1);
	if (check == 1)
		return (ft_putstr(format));
	va_start(args, format);
	size = ft_conv(format, args, size);
	va_end(args);
	return (size);
}
