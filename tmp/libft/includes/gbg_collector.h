/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbg_collector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:13:46 by lunovill          #+#    #+#             */
/*   Updated: 2022/11/17 05:13:47 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GBG_COLLECTOR_H
# define  GBG_COLLECTOR_H

# include <stdlib.h>

typedef struct s_garbage	t_garbage;
struct s_garbage
{
	void		*zone;
	t_garbage	*next;

};

t_garbage	*gbg_add(t_garbage *first, void *zone);
void		gbg_remove(t_garbage *remove);
#endif
