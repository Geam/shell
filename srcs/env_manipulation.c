#include "sh.h"
#include "var_manipulation.h"
#include "path_manipulation.h"

/**
 * Set var to val in local or env array. If the var update is 'PATH', update
 * the path keep in memory
 *
 * @return void
 */
void    ft_setenv(t_env *env, char *var, char *val, char env_env)
{
	char	**old_val;

	old_val = ft_get_var_addr(&env->local, var);
	if ((old_val || ! ft_get_var_addr(&env->env, var)) && !env_env)
		ft_setvar(&env->local, var, val, 1);
	else if (old_val && env_env)
	{
		ft_rm_from_var(&env->local, var, 0);
		ft_add_to_var(&env->env, var, *old_val, 0);
	}
	else
		ft_setvar(&env->env, var, val, 1);
    path_manipulation(env, var);
}

/**
 * Return the var from env or local array. If the var is not found, return NULL
 *
 * @return char*
 */
char    *ft_getenv(t_env *env, char *var)
{
    char    *val;

    if (!(val = ft_getvar(&env->env, var)))
        val = ft_getvar(&env->local, var);
    return (val);
}

/**
 * Remove var from env or local
 *
 * @return void
 */
void	ft_unsetenv(t_env *env, char *var)
{
	char	*val;

	if ((val = ft_getvar(&env->env, var)))
		ft_rm_from_var(&env->env, var, 1);
	else if ((val = ft_getvar(&env->env, var)))
		ft_rm_from_var(&env->local, var, 1);
	return ;
}
