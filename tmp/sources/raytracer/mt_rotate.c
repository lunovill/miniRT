#include "miniRT.h"

void    mt_rotate_x(t_mtx4f *dst, float theta)
{
	t_mtx4f src = *dst;
	t_mtx4f rx = (t_mtx4f){1., 0., 0., 0.,
		0., cosf(theta), sinf(theta), 0.,
		0., -sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rx);
}

void    mt_rotate_y(t_mtx4f *dst, float theta)
{
	t_mtx4f src = *dst;
	t_mtx4f ry = (t_mtx4f){cosf(theta), 0., -sinf(theta), 0.,
		0., 1., 0., 0.,
		sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &ry);
}

void    mt_rotate_z(t_mtx4f *dst, float theta)
{
	t_mtx4f src = *dst;
	t_mtx4f rz = (t_mtx4f){cosf(theta), sinf(theta), 0., 0.,
		-sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rz);
}