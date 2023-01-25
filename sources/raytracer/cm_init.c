#include "miniRT.h"

void	cm_view(Matrix4f *view, Tuple4f coor, Tuple4f vector)
{
	
	(*view).s0123 = vt_cross(vector, (Tuple4f){0., 1., 0., 0.});
	(*view).s4567 = vt_cross((Tuple4f)(*view).s0123, vector);
	(*view).s89ab = -vector;
	(*view).scdef = (Tuple4f){0., 0., 0., 1.};
(void)coor;
}

// void	mt_perspective(Matrix4f *prspct, t_camera *c, float window)
// {
// 	float	f;
	
// 	f = 1. / tanf(c->fov / 2);
// 	(*prspct).s0123 = (Tuple4f){f / window, 0., 0., 0.};
// 	(*prspct).s4567 = (Tuple4f){0., f, 0., 0.};
// 	(*prspct).s89ab = (Tuple4f){0., 0., -(c->far + c->near) / (c->far - c->near), -1.};
// 	(*prspct).scdef = (Tuple4f){0., 0., -(2. * c->far * c->near) / (c->far - c->near), 0.};
// }

// void	mt_projection(Matrix4f *prjt, t_camera *c, float window)
// {
// 	float	f;
	
// 	f = 1.0 / tanf(c->fov / 2.0);
// 	(*prjt).s0123 = (Tuple4f){tanf(c->fov / 2.0) * window , 0.0, 0.0, 0.0};
// 	(*prjt).s4567 = (Tuple4f){0.0, tanf(c->fov / 2.0 * window), 0.0, 0.0};
// 	(*prjt).s89ab = (Tuple4f){0.0, 0.0, -1.0, 0.0};
// 	(*prjt).scdef = (Tuple4f){0.0, 0.0, 0.0, 1.0};
// }
