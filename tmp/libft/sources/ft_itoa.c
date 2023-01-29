/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:15:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:17:22 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	if (n == 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_min(size_t size)
{
	char	*nb;

	nb = (char *)malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	ft_strcpy(nb, "-2147483648");
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	size;

	size = ft_size(n);
	if (n < 0)
		size++;
	if (n == -2147483648)
		return (ft_min(size));
	nb = (char *)malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	nb[size--] = '\0';
	if (n < 0)
	{
		*nb = '-';
		n *= -1;
	}
	if (n == 0)
		nb[0] = '0';
	while (n)
	{
		nb[size--] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}
