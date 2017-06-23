#include "minishell.h"

int setenv_f(t_sh *sh)
{
  if(!sh->args[0] || !sh->args[1])
  {
    f("Format for setenv: KEY VALUE where key and value not empty\n");
    return 1;
  }
  add_back_env(&sh->environ, sh->args[1], sh->args[2]);
  return 0;
}

int unsetenv_f(t_sh *sh)
{
  f("unsetenv");
    return 0;
}

int env_f(t_sh *sh)
{
print_env(sh->environ);
    return 0;
}
