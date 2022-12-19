#include "miniRT.h"

// static void	ft_view_pl(t_camera *c, t_plane *pl)
// {
// 	float			x;
// 	float			y;
// 	float			z;
// 	float			w;

// 	x = pl->orgc.x * c->view.s0 + pl->orgc.y * c->view.s4 + pl->orgc.z * c->view.s8 + pl->orgc.w * c->view.sc;
// 	y = pl->orgc.x * c->view.s1 + pl->orgc.y * c->view.s5 + pl->orgc.z * c->view.s9 + pl->orgc.w * c->view.sd;
// 	z = pl->orgc.x * c->view.s2 + pl->orgc.y * c->view.s6 + pl->orgc.z * c->view.sa + pl->orgc.w * c->view.se;
// 	w = pl->orgc.x * c->view.s3 + pl->orgc.y * c->view.s7 + pl->orgc.z * c->view.sb + pl->orgc.w * c->view.sf;
// 	pl->camc.xyzw = (Coor4f){x, y, z, w};
// }

// static void	ft_view_cy(t_camera *c, t_cylinder *cy)
// {
// 	float			x;
// 	float			y;
// 	float			z;
// 	float			w;

// 	x = cy->orgc.x * c->view.s0 + cy->orgc.y * c->view.s4 + cy->orgc.z * c->view.s8 + cy->orgc.w * c->view.sc;
// 	y = cy->orgc.x * c->view.s1 + cy->orgc.y * c->view.s5 + cy->orgc.z * c->view.s9 + cy->orgc.w * c->view.sd;
// 	z = cy->orgc.x * c->view.s2 + cy->orgc.y * c->view.s6 + cy->orgc.z * c->view.sa + cy->orgc.w * c->view.se;
// 	w = cy->orgc.x * c->view.s3 + cy->orgc.y * c->view.s7 + cy->orgc.z * c->view.sb + cy->orgc.w * c->view.sf;
// 	cy->camc.xyzw = (Coor4f){x, y, z, w};
// }

void	rt_camcoor(t_miniRT *main)
{
	Matrix4f		transform;
	unsigned int	i;

	mt_cross_mt(&transform, &main->c->view, &main->c->prspct);
	i = 0;
	if (main->sp)
		while(main->sp[i])
		{
			cr_cross_mt(&main->sp[i]->camc, main->sp[i]->orgc, &transform);
			i++;
		}
	// i = 0;
	// if (main->pl)
	// 	while(main->pl[i])
	// 		ft_view_pl(main->c, main->pl[i++]);
	// i = 0;
	// if (main->cy)
	// 	while(main->cy[i])
	// 		ft_view_cy(main->c, main->cy[i++]);
}