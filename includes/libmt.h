#ifndef LIBMT_H
# define LIBMT_H

# include <math.h>

// Cette valeur correspond a FLT_MAX de la lib <float.h>
# define INF 340282346638528859811704183484516925440.0
# define EPSILON 0.00001
# define True 1
# define False 0
#define	bool int

typedef float Tuple4f __attribute__((ext_vector_type(4)));
typedef float Matrix4f __attribute__((ext_vector_type(4*4)));


bool	equalf(float a, float b);
bool	equalt(Tuple4f a, Tuple4f b);
bool	equalm(Matrix4f m1, Matrix4f m2);

float	magnitude(Tuple4f vector);
Tuple4f	normalize(Tuple4f vector);
float	dot(Tuple4f u, Tuple4f v);
Tuple4f	cross(Tuple4f u, Tuple4f v);

void	mt_cross_mt(Matrix4f *result, Matrix4f *m1, Matrix4f *m2);
Tuple4f	mt_cross_tp(Matrix4f *m, Tuple4f t);
void	mt_inverse(Matrix4f *ivs, Matrix4f *mtx);

#endif