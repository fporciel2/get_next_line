/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/13 11:51:10 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_backup1(char *buf, char **backup)
{
	size_t	i;

	i = 0;
	while (*(buf - 1) != 10)
		buf++;
	while 
}

static int	ft_backup(char *buf, char **backup)
{
	while ((*buf != 10) && (*buf != 0))
		buf++;
	if ((*buf == 10) && (*(buf + 1) == 0))
		return (1);
	else if ((*buf == 0) && (buf >= &(backup[0][268435456])))
		return (0);
	else if ((*buf == 10) && (*(buf + 1) != 0))
		return (ft_backup1(&(buf[0]), backup));
	else if ((*buf == 0) && (buf < &(backup[0][268435456])))
		return (ft_backup2(&(buf[0]), backup));
}

char	*get_next_line(int fd)
{
	static char	backup[2][268435456];
	char		*buf;
	size_t		count;
	int			back_up;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE >= ft_len_get[backup]))
		return (NULL);
	buf = *backup;
	count = read(fd, buf, BUFFER_SIZE);
	if (count < 0)
		return (NULL);
	else
		buf[count] = 0;
	back_up = ft_backup(buf, backup);
	if (back_up == 0)
		return (NULL);
	if ((buf[back_up - 1] != 10) && (count != 0))
		return (get_next_line(fd));
	else
		return (ft_next_line(buf, &backup, back_up));
}
