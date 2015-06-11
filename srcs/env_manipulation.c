#include "sh.h"
#include "var_manipulation.h"
#include "path_manipulation.h"

void    ft_setenv(t_env *env, char *var, char *val, char env_loc)
{
    if (env_loc)
        ft_setvar(&env->env, var, val);
    else
        ft_setvar(&env->local, var, val);
    path_manipulation(env, var);
}

char    *ft_getenv(t_env *env, char *var)
{
    char    *val;

    if (!(val = ft_getvar(&env->env, var)))
        val = ft_getvar(&env->local, var);
    return (val);
}
