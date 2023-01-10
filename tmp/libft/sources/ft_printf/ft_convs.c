/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:16:26 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/15 06:42:23 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convs(int *ftab, va_list args, size_t size)
{
	char	*s;
	size_t	sconv;

	s = ft_strdup((char *)va_arg(args, char *));
	if (s == NULL)
		s = ft_strdup("(null)");
	if (ftab[BE_PRD])
		sconv = 0;
	else
	{
		if (!(ftab[PERIOD]) || (ft_strlen(s) < (size_t)ftab[PERIOD]))
			sconv = ft_strlen(s);
		else
			sconv = (size_t)ftab[PERIOD];
	}
	size += ft_field(ftab[FIELD], sconv, size);
	size += ft_zero(ftab[ZERO], sconv, size);
	ft_putsub(s, 0, sconv);
	size += ft_field(ftab[HYPHEN], sconv, size);
	free(s);
	return (size + sconv);
}
