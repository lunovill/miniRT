#include "../includes/new_miniRT.h"

void	init_camera(t_miniRT *miniRT)
{
	t_camera	*camera;

	camera = malloc(sizeof(*camera));
	if (!camera)
		return ;
	camera->coor = (Coor4f){0, 0, 0, 1};
	camera->vector = (Vector4f){0, 0, 0, 0};
	camera->matrix = (Matrix4f){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	camera->FOV = -1;
	miniRT->c = camera;
}

t_miniRT	*init()
{
	t_miniRT	*miniRT;
	miniRT = malloc(sizeof(*miniRT));
	if (!miniRT)
		return (NULL);
	init_camera(miniRT);
	miniRT->l = NULL;
	miniRT->sp = NULL;
	miniRT->pl = NULL;
	miniRT->cy = NULL;
	return (miniRT);
}