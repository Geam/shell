/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 21:38:00 by mdelage           #+#    #+#             */
/*   Updated: 2014/05/18 21:38:44 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd_c(char *s, int fd, char *color)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		ft_putstr_fd(color, fd);
		len = ft_putstr_fd(s, fd);
		ft_putstr_fd(NORMAL, fd);
	}
	return (len);
}
