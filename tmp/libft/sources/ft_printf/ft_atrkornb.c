/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atrkornb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:33:53 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 13:39:34 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atrkornb(const char *s, unsigned int *flag, va_list args)
{
	int	n;

	if (ft_isset(s[*flag], "-0."))
		(*flag)++;
	if (s[*flag] == '*')
	{
		n = (int)va_arg(args, int);
		(*flag)++;
	}
	else if (ft_isdigit(s[*flag]))
	{
		n = ft_atoi(s + *flag);
		while (ft_isdigit(s[*flag]))
			(*flag)++;
	}
	else
		n = 0;
	return (n);
}
