#include "libmt.h"

bool	equalf(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (True);
	return (False);
}

bool	equalt(Tuple4f a, Tuple4f b)
{
	if (equalf(a.x, b.x) && equalf(a.y, b.y) && equalf(a.z, b.z))
		return (True);
	return (False);
}

bool	equalm(Matrix4f m1, Matrix4f m2)
{
	if (equalt((Tuple4f)m1.s0123, m2.s0123) && equalt((Tuple4f)m1.s4567, m2.s4567) && equalt((Tuple4f)m1.s89ab, m2.s89ab) && equalt((Tuple4f)m1.scdef, m2.scdef))
		return (True);
	return (False);
}