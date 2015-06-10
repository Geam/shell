/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 20:02:54 by mdelage           #+#    #+#             */
/*   Updated: 2015/01/26 18:20:36 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int         strspl_nb_word(char const *s, char c)
{
    int      nb_word;
    int      word;

    word = 0;
    nb_word = 0;
    while (*s)
    {
        if (!word && c != *s)
        {
            ++word;
            ++nb_word;
        }
        else if (word && c == *s)
            --word;
        ++s;
    }
    ft_putstr("word find : ");
    ft_putnbr(nb_word);
    ft_putchar('\n');
    return (nb_word);
}

char        *strspl_ret_sub_str(char **s, char c)
{
    char    neol;
    char    *temp;
    char    *str;

    while (**s == c)
        ++(*s);
    if (!(**s))
        return (NULL);
    temp = *s;
    while (**s && **s != c)
        ++(*s);
    neol = (**s) ? 0 : 1;
    str = (char *)malloc(sizeof(char) * (*s - temp + neol));
    if (str)
        ft_strncpy(str, temp, (*s - temp + neol));
    return (str);
}

char		**ft_strsplit(char const *s, char c)
{
    int     i;
    char    **tab;
    char    *temp;

    if (!s)
        return (NULL);
    tab = (char **)malloc(sizeof(char *) * (strspl_nb_word(s, c) + 1));
    if (tab)
    {
        i = 0;
        temp = (char *)s;
        while (*temp)
        {
            tab[i] = strspl_ret_sub_str(&temp, c);
            ++i;
        }
        tab[i] = NULL;
    }
    return (tab);
}
