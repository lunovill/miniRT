#include "miniRT.h"

int trgb_color(Tuple4f color)
{
    int t = color.x;
    int r = color.y;
    int g = color.z;
    int b = color.w;

    return (t * (r << 16 | g << 8 | b));
}