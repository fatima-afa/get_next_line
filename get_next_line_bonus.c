/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fafa <fafa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:03:13 by fafa              #+#    #+#             */
/*   Updated: 2024/12/15 15:20:10 by fafa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **ptr1, char **ptr2, char **ptr3)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	if (ptr3 && *ptr3)
	{
		free(*ptr3);
		*ptr3 = NULL;
	}
}

void	set_line_buff_rest(char **buff, char **buff_rest, int idx)
{
	char	*tmp_buff;
	size_t	size_line;
	size_t	size_buff_rest;

	if (!*buff || idx == -1)
		return ;
	size_line = idx;
	size_buff_rest = strlen(*buff) - idx - 1;
	tmp_buff = *buff;
	*buff = ft_substr(tmp_buff, 0, size_line + 1);
	*buff_rest = ft_substr(tmp_buff, idx + 1, size_buff_rest);
	if (!*buff)
		return (ft_free(buff, buff_rest, &tmp_buff));
	ft_free(&tmp_buff, NULL, NULL);
}

char	*get_line(int fd, char **buff_rest)
{
	char	*buff;
	char	*tmp;
	long	size;
	int		idx_line;

	buff = ft_strjoin(*buff_rest, NULL);
	size = 1;
	while ((ft_strchr(buff, '\n', &idx_line)) == -1 && size > 0)
	{
		tmp = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (!tmp)
		{
			ft_free(&tmp, &buff, buff_rest);
			return (NULL);
		}
		size = read(fd, tmp, BUFFER_SIZE);
		tmp[size] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	set_line_buff_rest(&buff, buff_rest, idx_line);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff_rest[1024];
	char		*str_return;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	str_return = get_line(fd, &buff_rest[fd]);
	return (str_return);
}
