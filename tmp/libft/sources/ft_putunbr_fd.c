/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:45:03 by lunovill          #+#    #+#             */
/*   Updated: 2018/11/26 21:08:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	size_t	size;

	size = 0;
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		size++;
	}
	else
	{
		size = ft_putunbr_fd(n / 10, fd) + 1;
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (size);
}
