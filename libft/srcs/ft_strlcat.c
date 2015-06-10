/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:26:51 by mdelage           #+#    #+#             */
/*   Updated: 2015/01/26 18:40:47 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*cur;
	char	*reader;
	size_t	len;

	len = 0;
	if (src != NULL && dest != NULL)
	{
		cur = (char *)ft_memchr(dest, '\0', size);
		if (cur == NULL)
			return (size + ft_strlen(src));
		reader = (char *)src;
		len = (size_t)(cur - dest) + ft_strlen(reader);
		while ((size_t)(cur - dest) < size - 1 && *reader != '\0')
		{
			*cur = *reader;
			cur++;
			reader++;
		}
		*cur = '\0';
	}
	return (len);
}
