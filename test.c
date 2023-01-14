#include "test.h"

int	main()
{
	t_data *data;

	data = malloc(sizeof(*data));
	data->pl_or = (Coor4f){0.0, 0.0, 100.0, 0};
	data->pl_dir = (Coor4f){0.0, 1.0, 0.0, 0};
	data->r_or = (Coor4f){0.0, 0.0, 0.0, 0};
	data->r_dir = (Coor4f){0.0, 0.0, 0.8, 0};
	
	float a;
	float b;
	float c;
	Coor4f n = (Coor4f){((data->pl_dir.s0 + 1) * data->pl_or.s0), ((data->pl_dir.s1 + 1) * data->pl_or.s1), ((data->pl_dir.s2 + 1) * data->pl_or.s2), 0};
	Coor4f h = (Coor4f){0, 0, 10000, 0};
	
	float res;
//	printf("%f %f %f\n", n.s0, n.s1, n.s2);
//	if (((data->pl_dir.s0 * data->r_dir.s0) + (data->pl_dir.s1 * data->r_dir.s1) + (data->pl_dir.s2 * data->r_dir.s2)) == 0)
//		return (printf("pas parallele\n"));
	if (data->r_dir.s0 == 0 || n.s0 == 0)
		a = 0;
	else
		a = (data->r_or.s0 - data->pl_or.s0 * n.s0) / (data->r_dir.s0 * n.s0);
	if (data->r_dir.s1 == 0 || n.s1 == 0)
		b = 0;
	else
		b = (data->r_or.s1 - data->pl_or.s1 * n.s1) / (data->r_dir.s1 * n.s1);
	if (data->r_dir.s2 == 0 || n.s2 == 0)
		c = 0;
	else
		c = (data->r_or.s2 - data->pl_or.s2 * n.s2) / (data->r_dir.s2 * n.s2);
	res = a + b + c;
	printf("%f\n", res);
	return (0);
}