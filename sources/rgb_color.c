/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:38:27 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:38:30 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
