#include "libft.h"
#include "init_env.h"

void    dump_env(char **env)
{
    int     i;

    i = 0;
    while (env[i])
    {
        ft_putendl(env[i]);
        ++i;
    }
}

int     main(int ac, char **av, char **old_env)
{
    char    **env;

    (void)ac;
    (void)av;
    init_env(old_env, &env);
    dump_env(old_env);
    ft_putstr("===============\n");
    dump_env(env);
    ft_free_tab(&env);
    return (0);
}
