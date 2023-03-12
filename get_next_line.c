/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/12 18:02:47 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	backup[2][268435456];
	char		*buf;
	size_t		count;
	int			back_up;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE >= 238435456))
		return (NULL);
	buf = *backup;
	count = read(fd, buf, count);
	if (count < 0)
		return (NULL);
	else
		buf[count] = 0;
	back_up = ft_backup(buf, backup);
	if (back_up == 0)
		return (NULL);
	else if ((buf[count - 1] != 10) && (count != 0))
		return (get_next_line(fd));
	else
		return (ft_next_line(buf, backup));
}
