/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 03:32:37 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/29 12:02:06 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(unsigned long long ptr)
{
	size_t	size;

	size = 1;
	while (ptr >= 16)
	{
		ptr /= 16;
		size++;
	}
	return (size);
}

char	*ft_xtoa(unsigned long long ptr)
{
	size_t	size;
	char	*nb;

	size = ft_size(ptr);
	nb = (char *)malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	ft_memset(nb, 48, size);
	nb[size--] = '\0';
	while (ptr)
	{
		nb[size] = ptr % 16;
		if (10 <= nb[size] && nb[size] <= 15)
			nb[size] += 87;
		else
			nb[size] += 48;
		size--;
		ptr /= 16;
	}
	return (nb);
}
