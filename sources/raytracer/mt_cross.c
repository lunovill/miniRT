#include "miniRT.h"

void mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2)
{
	(*result).s0 = (*m1).s0 * (*m2).s0 + (*m1).s1 * (*m2).s4 + (*m1).s2 * (*m2).s8 + (*m1).s3 * (*m2).sc;
	(*result).s1 = (*m1).s0 * (*m2).s1 + (*m1).s1 * (*m2).s5 + (*m1).s2 * (*m2).s9 + (*m1).s3 * (*m2).sd;
	(*result).s2 = (*m1).s0 * (*m2).s2 + (*m1).s1 * (*m2).s6 + (*m1).s2 * (*m2).sa + (*m1).s3 * (*m2).se;
	(*result).s3 = (*m1).s0 * (*m2).s3 + (*m1).s1 * (*m2).s7 + (*m1).s2 * (*m2).sb + (*m1).s3 * (*m2).sf;
	(*result).s4 = (*m1).s4 * (*m2).s0 + (*m1).s5 * (*m2).s4 + (*m1).s6 * (*m2).s8 + (*m1).s7 * (*m2).sc;
	(*result).s5 = (*m1).s4 * (*m2).s1 + (*m1).s5 * (*m2).s5 + (*m1).s6 * (*m2).s9 + (*m1).s7 * (*m2).sd;
	(*result).s6 = (*m1).s4 * (*m2).s2 + (*m1).s5 * (*m2).s6 + (*m1).s6 * (*m2).sa + (*m1).s7 * (*m2).se;
	(*result).s7 = (*m1).s4 * (*m2).s3 + (*m1).s5 * (*m2).s7 + (*m1).s6 * (*m2).sb + (*m1).s7 * (*m2).sf;
	(*result).s8 = (*m1).s8 * (*m2).s0 + (*m1).s9 * (*m2).s4 + (*m1).sa * (*m2).s8 + (*m1).sb * (*m2).sc;
	(*result).s9 = (*m1).s8 * (*m2).s1 + (*m1).s9 * (*m2).s5 + (*m1).sa * (*m2).s9 + (*m1).sb * (*m2).sd;
	(*result).sa = (*m1).s8 * (*m2).s2 + (*m1).s9 * (*m2).s6 + (*m1).sa * (*m2).sa + (*m1).sb * (*m2).se;
	(*result).sb = (*m1).s8 * (*m2).s3 + (*m1).s9 * (*m2).s7 + (*m1).sa * (*m2).sb + (*m1).sb * (*m2).sf;
	(*result).sc = (*m1).sc * (*m2).s0 + (*m1).sd * (*m2).s4 + (*m1).se * (*m2).s8 + (*m1).sf * (*m2).sc;
	(*result).sd = (*m1).sc * (*m2).s1 + (*m1).sd * (*m2).s5 + (*m1).se * (*m2).s9 + (*m1).sf * (*m2).sd;
	(*result).se = (*m1).sc * (*m2).s2 + (*m1).sd * (*m2).s6 + (*m1).se * (*m2).sa + (*m1).sf * (*m2).se;
	(*result).sf = (*m1).sc * (*m2).s3 + (*m1).sd * (*m2).s7 + (*m1).se * (*m2).sb + (*m1).sf * (*m2).sf;
}

void    cr_cross_mt(Coor4f *result, Coor4f coor, Matrix4f *mtx)
{
	(*result).x = coor.x * (*mtx).s0 + coor.y * (*mtx).s4 + coor.z * (*mtx).s8 + coor.w * (*mtx).sc;
	(*result).y = coor.x * (*mtx).s1 + coor.y * (*mtx).s5 + coor.z * (*mtx).s9 + coor.w * (*mtx).sd;
	(*result).z = coor.x * (*mtx).s2 + coor.y * (*mtx).s6 + coor.z * (*mtx).sa + coor.w * (*mtx).se;
	(*result).w = coor.x * (*mtx).s3 + coor.y * (*mtx).s7 + coor.z * (*mtx).sb + coor.w * (*mtx).sf;
}

void	mt_cross_cr(Coor4f *result, Matrix4f *mtx, Coor4f coor)
{
	(*result).x = (*mtx).s0 * coor.x + (*mtx).s1 * coor.y + (*mtx).s2 * coor.z + (*mtx).s3 * coor.w;
	(*result).y = (*mtx).s4 * coor.x + (*mtx).s5 * coor.y + (*mtx).s6 * coor.z + (*mtx).s7 * coor.w;
	(*result).z = (*mtx).s8 * coor.x + (*mtx).s9 * coor.y + (*mtx).sa * coor.z + (*mtx).sb * coor.w;
	(*result).w = (*mtx).sc * coor.x + (*mtx).sd * coor.y + (*mtx).se * coor.z + (*mtx).sf * coor.w;
}

void cross_product(Vector4f *result, Vector4f u, Vector4f v)
{
	(*result).x = u.y * v.z - u.z * v.y;
	(*result).y = u.z * v.x - u.x * v.z;
	(*result).z = u.x * v.y - u.y * v.x;
	(*result).w = 0;
}

void normalize(Vector4f *result)
{
	float size;
	
	size = sqrtf((*result).x * (*result).x + (*result).y * (*result).y + (*result).z * (*result).z);
	(*result).xyz /= size;
}