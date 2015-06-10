/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:38:23 by mdelage           #+#    #+#             */
/*   Updated: 2014/03/05 20:20:25 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c)
			return (&((char *)s)[i]);
	}
	return (NULL);
}