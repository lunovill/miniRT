#include "miniRT.h"

void	mt_view(t_mtx4f *view, Coor4f coor, Vector4f vector)
{
	Vector4f	Up;

	// (*view).s0123 = (Vector4f){-vector.z, 0., vector.x, 0.};
	(*view).s0123 = (Vector4f){vector.z, 0., -vector.x, 0.};
	cross_product(&Up, vector, (*view).s0123);
	normalize(&Up);
	(*view).s4567 = Up;
	(*view).s89ab = vector;
	(*view).scdef = coor;
	// (*view).scdef = (Coor4f){-((*view).s0 * coor.x + (*view).s1 * coor.y + (*view).s2 * coor.z + (*view).s3 * coor.w),
	// 	-((*view).s4 * coor.x + (*view).s5 * coor.y + (*view).s6 * coor.z + (*view).s7 * coor.w),
	// 	-((*view).s8 * coor.x + (*view).s9 * coor.y + (*view).sa * coor.z + (*view).sb * coor.w),
	// 	1.};
}

// void	mt_perspective(t_mtx4f *prspct, t_camera *c, float window)
// {
// 	float	f;
	
// 	f = 1. / tanf(c->fov / 2);
// 	(*prspct).s0123 = (Vector4f){f / window, 0., 0., 0.};
// 	(*prspct).s4567 = (Vector4f){0., f, 0., 0.};
// 	(*prspct).s89ab = (Vector4f){0., 0., -(c->far + c->near) / (c->far - c->near), -1.};
// 	(*prspct).scdef = (Vector4f){0., 0., -(2. * c->far * c->near) / (c->far - c->near), 0.};
// }

void	mt_projection(t_mtx4f *prjt, t_camera *c, float window)
{
	float	f;
	
	f = 1.0 / tanf(c->fov / 2.0);
	(*prjt).s0123 = (Vector4f){tanf(c->fov / 2.0) * window , 0.0, 0.0, 0.0};
	(*prjt).s4567 = (Vector4f){0.0, tanf(c->fov / 2.0 * window), 0.0, 0.0};
	(*prjt).s89ab = (Vector4f){0.0, 0.0, -1.0, 0.0};
	(*prjt).scdef = (Vector4f){0.0, 0.0, 0.0, 1.0};
}
