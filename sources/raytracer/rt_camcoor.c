#include "miniRT.h"

void	rt_camcoor(t_miniRT *data)
{
	unsigned int	i;

	i = 0;
	if (data->sp)
		while(data->sp[i])
		{
			cr_cross_mt(&data->sp[i]->camc, data->sp[i]->orgc, &data->c->trsfrm);
			i++;
		}
	// i = 0;
	// if (data->pl)
	// 	while(data->pl[i])
	// 		ft_view_pl(data->c, data->pl[i++]);
	// i = 0;
	// if (data->cy)
	// 	while(data->cy[i])
	// 		ft_view_cy(data->c, data->cy[i++]);
}