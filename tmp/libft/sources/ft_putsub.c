/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:52:49 by lunovill          #+#    #+#             */
/*   Updated: 2021/03/12 16:59:33 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putsub(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	if (!s || ft_strlen((char *)s) < start)
		return (0);
	while (s[start] && len--)
	{
		ft_putchar(s[start++]);
		size++;
	}
	return (size);
}
