#include "miniRT.h"

int trgb_color(Color4f color)
{
    int t = color.x;
    int r = color.y;
    int g = color.z;
    int b = color.w;

    return (t << 24 | r << 16 | g << 8 | b);
}