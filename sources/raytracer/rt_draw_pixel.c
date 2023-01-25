#include "miniRT.h"

void	rt_draw_pixel(t_mlx *mlx, Tuple4f coor, int color)
{
    float x;
    float y;

    // x = coor.x;
    // y = coor.y;
    x = (coor.x / coor.w + 1.) * (float)mlx->wrslt / 2.;
    y = (coor.y / coor.w + 1.) * (float)mlx->hrslt / 2.;
    // printf("%f %f\n", x, y);
	if (!(0 <= x && x < mlx->wrslt && 0 <= y && y < mlx->hrslt))
		return ;
    mlx_put_pixel(mlx->scene, x, y, color);
    // exit (42);
}