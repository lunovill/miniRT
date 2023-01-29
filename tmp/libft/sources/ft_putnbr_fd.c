/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:45:03 by lunovill          #+#    #+#             */
/*   Updated: 2018/11/26 21:08:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		size++;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		size++;
	}
	else
	{
		size += ft_putnbr_fd(n / 10, fd) + 1;
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (size);
}
