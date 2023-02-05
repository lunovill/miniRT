/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxRT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:16:02 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/22 20:16:04 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXRT_H
# define MLXRT_H

# include <X11/keysymdef.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define WD_WIDTH 750
# define WD_HEIGHT 750

# define K_Home 65360
# define K_End 65367

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sline;
	int		endian;
}				t_data;

typedef struct s_key
{
	int	up;
	int	left;
	int	down;
	int	right;
	int rot_up;
	int rot_down;
	int rot_right;
	int rot_left;
	int befor;
	int behind;
	int less;
	int more;
}				t_key;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	t_data	*scene;
	int		wrslt;
	int		hrslt;
	t_key	*key;
	int		color;
}				t_mlx;

void	mlx_put_pixel(t_data *img, int x, int y, int color);
void	mlx_close(t_mlx *mlx);
int		mlx_key_release(int keycode, t_mlx *mlx);
t_key	*mlx_init_key(void);
t_mlx	*mlx_init_window(char *window_name, int width, int height);

#endif
