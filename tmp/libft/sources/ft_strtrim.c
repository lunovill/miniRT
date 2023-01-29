/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:59:08 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:50:11 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcmp(const char *set, const char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1)
		return (NULL);
	if (ft_strcmp(s1, "") == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_setcmp(set, s1[i]) && s1[i])
		i++;
	while (ft_setcmp(set, s1[j]) && s1[i])
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 2);
	return (str);
}
