/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:54:03 by mtashrif          #+#    #+#             */
/*   Updated: 2023/09/21 12:00:45 by mtashrif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*print_line(char **temp)
{
	int		n_pos;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != 10)
		n_pos++;
	if (str[n_pos] == 10)
		n_pos++;
	return_line = ft_strdup(str, n_pos);
	*temp = ft_strdup(str + n_pos, ft_strlen(str + n_pos));
	if (str)
		free(str);
	str = NULL;
	return (return_line);
}

char	*get_next_line(int fd)
{
	static char		*temp[1024];
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	if (have_n(temp[fd]))
		return (print_line(&temp[fd]));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		temp[fd] = ft_strjoin(temp[fd], buffer);
		if (have_n(temp[fd]))
			break ;
	}
	if (buffer)
		free(buffer);
	return (print_line(&temp[fd]));
}
