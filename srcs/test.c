#include "../includes/new_miniRT.h"
#include <stdlib.h>
#include <stdio.h>

int		main()
{
/*	Coor4f	test;
	test = (Coor4f){1.0, 2.0, 3.0, 4.0};
//	printf("%f\n%f\n%f\n%f\n", test.x, test.y, test.z, test.w);
//	printf("%f\n", test.x);
	t_miniRT	*ok;

	ok = malloc(sizeof(*ok));
	if (!ok)
		return (0);
	t_camera	*test3;
	test3->coor = (Coor4f){9.0, 10.0, 11.0, 12.0};
	printf("%f\n%f\n%f\n%f\n", test3->coor.x, test3->coor.y, test3->coor.z, test3->coor.w);
	Coor4f test2;
	test2 = (Coor4f){5.0, 6.0, 7.0, 8.0};
	printf("%f\n%f\n%f\n%f\n", test2.x, test2.y, test2.z, test2.w);
	ok->c->coor = test2;
//	ok->c->coor = (Coor4f){1.0, 2.0, 3.0, 4.0};
//	printf("%f\n", ok->c->coor.x);*/
//	t_miniRT	ok;

//	ok = malloc(sizeof(ok));
//	if (!ok)
//		return (0);
//	ok.c->coor = (Coor4f){1.0, 2.0, 3.0, 4.0};
//	printf("%f\n%f\n%f\n%f\n", ok.c->coor.x, ok.c->coor.y, ok.c->coor.z, ok.c->coor.w);
	t_miniRT	*test;

	test = malloc(sizeof(*test));
	if (!test)
		return (0);
	t_camera	*camera;
	camera = malloc(sizeof(*camera));
	test->c = camera;
	test->c->matrix = (Matrix4f){1.0, 2.0, 3.0, 4.0};
	test->c->matrix = (Matrix4f){1.0, 2.0, 3.0, 4.0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
//	test->c->matrix = (Matrix4f){1.0, 2.0, 3.0, 4.0}{0, 0, 0, 0}{0, 0, 0, 0}{0, 0, 0, 0};
	printf("%f\n", test->c->matrix.sd);
//	printf("%f\n%f\n%f\n%f\n", test->c->matrix.x, test->c->matrix.x, test->c->matrix.x, test->c->matrix.x);
	return (0);
}