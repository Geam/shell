#include <stdlib.h>
#include "libft.h"
#include "sh.h"
#include "env_manipulation.h"

char    **generate_dummy_path(void)
{
	char    **path;

	if ((path = (char **)malloc(sizeof(char *) * 2)))
	{
		path[0] = ft_strdup("/usr/local/bin:/usr/bin:/bin");
		path[1] = NULL;
	}
	return (path);
}

void    path_manipulation(t_env *env, char *var)
{
	char    **path;
	char    *env_path;

	if (ft_strequ("PATH", var))
	{
		if ((env_path = ft_getenv(env, var)))
		{
			path = ft_strsplit(env_path, ':');
			if (ft_tablen(path) >= 1)
			{
				ft_free_tab(&env->path);
				env->path = path;
				return ;
			}
		}
		env->path = generate_dummy_path();
	}
}
