/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/14 11:45:07 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *buf, char *backup)
{
	size_t	i;
}

static char	*ft_read_line(int fd, char *buf)
{
	size_t	count;
	size_t	recount;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	count = read(fd, buf, BUFFER_SIZE);
	if (count < 0)
		return (NULL);
	recount = (BUFFER_SIZE + 1);
	if (count < recount)
	{
		while (recount-- > count)
			free(buf[recount]);
	}
	buf[count] = 0;
	if ((!(ft_check_buf(buf))) && (count != 0))
	{
		(&(buf[count])) = ft_read_line(fd, &(buf[count]));
		if ((&(buf[count])) == NULL)
			return (NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;

	if ((fd < 0) || (fd > 1024) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = ft_read_line(fd, buf);
	if (buf == NULL)
		return (NULL);
	backup = ft_get_line(buf, backup);
	if (backup == NULL)
		return (NULL);
	free(buf);
	return (backup);
}
