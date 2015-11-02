#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "sh.h"
#include "env_manipulation.h"
#include "path_manipulation.h"

void    update_var(t_env *env)
{
	char    *temp;
	char    *nval;

	if ((temp = ft_getenv(env, "SHLVL")))
	{
		nval = ft_itoa(ft_atoi(temp) + 1);
		ft_setenv(env, "SHLVL", nval, 1);
		free(nval);
	}
	else
		ft_setenv(env, "SHLVL", "1", 1);
	ft_setenv(env, "TERM", "42sh", 1);
}

void    generate_env(t_env *env)
{
	env->env = (char **)malloc(sizeof(char *) * 3);
	if (env->env)
	{
		env->env[0] = ft_strdup("SHLVL=1");
		env->env[1] = getcwd(NULL, 0);
		env->env[2] = NULL;
	}
	env->path = generate_dummy_path();
}

int     init_env(char **old_env, t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (*old_env)
	{
		env->env = ft_dup_tab(old_env);
		update_var(env);
	}
	else
		generate_env(env);
	return (0);
}
