/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:45:01 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/06 16:13:55 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndle, size_t len)
{
	if (*ndle == '\0')
		return ((char *)hstck);
	while (*hstck && len-- >= ft_strlen(ndle))
	{
		if (*hstck == *ndle)
			if (ft_strncmp(hstck, ndle, ft_strlen(ndle)) == 0)
				return ((char *)hstck);
		hstck++;
	}
	return (NULL);
}
