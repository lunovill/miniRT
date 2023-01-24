#include "libmt.h"

void	mt_croos_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2)
{
	(*result).s0 = dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s048c);
	(*result).s1 = dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s159d);
	(*result).s2 = dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s26ae);
	(*result).s3 = dot((Tuple4f)(*m1).s0123, (Tuple4f)(*m2).s37bf);
	(*result).s4 = dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s048c);
	(*result).s5 = dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s159d);
	(*result).s6 = dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s26ae);
	(*result).s7 = dot((Tuple4f)(*m1).s4567, (Tuple4f)(*m2).s37bf);
	(*result).s8 = dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s048c);
	(*result).s9 = dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s159d);
	(*result).sa = dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s26ae);
	(*result).sb = dot((Tuple4f)(*m1).s89ab, (Tuple4f)(*m2).s37bf);
	(*result).sc = dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s048c);
	(*result).sd = dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s159d);
	(*result).se = dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s26ae);
	(*result).sf = dot((Tuple4f)(*m1).scdef, (Tuple4f)(*m2).s37bf);
}

Tuple4f	mt_cross_tp(Matrix4f *m, Tuple4f t)
{
	Tuple4f	result;

	result.x = dot((Tuple4f)(*m).s0123, t);
	result.x = dot((Tuple4f)(*m).s4567, t);
	result.x = dot((Tuple4f)(*m).s89ab, t);
	result.x = dot((Tuple4f)(*m).scdef, t);
	return (result);
}

void    mt_rotate_x(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f rx = (Matrix4f){1., 0., 0., 0.,
		0., cosf(theta), -sinf(theta), 0.,
		0., sinf(theta), cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rx);
}

void    mt_rotate_y(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f ry = (Matrix4f){cosf(theta), 0., sinf(theta), 0.,
		0., 1., 0., 0.,
		-sinf(theta), 0., cosf(theta), 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &ry);
}

void    mt_rotate_z(Matrix4f *dst, float theta)
{
	Matrix4f src = *dst;
	Matrix4f rz = (Matrix4f){cosf(theta), -sinf(theta), 0., 0.,
		sinf(theta), cosf(theta), 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.};
	mt_cross_mt(&*dst, &src, &rz);
}