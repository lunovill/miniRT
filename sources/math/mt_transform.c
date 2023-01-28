#include "miniRT.h"

void	mt_translate(Matrix4f *trslt, float x, float y, float z)
{
	(*trslt) = (Matrix4f){1., 0., 0., x, 0., 1., 0., y, 0., 0., 1., z, 0., 0., 0., 1.};
}

void	mt_scale(Matrix4f *scale, float x, float y, float z)
{
	(*scale) = (Matrix4f){x, 0., 0., 0., 0., y, 0., 0., 0., 0., z, 0., 0., 0., 0., 1.};
}

void	mt_shear(Matrix4f *shear, float x[2], float y[2], float z[2])
{
	(*shear) = (Matrix4f){1., x[0], x[1], 0., y[0], 1., y[1], 0., z[0], z[1], 1., 0., 0., 0., 0., 1.};
}