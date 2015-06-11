#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "sh.h"

char    **ft_get_var_addr(char ***env, char *var)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = ft_strlen(var);
    while ((*env)[i] && (ft_strncmp((*env)[i], var, len) \
            || (*env)[i][len] != '='))
        ++i;
    return (&((*env)[i]));
}

void    ft_add_to_var(char ***env, char *var, char *value)
{
    size_t  i;
    char    **new_env;

    new_env = (char **)malloc(sizeof(char *) * (ft_tablen(*env) + 2));
    if (new_env)
    {
        i = 0;
        while ((*env)[i])
        {
            new_env[i] = (*env)[i];
            ++i;
        }
        new_env[i] = ft_strjoin_3(var, "=", value);
        new_env[i + 1] = NULL;
        free(*env);
        *env = new_env;
    }
}

void    ft_rm_from_var(char ***env, char *var)
{
    size_t  i;
    size_t  j;
    size_t  len;
    char    **new_env;

    new_env = (char **)malloc(sizeof(char *) * ft_tablen(*env));
    if (new_env)
    {
        i = 0;
        j = 0;
        len = ft_strlen(var);
        while ((*env)[i])
        {
            if (ft_strncmp((*env)[i], var, len) || (*env)[i][len] != '=')
            {
                new_env[j] = (*env)[i];
                ++j;
            }
            else
                free((*env)[i]);
            ++i;
        }
    }
}

void    ft_setvar(char ***env, char *var, char *value)
{
    char    **env_var;

    env_var = ft_get_var_addr(env, var);
    if (*env_var)
    {
        free(*env_var);
        *env_var = ft_strjoin_3(var, "=", value);
    }
    else
        ft_add_to_var(env, var, value);
}

char    *ft_getvar(char ***env, char *var)
{
    char    **env_var;

    env_var = ft_get_var_addr(env, var);
    if (*env_var)
        return (*env_var + ft_strlen(var) + 1);
    else
        return (NULL);
}
