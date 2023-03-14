/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/14 16:08:13 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_sort_backup(size_t i, char *backup)
{
	size_t	j;

	j = 0;
	if (backup[i] != 0)
	{
		while (backup[i] != 0)
		{
			backup[j] = backup[i];
			j++;
			i++;
		}
		backup[j] = backup[i];
		j++;
		while (backup[j++] != 0)
			backup[j] = 0;
	}
	else
	{
		while (i-- != 0)
			backup[i] = 0;
		backup[i] = 0;
	}
}

static char	*ft_copy_line(char *buf, char *backup)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (backup[i] == 0)
	{
		while (buf[i++] != 0)
			backup[i] = buf[i];
		backup[i] = 0;
	}
	else
	{
		while (backup[i] != 0)
			i++;
		while (buf[j] != 0)
			backup[i++] = buf[j++];
		backup[i] = 0;
	}
	return (backup);
}

static char	*ft_get_line(char *backup, char *result)
{
	size_t	i;

	i = 0;
	while ((backup[i - 1] != 10) && (backup[i] != 0))
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((backup[i - 1] != 10) && (backup[i] != 0))
	{
		result[i] = backup[i];
		i++;
	}
	result[i] = 0;
	ft_sort_backup(i, backup);
	return (result);
}

static char	*ft_read_line(int fd, char *buf)
{
	size_t	count;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	count = read(fd, buf, BUFFER_SIZE);
	if (count < 0)
		return (NULL);
	buf[count] = 0;
	if ((!(ft_check_buf(buf))) && (count != 0))
	{
		buf = ft_read_line(fd, &(buf[count]));
		if ((&(buf[count])) == NULL)
			return (NULL);
	}
	buf = buf[0];
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	backup[70000000];
	char		*buf;
	char		*result;
	char		*backup1;

	if ((fd < 0) || (fd > 1024) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = ft_read_line(fd, buf);
	if (buf == NULL)
		return (NULL);
	backup1 = ft_copy_line(buf, backup);
	result = ft_get_line(backup1, result);
	if (result == NULL)
		return (NULL);
	free(buf);
	return (result);
}
