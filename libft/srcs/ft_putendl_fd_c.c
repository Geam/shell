/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 21:41:34 by mdelage           #+#    #+#             */
/*   Updated: 2014/05/18 21:41:35 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd_c(char *s, int fd, char *color)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		len = ft_putstr_fd_c(s, fd, color);
		len += ft_putchar_fd('\n', fd);
	}
	return (len);
}
