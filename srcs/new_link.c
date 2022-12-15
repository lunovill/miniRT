#include "../includes/new_miniRT.h"

t_light	*new_link_light(Coor4f coor, Vector4f vec, Matrix4f mat, float FOV)
{
	t_light	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	else
	{
		link->coor = coor;
		link->vector = vec;
		link->matrix = mat;
		link->FOV = FOV;
	}
	return (link);
}

t_sphere	*new_link_sphere(Coor4f coor, float rayon, int color)
{
	t_sphere	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	else
	{
		link->coor = coor;
		link->rayon = rayon;
		link->color = color;
	}
	return (link);
}

t_plane	*new_link_plane(Coor4f coor, Vector4f vec, int color)
{
	t_plane	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	else
	{
		link->coor = coor;
		link->vector = vec;
		link->color = color;
	}
	return (link);
}

t_cylinder	*new_link_cylinder(Coor4f coor, Vector4f vec, float rayon, float height, int color)
{
	t_cylinder	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	else
	{
		link->coor = coor;
		link->vector = vec;
		link->rayon = rayon;
		link->height = height;
		link->color = color;
	}
	return (link);
}