/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:40:06 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/21 05:40:08 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	rt_print_error(int code_error)
{
	if (code_error == ERROR_MALLOC)
		ft_putstr_fd(" malloc: memory allocation failure\n", 2);
	if (code_error == ERROR_MLX)
		ft_putstr_fd(" mlx: window initialization failed\n", 2);
}

int	rt_free(t_miniRT *main, int code_error)
{
	if (code_error)
		rt_print_error(code_error);
	if (main)
	{
		gbg_remove(main->garbage);
		mlx_close(main->mlx);
	}
	ft_free(main);
	return (exit(code_error), 0);
}
