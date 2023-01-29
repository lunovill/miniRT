/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:37:00 by lunovill          #+#    #+#             */
/*   Updated: 2018/11/25 00:45:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(const char *s, int fd)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		ft_putchar_fd(s[size++], fd);
	return (size);
}
