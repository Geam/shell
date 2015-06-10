#ifndef ENV_MANIPULATION_H
# define ENV_MANIPULATION_H

char    **ft_get_env_addr(t_env *env, char *var);
void    ft_add_to_env(t_env *env, char *var, char *value);
void    ft_rm_from_env(t_env *env, char *var);
void    ft_setenv(t_env *env, char *var, char *value);
char    *ft_getenv(t_env *env, char *var);

#endif
