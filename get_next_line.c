/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:45:08 by cclaude           #+#    #+#             */
/*   Updated: 2019/10/28 17:28:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	read_size = 1;
	while (!(newline_check(stock, read_size)))
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[read_size] = '\0';
		if ((stock = buf_join(stock, buf)) == NULL)
			return (-1);
	}
	if ((*line = get_line(stock)) == NULL)
		return (-1);
	if ((stock = stock_trim(stock)) == NULL)
		return (-1);
	if (read_size != 0)
		return (1);
	free(stock);
	stock = NULL;
	return (0);
}
