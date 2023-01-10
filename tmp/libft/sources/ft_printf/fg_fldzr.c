/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_fldzr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:14:33 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 09:24:08 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fg_fldzr(const char *s, int **ftab, unsigned int *flag, va_list args)
{
	if (s[*flag] == '0')
	{
		(*ftab)[ZERO] = ft_atrkornb(s, &*flag, args);
		(*ftab)[BE_FDZ] = (*ftab)[ZERO];
		if ((*ftab)[ZERO] && (*ftab)[BE_HPH])
			(*ftab)[HYPHEN] = (*ftab)[ZERO];
	}
	else
	{
		(*ftab)[FIELD] = ft_atrkornb(s, &*flag, args);
		(*ftab)[BE_FDZ] = (*ftab)[FIELD];
		if ((*ftab)[FIELD] && (*ftab)[BE_HPH])
			(*ftab)[HYPHEN] = (*ftab)[FIELD];
	}
	return ;
}
