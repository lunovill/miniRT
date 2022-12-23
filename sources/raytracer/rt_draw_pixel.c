#include "miniRT.h"

void	rt_draw_pixel(t_mlx *mlx, Coor4f coor, int color)
{
    float x;
    float y;

    x = (coor.x / coor.w + 1.) * (float)mlx->wrslt / 2.;
    y = (coor.y / coor.w + 1.) * (float)mlx->hrslt / 2.;
    printf("%f %f\n\n", x, y);
	if (!(0 <= x && x < mlx->wrslt && 0 <= y && y < mlx->hrslt))
		return ;
    mlx_put_pixel(mlx, x, y, color);
}