#include "miniRT.h"

int trgb_color(Tuple4f color)
{
    int r;
    int g;
    int b;

    color.yzw *= 255.;
	color.y = (color.y > 255.) ? 255. : color.y;
	color.z = (color.z > 255.) ? 255. : color.z;
	color.w = (color.w > 255.) ? 255. : color.w;
    r = color.y;
    g = color.z;
    b = color.w;
    return (r << 16 | g << 8 | b);
}