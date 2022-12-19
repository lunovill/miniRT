#include "../includes/new_miniRT.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_miniRT	*miniRT;

	if (argc != 2)
	{
		printf("Error\nBad number of arguments\n");
		return (0);
	}
	miniRT = init();
	if (parsing(miniRT, argv[1]) == -1)
		return (0);
//	printf("%f\n%f\n%f\n%f\n", miniRT->c->coor.x, miniRT->c->coor.y, miniRT->c->coor.z, miniRT->c->coor.w);
	return (0);
} 