/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:14:18 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/10 12:04:29 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_display_file(const char *file)
{
	int			fd;
	ssize_t		end;
	char		buff[BUFFER_SIZE + 1];

	if (!file)
		return (-1);
	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
		return (-1);
	end = read(fd, buff, BUFFER_SIZE);
	while (end > 0)
	{
		buff[end] = '\0';
		ft_putstr(buff);
		ft_bzero(buff, BUFFER_SIZE);
	}
	if (close(fd) == -1)
		return (-1);
	return (end);
}
