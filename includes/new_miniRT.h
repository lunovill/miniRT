typedef float Matrix4f __attribute__((ext_vector_type(4*4)));
typedef float Vector4f __attribute__((ext_vector_type(4)));
typedef float Coor4f __attribute__((ext_vector_type(4)));

#include <stdio.h>
#include <stdlib.h>

typedef struct          s_camera
{
    Coor4f              coor;
    Vector4f            vector;
    Matrix4f            matrix;
    float               FOV;
}                       t_camera;

typedef struct          s_light
{
    Coor4f              coor;
    float               brightness;
    int                 color;
    struct s_light      *next;
}                       t_light;

typedef struct          s_sphere
{
    Coor4f              coor;
    float               rayon;
    int                 color;
    struct s_sphere     *next;
}                       t_sphere;

typedef struct          s_plane
{
    Coor4f              coor;
    Vector4f            vector;
    int                 color;
    struct s_plane      *next;
}                        t_plane;

typedef struct          s_cylinder
{
    Coor4f              coor;
    Vector4f            vector;
    float               rayon;
    float               height;
    int                 color;
    struct s_cylinder   *next;
}                       t_cylinder;

typedef struct          s_miniRT
{
//    t_mlx               *mlx;
    t_camera            *c;
    t_light             **l;
    t_sphere            **sp;
    t_plane             **pl;
    t_cylinder          **cy;
//    t_garbage           *garbage;
}                       t_miniRT;

/***********FONCTION**************/

t_miniRT	*init();