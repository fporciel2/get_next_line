/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/11 11:15:33 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char **str)
{
	char	*buf;

	buf = *str;
	if ((*str == NULL) || (str == NULL))
		return (NULL);
	if (BUFFER_SIZE < 8192)
	{
		if (read(fd, buf, BUFFER_SIZE))
	}
}

char	*get_next_line(int fd)
{
	static char	str[8192][8192];
	char		**stri;
	char		*strin;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE > SIZE_MAX))
		return (NULL);
	while (str++ != &(str[8192]))
	{
		while (*str != &((*str)[8192]))
			*str++;
		if (*str++ == &((*str)[8192]))
			**str = 0;
	}
	if (str++ == &(str[8192]))
		*str = NULL;
	stri = ft_read(fd, str);
	strin = ft_write(stri);
	return (strin);
}
