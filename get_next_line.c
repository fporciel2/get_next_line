/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/13 13:24:03 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	backup[536870912];
	char		buf;
	size_t		count;
	size_t		i;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	count = read(fd, &buf, 1);
	while (count > 0)
	{
		backup[i++] = buf;
		if (backup[i - 1] == 10)
			break ;
		count = read(fd, &buf, 1);
	}
	if (count == 0)
		return (NULL);
	backup[i] = 0;
	return (backup);
}
