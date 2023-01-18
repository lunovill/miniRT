/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbg_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:13:32 by lunovill          #+#    #+#             */
/*   Updated: 2023/01/03 02:13:39 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gbg_collector.h"

t_garbage	*gbg_add(t_garbage *first, void *zone)
{
	t_garbage	*add;

	add = malloc(sizeof(t_garbage));
	if (!add)
		return (gbg_remove(first), NULL);
	add->zone = zone;
	add->next = first;
	return (add);
}

void	gbg_remove(t_garbage *remove)
{
	t_garbage	*next;

	while (remove)
	{
		next = remove->next;
		free(remove->zone);
		free(remove);
		remove = next;
	}
}
