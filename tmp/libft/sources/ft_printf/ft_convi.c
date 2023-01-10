/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:24:34 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 13:50:42 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_withoutprd(char *i, int *ftab, size_t sconv, size_t size)
{
	size += ft_field(ftab[FIELD], sconv, size);
	if (ftab[ZERO] && ftab[PERIOD])
		size += ft_field(ftab[ZERO], sconv, size);
	if (i[0] == '-')
		ft_putchar(*i++);
	if (ftab[ZERO] && !(ftab[PERIOD]))
		size += ft_zero(ftab[ZERO], sconv, size);
	if (sconv)
		ft_putstr(i);
	size += ft_field(ftab[HYPHEN], sconv, size);
	return (size);
}

static size_t	ft_withprd(char *i, int *ftab, size_t sconv, size_t size)
{
	if (ftab[BE_PRD])
	{
		ftab[FIELD] -= sconv;
		ftab[ZERO] -= sconv;
	}
	size += ft_field(ftab[FIELD], ftab[PERIOD], size);
	size += ft_field(ftab[ZERO], ftab[PERIOD], size);
	if (i[0] == '-')
	{
		ft_putchar(*i++);
		ftab[HYPHEN]--;
	}
	size += ft_zero(ftab[PERIOD], sconv, size);
	if (sconv)
		ft_putstr(i);
	if (ftab[PERIOD])
		size += ft_field(ftab[HYPHEN], ftab[PERIOD], size);
	else
		size += ft_field(ftab[HYPHEN], sconv, size);
	return (size);
}

size_t	ft_convi(int *ftab, va_list args, size_t size)
{
	char	*i;
	size_t	sconv;

	i = ft_itoa((int)va_arg(args, int));
	if ((i[0] == '0') && ftab[BE_PRD])
		sconv = 0;
	else
		sconv = ft_strlen(i);
	if ((i[0] == '-') && ((size_t)ftab[PERIOD] > sconv - 1))
	{
		sconv -= 1;
		ftab[FIELD]--;
		ftab[ZERO]--;
		size++;
	}
	if (ftab[BE_PRD] && (i[0] == '-'))
		ftab[HYPHEN] += 1;
	if (!(ftab[BE_PRD]) && (size_t)ftab[PERIOD] <= sconv)
		size = ft_withoutprd(i, ftab, sconv, size);
	else
		size = ft_withprd(i, ftab, sconv, size);
	free(i);
	return (size + sconv);
}
