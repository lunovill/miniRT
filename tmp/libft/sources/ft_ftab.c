/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:48:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/18 14:31:51 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ftab(char **tab)
{
	unsigned int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	ft_free(tab);
}
