/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fafa <fafa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:03:17 by fafa              #+#    #+#             */
/*   Updated: 2024/12/15 15:16:30 by fafa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s, int c, int *idx)
{
	if (!s)
		return (-1);
	*idx = 0;
	while (*s && *s != (unsigned char)c)
	{
		s++;
		(*idx)++;
	}
	if (*s == '\0')
		*idx = -1;
	return (*idx);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if ((!s1 && !s2) || (ft_strlen(s1) + ft_strlen(s2) == 0))
	{
		ft_free(&s1, &s2, NULL);
		return (NULL);
	}
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	ft_free(&s1, &s2, NULL);
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	if (!s || size == 0 || start >= size)
		return (NULL);
	if (len + start > size)
		len = size - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
