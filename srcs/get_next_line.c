#include "../includes/miniRT.h"

int	find_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && (!(str[i] == c)))
		i++;
	if (!(str[i] == c))
		return (-1);
	return (i);
}

int	get_line(char **stock, char **line, int i)
{
	size_t	len_stock;
	char	*tmp_stock;

	*line = ft_substr(*stock, 0, i);
	len_stock = ft_strlen(*stock + i) + 1;
	if (len_stock <= 0)
	{
		free(stock);
		stock = NULL;
		return (1);
	}
	tmp_stock = ft_substr(*stock, i + 1, len_stock);
	free(*stock);
	*stock = tmp_stock;
	return (1);
}

int	get_last_line(char **stock, char **line, int ret)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	return (ret);
}

int	my_gnl(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = 0;

	ret = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (stock && find_index(stock, '\n') > -1)
		return (get_line(&stock, line, find_index(stock, '\n')));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (stock == 0)
			stock = ft_strdup("");
		stock = ft_strjoin(stock, buf);
		if (find_index(stock, '\n') > -1)
			return (get_line(&stock, line, find_index(stock, '\n')));
	}
	if (stock)
		return (get_last_line(&stock, line, ret));
	*line = ft_strdup("");
	return (ret);
}
