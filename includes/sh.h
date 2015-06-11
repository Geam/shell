#ifndef SH_H
#define SH_H

typedef struct  s_env
{
    char        **env;
    char        **local;
    char        **path;
}               t_env;

#endif
