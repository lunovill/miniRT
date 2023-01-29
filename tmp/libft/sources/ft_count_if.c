/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:36:20 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:02:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tabs, int (*f)(char *))
{
	unsigned int	count;
	unsigned int	i;

	if (!tabs || !f)
		return (0);
	i = 0;
	count = 0;
	while (tabs[i])
		if (f(tabs[i++]) == 1)
			count++;
	return (count);
}
