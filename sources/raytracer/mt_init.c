#include "miniRT.h"

void	mt_view(Matrix4f *view, Coor4f coor, Vector4f vector)
{
	float	norm;

	(*view).s0123 = (Vector4f){-vector.z, 0., vector.x, 0.};
	(*view).s0123 = (Vector4f){vector.z, 0., -vector.x, 0.};
	(*view).s4567 = (Vector4f){-(*view).s2 * vector.y,
		(*view).s2 * vector.x - (*view).s0 * vector.z,
		(*view).s0 * vector.y, 0.};
	norm = sqrtf((*view).s4 * (*view).s4 + (*view).s5 * (*view).s5 + (*view).s6 * (*view).s6);
	(*view).s456 /= norm;
	(*view).s89ab = (Vector4f)vector;
	(*view).scdef = (Coor4f){-((*view).s0 * coor.x + (*view).s1 * coor.y + (*view).s2 * coor.z + (*view).s3 * coor.w),
		-((*view).s4 * coor.x + (*view).s5 * coor.y + (*view).s6 * coor.z + (*view).s7 * coor.w),
		-((*view).s8 * coor.x + (*view).s9 * coor.y + (*view).sa * coor.z + (*view).sb * coor.w),
		1.};
}

void	mt_perspective(Matrix4f *prspct, t_camera *c, float window)
{
	float	f;
	
	f = 1. / tanf(c->fov / 2);
	(*prspct).s0123 = (Vector4f){f / window, 0., 0., 0.};
	(*prspct).s4567 = (Vector4f){0., f, 0., 0.};
	(*prspct).s89ab = (Vector4f){0., 0., -(c->far + c->near) / (c->far - c->near), -1.};
	(*prspct).scdef = (Vector4f){0., 0., -(2. * c->far * c->near) / (c->far - c->near), 0.};
}
