/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:08:59 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/03 20:40:43 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convc(int *ftab, va_list args, size_t size, int conv)
{
	size += ft_field(ftab[FIELD], 1, size);
	size += ft_zero(ftab[ZERO], 1, size);
	if (conv == '%')
		ft_putchar('%');
	else
		ft_putchar((char)va_arg(args, int));
	size += ft_field(ftab[HYPHEN], 1, size);
	return (size + 1);
}
