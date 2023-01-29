/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strischr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:33:26 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/04 20:47:50 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strischr(const char *s, const char *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != set[j])
	{
		j++;
		if (set[j] == '\0')
		{
			j = 0;
			i++;
		}
	}
	if (s[i] == set[j])
		return (i);
	return (-1);
}
