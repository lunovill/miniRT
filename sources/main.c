#include "../includes/miniRT.h"

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
	// check all
	// check ambiant light

	// printf("check ambiant brightness : %f\n", data->l[0]->brightness);
	// printf("check ambiant orgc : %f %f %f %f\n", data->l[0]->orgc.s0, data->l[0]->orgc.s1,
	// data->l[0]->orgc.s2, data->l[0]->orgc.s3);
	// printf("check ambiant camc : %f %f %f %f\n", data->l[0]->camc.s0, data->l[0]->camc.s1,
	// data->l[0]->camc.s2, data->l[0]->camc.s3);
	// printf("check ambiant color : %d\n", data->l[0]->color);
	// // check light
	// printf("\n");

	// printf("check light brightness : %f\n", data->l[1]->brightness);
	// printf("check light orgc : %f %f %f %f\n", data->l[1]->orgc.s0, data->l[1]->orgc.s1,
	// data->l[1]->orgc.s2, data->l[1]->orgc.s3);
	// printf("check light camc : %f %f %f %f\n", data->l[1]->camc.s0, data->l[1]->camc.s1,
	// data->l[1]->camc.s2, data->l[1]->camc.s3);
	// printf("check light color : %d\n", data->l[1]->color);
	// // check cam
	// printf("\n");

    // printf("check cam vector : %f %f %f %f\n", data->c->vector.s0, data->c->vector.s1,
	// 	data->c->vector.s2, data->c->vector.s3);
    // printf("check cam coor : %f %f %f %f\n", data->c->coor.s0, data->c->coor.s1, data->c->coor.s2,
	// 	data->c->coor.s3);
    // printf("check cam matrix : %.f %.f %.f %.f / %.f %.f %.f %.f / %.f %.f %.f %.f / %.f %.f %.f %.f\n",
	// data->c->matrix.s0, data->c->matrix.s1, data->c->matrix.s2, data->c->matrix.s3,
	// data->c->matrix.s4, data->c->matrix.s5, data->c->matrix.s6, data->c->matrix.s7,
	// data->c->matrix.s8, data->c->matrix.s9, data->c->matrix.sa, data->c->matrix.sb,
	// data->c->matrix.sc, data->c->matrix.sd, data->c->matrix.se, data->c->matrix.sf);
	// printf("check cam fov : %f\n", data->c->fov);
	// // check sphere
	// printf("\n");

	// printf("check sphere rayon : %f\n", data->sp[0]->rayon);
	// printf("check sphere orgc : %f %f %f %f\n", data->sp[0]->orgc.s0, data->sp[0]->orgc.s1,
	// data->sp[0]->orgc.s2, data->sp[0]->orgc.s3);
	// printf("check sphere camc : %f %f %f %f\n", data->sp[0]->camc.s0, data->sp[0]->camc.s1,
	// data->sp[0]->camc.s2, data->sp[0]->camc.s3);
	// printf("check sphere color : %d\n", data->sp[0]->color);
	// printf("\n");
	// printf("check sphere rayon : %f\n", data->sp[1]->rayon);
	// printf("check sphere orgc : %f %f %f %f\n", data->sp[1]->orgc.s0, data->sp[1]->orgc.s1,
	// data->sp[1]->orgc.s2, data->sp[1]->orgc.s3);
	// printf("check sphere camc : %f %f %f %f\n", data->sp[1]->camc.s0, data->sp[1]->camc.s1,
	// data->sp[1]->camc.s2, data->sp[1]->camc.s3);
	// printf("check sphere color : %d\n", data->sp[1]->color);
	// // check plane
	// printf("\n");

	// printf("check plane vector : %f %f %f %f\n", data->pl[0]->vector.s0, data->pl[0]->vector.s1,
	// 	data->pl[0]->vector.s2, data->pl[0]->vector.s3);
	// printf("check plane orgc : %f %f %f %f\n", data->pl[0]->orgc.s0, data->pl[0]->orgc.s1,
	// data->pl[0]->orgc.s2, data->pl[0]->orgc.s3);
	// printf("check plane camc : %f %f %f %f\n", data->pl[0]->camc.s0, data->pl[0]->camc.s1,
	// data->pl[0]->camc.s2, data->pl[0]->camc.s3);
	// printf("check plane color : %d\n", data->pl[0]->color);
	// // check cylinder
	// printf("\n");

	// printf("check cylinder vector : %f %f %f %f\n", data->cy[0]->vector.s0, data->cy[0]->vector.s1,
	// 	data->cy[0]->vector.s2, data->cy[0]->vector.s3);
	// printf("check cylinder orgc : %f %f %f %f\n", data->cy[0]->orgc.s0, data->cy[0]->orgc.s1,
	// data->cy[0]->orgc.s2, data->cy[0]->orgc.s3);
	// printf("check cylinder camc : %f %f %f %f\n", data->cy[0]->camc.s0, data->cy[0]->camc.s1,
	// data->cy[0]->camc.s2, data->cy[0]->camc.s3);
	// printf("check cylinder color : %d\n", data->cy[0]->color);
	// printf("check cylinder diameter : %f\n", data->cy[0]->rayon);
	// printf("check cylinder height : %f\n", data->cy[0]->height);

	return (0);
}