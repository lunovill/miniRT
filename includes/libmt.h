#ifndef LIBMT_H
# define LIBMT_H

# include <math.h>

# define EPSILON 0.0001

typedef float Tuple4f __attribute__((ext_vector_type(4)));
typedef float Matrix4f __attribute__((ext_vector_type(4*4)));

typedef struct s_rayon
{
	Tuple4f	origin;
	Tuple4f	vector;
}				t_rayon;

Tuple4f	tp_rayon(t_rayon r, float t);

float	vt_magnitude(Tuple4f vector);
Tuple4f	vt_normalize(Tuple4f vector);
float	vt_dot(Tuple4f u, Tuple4f v);
Tuple4f	vt_cross(Tuple4f u, Tuple4f v);

Tuple4f	mt_cross_tp(Matrix4f *m, Tuple4f t);
void	mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2);
void	mt_inverse(Matrix4f *ivs, Matrix4f *mtx);
void    mt_rotate_x(Matrix4f *result, float theta);
void    mt_rotate_y(Matrix4f *result, float theta);
void    mt_rotate_z(Matrix4f *result, float theta);

#endif