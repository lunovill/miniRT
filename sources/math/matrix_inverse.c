#include "libmt.h"
#include <stdio.h>

static float minor(float m[3][3], int row, int colum)
{
	int a[2];
	int b[2];
	int c[2];
	int d[2];

	a[0] = 0;
	a[1] = 0;
	if (a[0] == row)
		a[0]++;
	if (a[1] == colum)
		a[1]++;
	b[0] = a[0] + 1;
	if (b[0] == row)
		b[0]++;
	b[1] = a[1];
	c[0] = a[0];
	c[1] = a[1] + 1;
	if (c[1] == colum)
		c[1]++;
	d[0] = b[0];
	d[1] = c[1];
	
	return (m[a[1]][a[0]] * m[d[1]][d[0]] - m[b[1]][b[0]] * m[c[1]][c[0]]);
}

static void submatrix(float mtx[4][4], float (*m)[3][3], int row, int colum)
{
	int i;
	int j;
	int x;
	int y;
	
	y = 0;
	j = 0;
	while (y < 4)
	{
		x = 0;
		i = 0;
		if (y != colum)
		{
			while (x < 4)
			{
				if (x != row)
				{
					(*m)[j][i] = mtx[y][x];
					i++;
				}
				x++;
			}
			j++;
		}
		y++;
	}
}

static float determinant(float mtx[4][4])
{
	float	d;
	float	m[3][3];

	submatrix(mtx, &m, 0, 0);
	d = mtx[0][0] * (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]);
	submatrix(mtx, &m, 1, 0);	
	d += mtx[0][1] * -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]);
	submatrix(mtx, &m, 2, 0);	
	d += mtx[0][2] * (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]);
	submatrix(mtx, &m, 3, 0);	
	d += mtx[0][3] * -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]);
	return (d);
}

static void	inverse(Matrix4f *ivs, float mtx[4][4], float d)
{
	float	m[3][3];

	if (d == 0.0)
		(*ivs) = (Matrix4f){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	else
	{
		submatrix(mtx, &m, 0, 0);
		(*ivs).s0 = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 0, 1);
		(*ivs).s1 = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 0, 2);
		(*ivs).s2 = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 0, 3);
		(*ivs).s3 = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 1, 0);
		(*ivs).s4 = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 1, 1);
		(*ivs).s5 = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 1, 2);
		(*ivs).s6 = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 1, 3);
		(*ivs).s7 = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 2, 0);
		(*ivs).s8 = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 2, 1);
		(*ivs).s9 = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 2, 2);
		(*ivs).sa = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 2, 3);
		(*ivs).sb = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 3, 0);
		(*ivs).sc = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 3, 1);
		(*ivs).sd = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 3, 2);
		(*ivs).se = (minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		submatrix(mtx, &m, 3, 3);
		(*ivs).sf = -(minor(m, 0, 0) * m[0][0] - minor(m, 0, 1) * m[1][0] + minor(m, 0, 2) * m[2][0]) / d;
		printf("%f\n", (*ivs).sf);
	}
}

void	mt_inverse(Matrix4f *ivs, Matrix4f *mtx)
{
	float m[4][4];

	m[0][0] = (*mtx).s0;
	m[0][1] = (*mtx).s1;
	m[0][2] = (*mtx).s2;
	m[0][3] = (*mtx).s3;
	m[1][0] = (*mtx).s4;
	m[1][1] = (*mtx).s5;
	m[1][2] = (*mtx).s6;
	m[1][3] = (*mtx).s7;
	m[2][0] = (*mtx).s8;
	m[2][1] = (*mtx).s9;
	m[2][2] = (*mtx).sa;
	m[2][3] = (*mtx).sb;
	m[3][0] = (*mtx).sc;
	m[3][1] = (*mtx).sd;
	m[3][2] = (*mtx).se;
	m[3][3] = (*mtx).sf;
	inverse(&*ivs, m, determinant(m));
}
