#include "../includes/miniRT.h"

void	gestion_error(t_miniRT *data)
{
	printf("Error suppression\n");
	free(data);
	gbg_remove(data->garbage);
	exit(EXIT_FAILURE);
}