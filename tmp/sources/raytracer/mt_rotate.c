#include "miniRT.h"

void    mt_rotate_x(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f rx = (Matrix4f){1., 0., 0., 0.,
		0., cosf(theta), sinf(theta), 0.,
		0., -sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rx);
}

void    mt_rotate_y(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f ry = (Matrix4f){cosf(theta), 0., -sinf(theta), 0.,
		0., 1., 0., 0.,
		sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &ry);
}

void    mt_rotate_z(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f rz = (Matrix4f){cosf(theta), sinf(theta), 0., 0.,
		-sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rz);
}