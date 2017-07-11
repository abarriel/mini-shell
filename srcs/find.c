/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 23:17:03 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:17:22 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(t_env *e, char *name)
{
	char	*str;

	str = "n";
	while (e)
	{
		if (!ft_strcmp(e->name, name))
			return (e->value);
		e = e->next;
	}
	return (str);
}

int		change_env(t_env *e, char *name, char *value)
{
	while (e)
	{
		if (!ft_strcmp(e->name, name))
		{
			free(e->value);
			e->value = value;
			return (0);
		}
		e = e->next;
	}
	return (1);
}
