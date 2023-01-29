/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:09:43 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 06:39:33 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_zero(int zero, size_t sconv, size_t size)
{
	if ((zero < 0) || ((size_t)zero <= sconv)
		|| (zero >= 2147483647 - (int)size))
		return (0);
	zero -= (int)sconv;
	size = zero;
	while (zero--)
		ft_putchar('0');
	return (size);
}
