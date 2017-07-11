/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:32:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:32:58 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_space(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '\t')
			src[i] = ' ';
		i++;
	}
	return (src);
}

char	**get_args(char *line_not_trimed)
{
	char	**tab;
	char	**tmp;
	char	**new;
	char	*trimed;

	trimed = ft_strtrim(line_not_trimed);
	tab = ft_strsplit(trimed, '"');
	free(trimed);
	if (tab[0] == NULL)
		return (tab);
	free(tab[0]);
	tab[0] = ft_strtrim(tab[0]);
	tab[0] = clean_space(tab[0]);
	tmp = ft_strsplit(tab[0], ' ');
	new = concat_tab(tmp, tab + 1);
	free_tab(tmp);
	free_tab(tab);
	return (new);
}

int		loop(t_sh *sh)
{
	while (write(1, "$> ", 3) && get_next_line(0, &sh->line))
	{
		sh->args = get_args(sh->line);
		execute(sh);
		free(sh->line);
		free_tab(sh->args);
	}
	return (0);
}

int		main(void)
{
	t_sh	*sh;
	int		i;

	i = 0;
	sh = init_sh();
	load_env(sh);
	load_path(sh);
	loop(sh);
	return (0);
}
