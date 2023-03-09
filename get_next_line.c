/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:29:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/09 18:02:15 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	result = ft_write(str);
	if (result == NULL)
		return (NULL);
	str = ft_backup(str);
	return (result);
}
