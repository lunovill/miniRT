#include "libmt.h"

Tuple4f	tp_rayon(t_rayon r, float t)
{
	return (r.origin + t * r.vector);
}