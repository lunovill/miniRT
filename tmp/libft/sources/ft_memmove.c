/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:13:13 by lunovill          #+#    #+#             */
/*   Updated: 2021/02/23 16:40:56 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpd;
	char	*tmps;

	if (!dst && !src)
		return (NULL);
	tmpd = (char *)dst;
	tmps = (char *)src;
	while (len--)
	{
		if (tmps < tmpd)
			tmpd[len] = tmps[len];
		else
			*tmpd++ = *tmps++;
	}
	return (dst);
}
