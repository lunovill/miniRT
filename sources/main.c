#include "miniRT.h"

int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	i = i - 3;
	if (str[i] == '.')
	{
		if (str[i + 1] == 'r')
		{
			if (str[i + 2] == 't')
			{
				if (str[i - 1] == '/')
					return (0);
				return (1);
			}
		}
	}
	return (0);
}

// int main()
// {
// 	t_miniRT *data;
// 	data  = malloc(sizeof(t_miniRT));
// 	data->garbage = NULL;
// 	// Camera
// 	data->c = malloc(sizeof(t_camera));
// 	data->garbage = gbg_add(data->garbage, data->c);
// 	data->c->coor = (Coor4f){0.0, 0.0, 0.0, 1.0};
// 	data->c->vector = (Vector4f){0.0, 0.0, 1.0, 0.0};
// 	data->c->fov = 160.0 * M_PI / 180.0;
// 	// Lumiere Ambiante
// 	data->l = malloc(sizeof(t_light *) * 5);
// 	data->garbage = gbg_add(data->garbage, data->l);
// 	data->l[0] = malloc(sizeof(t_light));
// 	data->garbage = gbg_add(data->garbage, data->l[0]);
// 	data->l[0]->color = (Color4f){0.5, 255.0, 255.0, 255.0};
// 	// Lumiere Verte
// 	data->l[1] = malloc(sizeof(t_light));
// 	data->garbage = gbg_add(data->garbage, data->l[1]);
// 	data->l[1]->coor = (Coor4f){0.0, 0.0, 100.0};
// 	data->l[1]->color = (Color4f){0.6, 255.0, 255.0, 255.0};
// 	// // Lumiere Rouge
// 	// data->l[2] = malloc(sizeof(t_light));
// 	// data->garbage = gbg_add(data->garbage, data->l[2]);
// 	// data->l[2]->coor = (Coor4f){50.0, -50.0, 25.0};
// 	// data->l[2]->color = (Color4f){0.6, 255.0, 0.0, 0.0};
// 	// // Lumiere Blanche
// 	// data->l[3] = malloc(sizeof(t_light));
// 	// data->garbage = gbg_add(data->garbage, data->l[3]);
// 	// data->l[3]->coor = (Coor4f){0.0, 0.0, 500.0};
// 	// data->l[3]->color = (Color4f){0.5, 255.0, 255.0, 255.0};
// 	data->l[2] = NULL;
// 	// Plan
// 	data->pl = malloc(sizeof(t_plane *) * 2);
// 	data->garbage = gbg_add(data->garbage, data->pl);
// 	data->pl[0] = malloc(sizeof(t_plane));
// 	data->garbage = gbg_add(data->garbage, data->pl[0]);
// 	data->pl[0]->coor = (Coor4f){0.0, -100.0, -100.0, 1.0};
// 	data->pl[0]->vector = (Vector4f){0.0, 1.0, 0.0, 0.0};
// 	data->pl[0]->color = (Color4f){1.0, 255.0, 255.0, 255.0};
// 	data->pl[1] = NULL;
// 	// Sphere 0
// 	data->sp = malloc(sizeof(t_sphere *) * 15);
// 	data->garbage = gbg_add(data->garbage, data->sp);
// 	data->sp[0] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[0]);
// 	data->sp[0]->coor = (Coor4f){0.0, 0.0, 25.0, 1.0};
// 	data->sp[0]->rayon = 10.0;
// 	data->sp[0]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 1
// 	data->sp[1] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[1]);
// 	data->sp[1]->coor = (Coor4f){-50.0, 50.0, 25.0, 1.0};
// 	data->sp[1]->rayon = 10.0;
// 	data->sp[1]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 2
// 	data->sp[2] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[2]);
// 	data->sp[2]->coor = (Coor4f){0.0, 50.0, 25.0, 1.0};
// 	data->sp[2]->rayon = 10.0;
// 	data->sp[2]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 3
// 	data->sp[3] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[3]);
// 	data->sp[3]->coor = (Coor4f){50.0, 50.0, 25.0, 1.0};
// 	data->sp[3]->rayon = 10.0;
// 	data->sp[3]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 4
// 	data->sp[4] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[4]);
// 	data->sp[4]->coor = (Coor4f){-50.0, 0.0, 25.0, 1.0};
// 	data->sp[4]->rayon = 10.0;
// 	data->sp[4]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Shpere 5
// 	data->sp[5] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[5]);
// 	data->sp[5]->coor = (Coor4f){50.0, 0.0, 25.0, 1.0};
// 	data->sp[5]->rayon = 10.0;
// 	data->sp[5]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 6
// 	data->sp[6] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[6]);
// 	data->sp[6]->coor = (Coor4f){-50, -50.0, 25.0, 1.0};
// 	data->sp[6]->rayon = 10.0;
// 	data->sp[6]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 7
// 	data->sp[7] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[7]);
// 	data->sp[7]->coor = (Coor4f){0.0, -50.0, 25.0, 1.0};
// 	data->sp[7]->rayon = 10.0;
// 	data->sp[7]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 8
// 	data->sp[8] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[8]);
// 	data->sp[8]->coor = (Coor4f){50.0, -50.0, 25.0, 1.0};
// 	data->sp[8]->rayon = 10.0;
// 	data->sp[8]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 9
// 	data->sp[9] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[9]);
// 	data->sp[9]->coor = (Coor4f){50.0, 25.0, 50.0};
// 	data->sp[9]->rayon = 10.0;
// 	data->sp[9]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 3
// 	data->sp[10] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[10]);
// 	data->sp[10]->coor = (Coor4f){25.0, 25.0, 50.0};
// 	data->sp[10]->rayon = 10.0;
// 	data->sp[10]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 4
// 	data->sp[11] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[11]);
// 	data->sp[11]->coor = (Coor4f){-50.0, 0.0, 50.0};
// 	data->sp[11]->rayon = 10.0;
// 	data->sp[11]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Shpere 5
// 	data->sp[12] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[12]);
// 	data->sp[12]->coor = (Coor4f){25.0, 0.0, 50.0};
// 	data->sp[12]->rayon = 10.0;
// 	data->sp[12]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// 	// Sphere 6
// 	data->sp[13] = malloc(sizeof(t_sphere));
// 	data->garbage = gbg_add(data->garbage, data->sp[13]);
// 	data->sp[13]->coor = (Coor4f){-25.0, -25.0, 50.0};
// 	data->sp[13]->rayon = 10.0;
// 	data->sp[13]->color = (Color4f){1.0, 0.0, 0.0, 255.0};
// //	data->sp[9] = NULL;
// 	minirt(data);
// 	return (0);
// }

//comment fonctionne la fct pour rgb en detail


int	main(int argc, char **argv)
{
	t_miniRT	*data;

	if (argc != 2 || (check_name(argv[1]) == 0))
	{
		printf("Error\nBad arguments\n");
		return (0);
	}
	data = init_minirt();
	if	(parsing(data, argv[1]) != 0)
	{
		printf("Error parsing\n");
		gestion_error(data);
	}
	if (fill_struct(data, argv[1]) != 0)
	{
		printf("Error filling\n");
		gestion_error(data);
	}
	minirt(data);
	return (0);
}