#include <math.h>
#include <stdio.h>

typedef float Vector4f __attribute__((ext_vector_type(4)));
typedef float Coor4f __attribute__((ext_vector_type(4)));
typedef float Matrix4f __attribute__((ext_vector_type(16)));

typedef struct s_matix
{
	Vector4f	vx;
	Vector4f	vy;
	Vector4f	vz;
	Coor4f		c;
}               t_matrix;

t_matrix ft(Coor4f c, Vector4f v, Matrix4f *a)
{
    t_matrix m;
    m.vx = v;
    m.vy = v;
    m.vz = v;
    m.c = c;
    (*a).x = 0;
    return (m);
}

int main()
{
    Matrix4f a;
    t_matrix m;
    Coor4f c = {1,2,3,4};
    Vector4f v = {5,6,7,8};

    m = ft(c, v, &a);
    return 0;
}
