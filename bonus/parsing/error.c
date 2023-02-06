/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:35:46 by hucoulon          #+#    #+#             */
/*   Updated: 2023/02/05 18:36:23 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"

void	gestion_error(t_miniRT *data, int i)
{
	printf("Error\n");
	if (i == 1)
		printf("Parsing\n");
	if (i == 2)
		printf("fill\n");
	gbg_remove(data->garbage);
	free(data);
	exit(EXIT_FAILURE);
}
