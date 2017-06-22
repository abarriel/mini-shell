#include "minishell.h"

int   fill_path(t_sh *sh, char *value)
{
  int i;
  char **path;

  i = 0;
  if (!value)
    return 1;
  path = ft_strsplit(value, ':');
  while (path[i])
  {
    add_back_path(&sh->path, path[i]);
    i++;
  }
  free_tab(path);
  return 0;
}

int   load_path(t_sh *sh)
{
  t_env   *loop_environ;

  loop_environ = sh->environ;
  while (loop_environ)
  {
    if (!ft_strcmp(loop_environ->name, "PATH"))
        {
          if (fill_path(sh, loop_environ->value))
            return 1;
          return 0;
        }
    loop_environ = loop_environ->next;
  }
  return 1;
}

int   load_env(t_sh *sh)
{
  extern  char **environ;
  int  i;
  char **env;

  i = 0;
  while(environ[i])
  {
    env = ft_strsplit(environ[i], '=');
    add_back_env(&sh->environ, env[0], env[1]);
    free_tab(env);
    i++;
  }
  return i;
}
