/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:24:34 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/17 12:16:54 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_xtoupper(char *x)
{
	unsigned int	i;

	i = 0;
	while (x[i])
	{
		x[i] = ft_toupper(x[i]);
		i++;
	}
	return (x);
}

static size_t	ft_withprd(char *n, int *ftab, size_t sconv, size_t size)
{
	if (ftab[BE_PRD])
	{
		ftab[FIELD] -= sconv;
		ftab[ZERO] -= sconv;
	}
	size += ft_field(ftab[FIELD], ftab[PERIOD], size);
	size += ft_field(ftab[ZERO], ftab[PERIOD], size);
	size += ft_zero(ftab[PERIOD], sconv, size);
	if (sconv)
		ft_putstr(n);
	if (ftab[PERIOD])
		size += ft_field(ftab[HYPHEN], ftab[PERIOD], size);
	else
		size += ft_field(ftab[HYPHEN], sconv, size);
	return (size);
}

static char	*ft_n(va_list args, int conv)
{
	char	*n;

	if (conv == 'u')
		n = ft_uitoa((unsigned int)va_arg(args, unsigned int));
	else
		n = ft_xtoa((unsigned int)va_arg(args, unsigned int));
	return (n);
}

size_t	ft_convn(int *ftab, va_list args, size_t size, int conv)
{
	char	*n;
	size_t	sconv;

	n = ft_n(args, conv);
	sconv = 0;
	if (!((n[0] == '0') && (ftab[BE_PRD])))
		sconv = ft_strlen(n);
	if (conv == 'X')
		n = ft_xtoupper(n);
	if (!(ftab[BE_PRD]) && (size_t)ftab[PERIOD] <= sconv)
	{
		size += ft_field(ftab[FIELD], sconv, size);
		if (ftab[ZERO] && !(ftab[PERIOD]))
			size += ft_zero(ftab[ZERO], sconv, size);
		else
			size += ft_field(ftab[ZERO], sconv, size);
		if (sconv)
			ft_putstr(n);
		size += ft_field(ftab[HYPHEN], sconv, size);
	}
	else
		size = ft_withprd(n, ftab, sconv, size);
	free(n);
	return (size + sconv);
}
