/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:28:14 by mdelage           #+#    #+#             */
/*   Updated: 2014/03/16 21:00:03 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define BUF_SIZE 4096

static size_t	ft_strlen_spe(char *str, char c)
{
	size_t	length;

	length = 0;
	while (str[length] != c && str[length] != '\0')
		length++;
	return (length);
}

static void		ft_strcpy_clean(char dest[BUF_SIZE + 1], char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= BUF_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
	return ;
}

static char		*ft_strjoin_spe(char *s1, char *s2, size_t l_s2)
{
	char	*temp;
	size_t	l_s1;
	size_t	i;

	i = 0;
	l_s1 = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	while (i < l_s1)
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l_s2)
	{
		temp[i + l_s1] = s2[i];
		i++;
	}
	temp[i + l_s1] = '\0';
	return (temp);
}

static void		gnl_subfunc(char buf[BUF_SIZE + 1], size_t len, char *line)
{
	if (buf[0] == '\0' && line[0] != '\0')
		buf[0] = '\0';
	else
		ft_strcpy_clean(buf, &(buf[len + 1]));
	return ;
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*temp;
	size_t		length;
	static char	buf[BUF_SIZE + 1] = {'\0'};

	*line = ft_strnew(1);
	ret = 1;
	while (ret > 0)
	{
		if (buf[0] == '\0')
			ret = read(fd, &buf, BUF_SIZE);
		if (ret < 0)
			return (ret);
		length = ft_strlen_spe(buf, '\n');
		temp = *line;
		*line = ft_strjoin_spe(temp, buf, length);
		free(temp);
		if (buf[length] != '\0' || (buf[0] == '\0' && *line[0] != '\0'))
		{
			gnl_subfunc(buf, length, *line);
			return (1);
		}
		ft_strclr((char *)&buf);
	}
	return (0);
}
