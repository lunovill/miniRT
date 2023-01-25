#include "libmt.h"

void    mt_rotate_x(Matrix4f *rx, float theta)
{
	(*rx) = (Matrix4f){1., 0., 0., 0.,
		0., cosf(theta), -sinf(theta), 0.,
		0., sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
}

void    mt_rotate_y(Matrix4f *ry, float theta)
{
	(*ry) = (Matrix4f){cosf(theta), 0., sinf(theta), 0.,
		0., 1., 0., 0.,
		-sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
}

void    mt_rotate_z(Matrix4f *rz, float theta)
{
	(*rz) = (Matrix4f){cosf(theta), -sinf(theta), 0., 0.,
		sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
}
