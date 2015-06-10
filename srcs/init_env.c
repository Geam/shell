#include "libft.h"

#include <stdlib.h>

void    ft_setenv(char ***env, char *var, char *value);
char    *ft_getenv(char ***env, char *var);

void    update_var(char ***env)
{
    char    *temp;
    char    *nval;

    if (temp = ft_getenv(env, "SHLVL"))
    {
        nval = ft_itoa(ft_atoi(temp) + 1);
        ft_setenv(env, "SHLVL", nval);
        free(nval);
    }
}

int     init_env(char **old_env, char ***env)
{
    if (*old_env)
    {
        *env = ft_dup_tab(old_env);
        update_var(env);
    }
    else
        ft_putstr("env NOT given\n");
    return (0);
}


