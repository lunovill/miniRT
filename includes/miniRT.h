#ifndef MINIRT_H
 #define MINIRT_H

// CODE ERREUR
# define ERROR_MALLOC 1
# define ERROR_MLX 2

//# include <X11/keysymdef.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

//# include "mlxRT.h"

typedef float Matrix4f __attribute__((ext_vector_type(4*4)));
typedef float Vector4f __attribute__((ext_vector_type(4)));
typedef float Coor4f __attribute__((ext_vector_type(4)));

typedef struct	s_check_file
{
	int			camera;
	int			light;
	int			sphere;
	int			plane;
	int			cylinder;
	int			line;
}				t_check_file;


typedef struct s_camera
{
	Coor4f		coor;
	Vector4f	vector;
	Matrix4f	matrix;
	float		FOV;
}				t_camera;

typedef struct s_light
{
	Coor4f		coor;
	float		brightness;
	int			color;
}				t_light;

typedef struct s_sphere
{
	Coor4f			coor;
	float			rayon;
	int				color;
}				t_sphere;

typedef struct s_plane
{
	Coor4f		coor;
	Vector4f	vector;
	int			color;
}				t_plane;

typedef struct s_cylinder
{
	Coor4f		coor;
	Vector4f	vector;
	float		rayon;
	float		height;
	int			color;
}				t_cylinder;

typedef struct s_miniRT
{
//	t_mlx			*mlx;
	t_check_file	*check;
	t_camera		*c;
	t_light			**l;
	t_sphere		**sp;
	t_plane			**pl;
	t_cylinder		**cy;
//	t_garbage		*garbage;
}				t_miniRT;

/*      fonction        */

t_miniRT    *init_miniRT();
int     parsing(t_miniRT *data, char *file);
int     fill_struct(t_miniRT *data, char *file);
int		check_name(char *str);


/*					mon_get_next_line					*/

int		my_gnl(int fd, char **line);
char	*ft_strdup(char const *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif