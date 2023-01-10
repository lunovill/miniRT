/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:04:41 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:21:42 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (size == 0)
	{
		free(ptr);
		return (ft_strdup(""));
	}
	if (ptr && size <= ft_strlen(ptr))
		return (ptr);
	new = malloc(size);
	if (!new)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(new, ptr, ft_strlen(ptr));
		free(ptr);
	}
	return (new);
}
