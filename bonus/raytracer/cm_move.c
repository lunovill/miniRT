#include "miniRT.h"

int cm_move(t_camera *c, t_key *key)
{
	int ret = 0;
	if (key->up == 1)
		c->view.s37bf += (Tuple4f)c->view.s456d * c->pz * 0.5, ret = 1;
	if (key->down == 1)
		c->view.s37bf -= (Tuple4f)c->view.s456d * c->pz * 0.5, ret = 1;
	if (key->right == 1)
		c->view.s37bf += (Tuple4f)c->view.s012c * c->pz * 0.5, ret = 1;
	if (key->left == 1)
		c->view.s37bf -= (Tuple4f)c->view.s012c * c->pz * 0.5, ret = 1;
	if (key->befor == 1)
		c->view.s37bf += (Tuple4f)c->view.s89ae * c->pz, ret = 1;
	if (key->behind == 1)
		c->view.s37bf -= (Tuple4f)c->view.s89ae * c->pz, ret = 1;
	if (key->rot_up == 1)
		mt_rotate_x(&c->view, -0.1), ret = 2;
	if (key->rot_down == 1)
		mt_rotate_x(&c->view, 0.1), ret = 2;
	if (key->rot_right == 1)
		mt_rotate_y(&c->view, 0.1), ret = 2;
	if (key->rot_left == 1)
		mt_rotate_y(&c->view, -0.1), ret = 2;
	return (ret);
}