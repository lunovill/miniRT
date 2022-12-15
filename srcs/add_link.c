#include "../includes/new_miniRT.h"

void	add_link_light(t_miniRT *miniRT, t_light *add_link)
{
	t_light	*tmp;

	if (miniRT->l == NULL)
		miniRT->l = add_link;
	else
	{
		tmp = miniRT->l;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_sphere(t_miniRT *miniRT, t_sphere *add_link)
{
	t_sphere	*tmp;

	if (miniRT->sp == NULL)
		miniRT->sp = add_link;
	else
	{
		tmp = miniRT->sp;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_plane(t_miniRT *miniRT, t_plane *add_link)
{
	t_plane	*tmp;

	if (miniRT->pl == NULL)
		miniRT->pl = add_link;
	else
	{
		tmp = miniRT->pl;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_cylinder(t_miniRT *miniRT, t_cylinder *add_link)
{
	t_cylinder	*tmp;

	if (miniRT->cy == NULL)
		miniRT->cy = add_link;
	else
	{
		tmp = miniRT->cy;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}