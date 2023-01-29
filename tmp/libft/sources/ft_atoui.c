/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 23:29:53 by lunovill          #+#    #+#             */
/*   Updated: 2021/02/11 23:29:56 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atoui(const char *str)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i++] - '0';
	}
	return (n);
}
