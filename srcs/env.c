#include "minishell.h"

int setenv_f(t_sh *sh)
{
  if (!sh->args[1] || !sh->args[2])
  {
    f("Format for setenv: KEY VALUE where key and value not empty\n");
    return (1);
  }
  if (ft_strchr(sh->args[1], '=') || ft_strchr(sh->args[2], '='));
  {
    f("Format for setenv: KEY VALUE should not contains =\n");
    return (1);
  }
  add_back_env(&sh->environ, sh->args[1], sh->args[2]);
  return (0);
}

// void free_elem_env(t_env *env, char *arg)
// {
//   while (env)
//   {
//     if(!ft_strcmp(arg, env->name))
//     {
//
//     }
//     env = env->next;
//   }
// }

int unsetenv_f(t_sh *sh)
{
  if (!sh->args[0] || !sh->args[1])
  {
    f("Format for unsetenv: KEY VALUE where key and value not empty\n");
    return (1);
  }
  if (ft_strchr(sh->args[1], '='));
  {
    f("Format for unsetenv: KEY VALUE should not contains =\n");
    return (1);
  }
  // free_elem_env(&sh->environ, sh->args[1]);
  f("unsetenv");
  return (0);
}

int env_f(t_sh *sh)
{
  print_env(sh->environ);
    return (0);
}
