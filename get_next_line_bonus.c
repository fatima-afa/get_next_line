/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fafa <fafa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:03:13 by fafa              #+#    #+#             */
/*   Updated: 2024/12/15 20:58:03 by fafa             ###   ########.fr       */
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
	size_buff_rest = ft_strlen(*buff) - idx - 1;
	tmp_buff = *buff;
	*buff = ft_substr(tmp_buff, 0, size_line + 1);
	*buff_rest = ft_substr(tmp_buff, idx + 1, size_buff_rest);
	if (!*buff)
		return (ft_free(buff, buff_rest, &tmp_buff));
	ft_free(&tmp_buff, NULL, NULL);
}

static char	*read_line(int fd, char *buff, long *size)
{
	char	*tmp;
	char	*old_buff;

	tmp = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		ft_free(&buff, NULL, NULL);
		return (NULL);
	}
	*size = read(fd, tmp, BUFFER_SIZE);
	if (*size < 0)
	{
		ft_free(&tmp, &buff, NULL);
		return (NULL);
	}
	if (*size == 0)
	{
		ft_free(&tmp, NULL, NULL);
		return (buff);
	}
	tmp[*size] = '\0';
	old_buff = buff;
	buff = ft_strjoin(buff, tmp);
	ft_free(&old_buff, &tmp, NULL);
	return (buff);
}

static char	*get_line(int fd, char **buff_rest)
{
	char	*buff;
	long	size;
	int		idx_line;

	if (!buff_rest)
		return (NULL);
	buff = ft_strjoin(*buff_rest, NULL);
	ft_free(buff_rest, NULL, NULL);
	size = 1;
	while ((ft_strchr(buff, '\n', &idx_line)) == -1 && size > 0)
	{
		buff = read_line(fd, buff, &size);
		if (!buff)
			return (NULL);
	}
	if (!buff || !*buff)
	{
		ft_free(&buff, NULL, NULL);
		return (NULL);
	}
	set_line_buff_rest(&buff, buff_rest, idx_line);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff_rest[1024];
	char		*str_return;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024|| read(fd, NULL, 0) < 0)
		return (NULL);
	str_return = get_line(fd, &buff_rest[fd]);
	return (str_return);
}
