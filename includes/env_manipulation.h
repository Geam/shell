#ifndef ENV_MANIPULATION_H
# define ENV_MANIPULATION_H

char    **ft_get_env_addr(char ***env, char *var);
void    ft_add_to_env(char ***env, char *var, char *value);
void    ft_rm_from_env(char ***env, char *var);
void    ft_setenv(char ***env, char *var, char *value);
char    *ft_getenv(char ***env, char *var);

#endif
