/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:09:05 by lunovill          #+#    #+#             */
/*   Updated: 2018/11/26 21:21:21 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putunbr(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n < 10)
	{
		ft_putchar(n + '0');
		size++;
	}
	else
	{
		size = ft_putunbr(n / 10) + 1;
		ft_putchar(n % 10 + '0');
	}
	return (size);
}
