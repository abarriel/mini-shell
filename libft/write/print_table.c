#include "libft.h"

int print_table(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
      ft_putendl(tab[i]);
      i++;
    }
    return (i); 
}
