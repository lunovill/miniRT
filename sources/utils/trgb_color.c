#include "miniRT.h"

int trgb_color(Tuple4f color)
{
    int t;
    int r;
    int g;
    int b;

    t = color.x;
    r = color.y;
    g = color.z;
    b = color.w;
    return ((r << 16 | g << 8 | b) * t);
}