/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 04:25:39 by lunovill          #+#    #+#             */
/*   Updated: 2018/12/01 00:36:26 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, size_t len, void (*f)(int))
{
	unsigned int	i;

	if (!tab || !f || len == 0)
		return ;
	i = 0;
	while (i < len)
		f(tab[i++]);
}
