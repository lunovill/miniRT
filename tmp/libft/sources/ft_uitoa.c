/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:44:50 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:57:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
{
	size_t	size;
	char	*nb;

	size = ft_size(n);
	nb = (char *)malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	nb[size--] = '\0';
	if (n == 0)
		nb[0] = '0';
	while (n)
	{
		nb[size--] = n % 10 + '0';
		n /= 10;
	}
	return (nb);
}
