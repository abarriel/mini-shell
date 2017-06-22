#include "minishell.h"

int print_env(t_env *e)
{
  int i;

  i = 0;
  while(e)
  {
    f("{9}%s", e->name);
    ft_putchar('=');
    f("{7}%s\n", e->value);
    i++;
    e = e->next;
  }
  return (i);
}

int print_path(t_path *p)
{
  int i;

  i = 0;
  ft_putchar('\n');
  while(p)
  {
    f("{7} %s ", p->name);
    if (p->next)
    ft_putchar(':');
    i++;
    p = p->next;
  }
  ft_putchar('\n');
  return (i);
}
