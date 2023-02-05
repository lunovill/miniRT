#include "miniRT.h"

void	cm_init(Matrix4f *view, Tuple4f coor, Tuple4f vector)
{
	
	(*view).s0123 = vt_cross(vector, (Tuple4f){0., 1., 0., 0.});
	(*view).s0123 = vt_normalize((*view).s0123);
	(*view).s4567 = vt_cross((Tuple4f)(*view).s0123, vector);
	(*view).s4567 = vt_normalize((Tuple4f)(*view).s4567);
	(*view).s89ab = vector;
	(*view).s37bf = coor;
	(*view).scdef = (Tuple4f){0., 0., 0., 1.};
}
