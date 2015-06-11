#ifndef ENV_MANIPULATION_H
#define ENV_MANIPULATION_H

void    ft_setenv(t_env *env, char *var, char *val, char env_loc);
char    *ft_getenv(t_env *env, char *var);

#endif
