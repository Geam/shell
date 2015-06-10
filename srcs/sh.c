#include "libft.h"

int     init_env(char **old_env, char ***env);

int     main(int ac, char **av, char **old_env)
{
    char    **env;

    (void)ac;
    (void)av;
    init_env(old_env, &env);
    return (0);
}
