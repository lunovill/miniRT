/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:15:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/29 12:03:22 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_withprd(char *p, int *ftab, size_t sconv, size_t size)
{
	size += ft_field(ftab[FIELD], ftab[PERIOD] + 2, size);
	size += ft_field(ftab[ZERO], ftab[PERIOD] + 2, size);
	ft_putstr("0x");
	size += ft_zero(ftab[PERIOD], sconv - 2, size);
	if (sconv - 2)
		ft_putstr(p);
	size += ft_field(ftab[HYPHEN], ftab[PERIOD] + 2, size);
	return (size);
}

size_t	ft_convp(int *ftab, va_list args, size_t size)
{
	char	*p;
	size_t	sconv;

	p = ft_xtoa((unsigned long long)va_arg(args, unsigned long long));
	sconv = 2;
	if (!(p[0] == '0'))
		sconv += ft_strlen(p);
	if ((ftab[BE_PRD] != 1) && (size_t)ftab[PERIOD] <= sconv - 2)
	{
		if (!(sconv - 2))
			sconv++;
		size += ft_field(ftab[FIELD], sconv, size);
		ft_putstr("0x");
		size += ft_zero(ftab[ZERO], sconv, size);
		ft_putstr(p);
		size += ft_field(ftab[HYPHEN], sconv, size);
	}
	else
		ft_withprd(p, ftab, sconv, size);
	free(p);
	return (size + sconv);
}
