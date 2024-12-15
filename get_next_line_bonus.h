/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fafa <fafa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:45:01 by fafa              #+#    #+#             */
/*   Updated: 2024/12/15 20:56:41 by fafa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

void	ft_free(char **ptr1, char **ptr2, char **ptr3);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c, int *idx);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
void	set_line_buff_rest(char **buff, char **buff_rest, int idx);

#endif
