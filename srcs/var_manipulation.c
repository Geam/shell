#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "sh.h"

/**
 * The function below are generic, they can be used for env and local variable
 */

/**
 * Return a pointer to the var. If the var is not found, return NULL
 *
 * @return char**
 */
char    **ft_get_var_addr(char ***env, char *var)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = ft_strlen(var);
    while ((*env)[i] && (ft_strncmp((*env)[i], var, len) \
            || (*env)[i][len] != '='))
        ++i;
	if ((*env)[i])
	    return (&((*env)[i]));
	return (NULL);
}

/**
 * Add new variable to array of variable
 *
 * @return void
 */
void    ft_add_to_var(char ***env, char *var, char *value, int new)
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
		if (new)
	        new_env[i] = ft_strjoin_3(var, "=", value);
		else
			new_env[i] = value;
        new_env[i + 1] = NULL;
        free(*env);
        *env = new_env;
    }
}

/**
 * Remove variable from array of variable. If del == 0, the string won't be
 * free, usefull when tranferring var from local to env and vice versa
 *
 * @return void
 */
void    ft_rm_from_var(char ***env, char *var, int del)
{
    size_t  i;
    size_t  j;
    size_t  len;
    char    **new_env;

    if ((new_env = (char **)malloc(sizeof(char *) * ft_tablen(*env))))
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
            else if (del)
                free((*env)[i]);
            ++i;
        }
		free(*env);
		*env = new_env;
    }
}

/**
 * Set a variable value in array of variable. If variable exist, replace it's
 * value. If new, will alocate string such as <var>=<value>, else the value
 * will be store as if
 *
 * @return void
 */
void    ft_setvar(char ***env, char *var, char *value, int new)
{
    char    **env_var;

    env_var = ft_get_var_addr(env, var);
    if (*env_var)
    {
        free(*env_var);
		if (new)
	        *env_var = ft_strjoin_3(var, "=", value);
		else
			*env_var = value;
    }
    else
        ft_add_to_var(env, var, value, new);
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
