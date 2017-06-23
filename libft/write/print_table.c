#include "libft.h"

int print_table(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
      f("{7}[%s] ",tab[i]);
      i++;
    }
    ft_putchar('\n');
    return (i);
}
