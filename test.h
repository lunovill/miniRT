#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>

typedef float Coor4f __attribute__((ext_vector_type(4)));

typedef struct	s_data
{
	Coor4f	pl_or;
	Coor4f	pl_dir;
	Coor4f	r_or;
	Coor4f	r_dir;
}				t_data;


#endif