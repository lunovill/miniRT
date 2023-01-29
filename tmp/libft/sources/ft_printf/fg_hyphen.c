/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_hyphen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:38:40 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/17 11:48:14 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fg_hyphen(const char *s, int **ftab, unsigned int *flag, va_list args)
{
	(*ftab)[BE_HPH] = ft_atrkornb(s, &*flag, args);
	if ((*ftab)[BE_HPH])
		(*ftab)[HYPHEN] = (*ftab)[BE_HPH];
	if (!((*ftab)[HYPHEN]) && (*ftab)[BE_FDZ])
		(*ftab)[HYPHEN] = (*ftab)[BE_FDZ];
	(*ftab)[BE_HPH]++;
	return ;
}
