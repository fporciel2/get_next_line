/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/11 18:11:33 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_write(char **str)
{
	char	*stri;

	stri = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stri == NULL)
		return (NULL);
	while (*str-- != str[0][0])
		str--;
}

static char	**ft_read(int fd, char **str)
{
	char	*buf;
	char	*buf1;
	size_t	count;

	if (*str == &(str[0][0]))
		buf = *str;
	else
	{
		str++;
		buf = *str;
	}
	count = read(fd, buf, BUFFER_SIZE);
	if (count <= 0)
		return (ft_free_str(str));
	else if (ft_buf_check(buf, count))
		*str = buf;
	else
	{
		str++;
		str = ft_read(fd, str);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	backup[8192][8192];
	char		**str;
	char		*stri;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE >= (8192 * 8192)))
		return (NULL);
	str = ft_read(fd, backup);
	stri = ft_write(str);
	backup = ft_backup(str, stri);
	return (backup);
}
