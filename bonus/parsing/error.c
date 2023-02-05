#include "miniRT.h"

void	gestion_error(t_miniRT *data, int i)
{
	printf("Error\n");
	if (i == 1)
		printf("Parsing\n");
	if (i == 2)
		printf("fill\n");
	gbg_remove(data->garbage);
	free(data);
	exit(EXIT_FAILURE);
}
