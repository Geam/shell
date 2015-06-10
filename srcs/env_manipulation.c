#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "sh.h"
#include "path_manipulation.h"

char    **ft_get_env_addr(t_env *env, char *var)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = ft_strlen(var);
    while (env->env[i] && (ft_strncmp((env->env)[i], var, len) \
            || env->env[i][len] != '='))
        ++i;
    return (&(env->env[i]));
}

void    ft_add_to_env(t_env *env, char *var, char *value)
{
    size_t  i;
    char    **new_env;

    new_env = (char **)malloc(sizeof(char *) * (ft_tablen(env->env) + 2));
    if (new_env)
    {
        i = 0;
        while (env->env[i])
        {
            new_env[i] = env->env[i];
            ++i;
        }
        new_env[i] = ft_strjoin_3(var, "=", value);
        new_env[i + 1] = NULL;
        free(env->env);
        env->env = new_env;
    }
}

void    ft_rm_from_env(t_env *env, char *var)
{
    size_t  i;
    size_t  j;
    size_t  len;
    char    **new_env;

    new_env = (char **)malloc(sizeof(char *) * ft_tablen(env->env));
    if (new_env)
    {
        i = 0;
        j = 0;
        len = ft_strlen(var);
        while (env->env[i])
        {
            if (ft_strncmp(env->env[i], var, len) || env->env[i][len] != '=')
            {
                new_env[j] = env->env[i];
                ++j;
            }
            ++i;
        }
    }
    path_manip(env, var);
}

void    ft_setenv(t_env *env, char *var, char *value)
{
    char    **env_var;

    env_var = ft_get_env_addr(env, var);
    if (*env_var)
    {
        free(*env_var);
        *env_var = ft_strjoin_3(var, "=", value);
    }
    else
        ft_add_to_env(env, var, value);
    path_manip(env, var);
}

char    *ft_getenv(t_env *env, char *var)
{
    char    **env_var;

    env_var = ft_get_env_addr(env, var);
    if (*env_var)
        return (*env_var + ft_strlen(var) + 1);
    else
        return (NULL);
}
