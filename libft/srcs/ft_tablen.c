/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:03:32 by mdelage           #+#    #+#             */
/*   Updated: 2014/03/19 16:05:26 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_tablen(char **tab)
{
	size_t	len;

	len = 0;
	if (tab)
	{
		while (tab[len])
			++len;
	}
	return (len);
}
