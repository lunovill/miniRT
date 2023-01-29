/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:09:43 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 06:38:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_field(int field, size_t sconv, size_t size)
{
	if ((field < 0) || ((size_t)field <= sconv)
		|| (field >= 2147483647 - (int)size))
		return (0);
	field -= (int)sconv;
	size = field;
	while (field--)
		ft_putchar(' ');
	return (size);
}
