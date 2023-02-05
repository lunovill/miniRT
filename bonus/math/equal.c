#include "libmt.h"

int	equalf(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

int	equalt(t_tpl4f a, t_tpl4f b)
{
	if (equalf(a.x, b.x) && equalf(a.y, b.y) && equalf(a.z, b.z))
		return (TRUE);
	return (FALSE);
}

int	equalm(t_mtx4f m1, t_mtx4f m2)
{
	if (equalt((t_tpl4f)m1.s0123, m2.s0123) && equalt((t_tpl4f)m1.s4567, m2.s4567)
            && equalt((t_tpl4f)m1.s89ab, m2.s89ab) && equalt((t_tpl4f)m1.scdef, m2.scdef))
		return (TRUE);
	return (FALSE);
}
