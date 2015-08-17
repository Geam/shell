#ifndef VAR_MANIPULATION_H
# define VAR_MANIPULATION_H

char    **ft_get_var_addr(char ***env, char *var);
void    ft_add_to_var(char ***env, char *var, char *value, int new);
void    ft_rm_from_var(char ***env, char *var, int del);
void    ft_setvar(char ***env, char *var, char *value, int new);
char    *ft_getvar(char ***env, char *var);

#endif
