/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:02:40 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/29 12:06:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fg_check_in(const char *s, size_t size)
{
	if (!(size))
		return (0);
	while (size--)
		if ((ft_isdigit(s[size]) == 0) && (ft_isset(s[size], FLAGS) == 0))
			return (-1);
	return (0);
}

int	fg_check(const char *s)
{
	unsigned int	i;
	ssize_t			check;

	check = ft_strichr(s, '%');
	if (check == -1)
		return (1);
	i = 0;
	check = ft_strichr(s + i, '%');
	while (check != -1)
	{
		i += check + 1;
		check = ft_strischr(s + i, CONVS);
		if (check == -1 || fg_check_in(s + i, check) == -1)
			return (-1);
		i += check + 1;
		check = ft_strichr(s + i, '%');
	}
	return (0);
}
