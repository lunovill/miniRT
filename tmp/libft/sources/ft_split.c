/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:14:30 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:25:27 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lwords(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size++;
			while (*s && *s != c)
				s++;
		}
	}
	return (size);
}

static size_t	ft_lchar(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static char	**ft_issplit(const char *s, char c, char **tabs, size_t wsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < wsize)
	{
		while (*s && *s == c)
			s++;
		tabs[i] = (char *)malloc(sizeof(char) * (ft_lchar(s, c) + 1));
		if (!(tabs[i]))
			return (NULL);
		while (*s && *s != c)
			tabs[i][j++] = *s++;
		tabs[i++][j] = '\0';
		j = 0;
	}
	tabs[i] = 0;
	return (tabs);
}

char	**ft_split(const char *s, char c)
{
	size_t			wsize;
	char			**tabs;

	if (!s || !c)
		return (NULL);
	wsize = ft_lwords(s, c);
	tabs = (char **)malloc(sizeof(char *) * (wsize + 1));
	if (!tabs)
		return (NULL);
	return (ft_issplit(s, c, tabs, wsize));
}
