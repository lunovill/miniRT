/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_period.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:51:02 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 13:36:34 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fg_period(const char *s, int **ftab, unsigned int *flag, va_list args)
{
	(*ftab)[PERIOD] = ft_atrkornb(s, &*flag, args);
	if (!((*ftab)[PERIOD]))
		(*ftab)[BE_PRD] = 1;
	else
		(*ftab)[BE_PRD] = 0;
	return ;
}
