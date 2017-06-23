#include "libft.h"

int   len_tab(char **t1)
{
  int i;

  i = 0;
  while(t1[i])
  {
    i++;
  }
  return i;
}

char **concat_tab(char **t1, char **t2)
{
  int len;
  char **new;
  int i;
  int y;

  y = 0;
  i = 0;
  len = len_tab(t1) + len_tab(t2);
  new = (char **)malloc(sizeof(char*) * (len + 1));
  ft_bzero((void*)new, sizeof(char*) * (len + 1));
  while(t1[i])
  {
    new[i] = ft_strdup(t1[i]);
    i++;
  }
  while(t2[y])
  {
    new[i] = ft_strdup(t2[y]);
    y++;
    i++;
  }
  new[i] = NULL;
  return new;
}
