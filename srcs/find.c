#include "minishell.h"

char *find_env(t_env *e, char *name)
{
  char *str;

  str = "n";
  while(e)
  {
    if(!ft_strcmp(e->name, name))
      return(e->value);
    e = e->next;
  }
  return str;
}

int change_env(t_env *e, char *name, char *value)
{
  while(e)
  {
    if(!ft_strcmp(e->name, name))
    {
      free(e->value);
        e->value = value;
        return 0;
    }
    e = e->next;
  }
  return 1;
}
// /Users/abarriel/.brew/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki
