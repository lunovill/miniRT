#include "miniRT.h"

int trgb_color(Tuple4f color)
{
    int r;
    int g;
    int b;

    // color.yzw *= color.x;
    r = color.y;
    g = color.z;
    b = color.w;
    return ((r << 16 | g << 8 | b));
}