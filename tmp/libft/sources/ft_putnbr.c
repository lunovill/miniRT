/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:09:05 by lunovill          #+#    #+#             */
/*   Updated: 2018/11/26 21:21:21 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr(int n)
{
	size_t	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		size++;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		size++;
	}
	else
	{
		size += ft_putnbr(n / 10) + 1;
		ft_putchar(n % 10 + '0');
	}
	return (size);
}
