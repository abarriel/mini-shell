/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 22:52:14 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:35:50 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_oldpath(t_sh *sh)
{
	if (chdir((find_env(sh->environ, "OLDPWD"))) != 0)
		return (f("error\n"));
	return (0);
}

int	cd_f(t_sh *sh)
{
	char	*old_pwd;
	char	*new_pwd;

	if (len_tab(sh->args) > 2)
		return (f("cd: too many arguments\n"));
	old_pwd = getcwd(NULL, 0);
	if (sh->args[1] == NULL)
	{
		if (chdir((find_env(sh->environ, "HOME"))) != 0)
		{
			ft_strdel(&old_pwd);
			return (f("error\n"));
		}
	}
	else
	{
		if (!(ft_strcmp(sh->args[1], "-")) &&
				chdir((find_env(sh->environ, "OLDPWD"))))
		{
			ft_strdel(&old_pwd);
			return (f("error\n"));
		}
		if (ft_strcmp(sh->args[1], "-") && chdir(sh->args[1]) != 0)
		{
			ft_strdel(&old_pwd);
			return (f("cd: no such file or directory: %s\n", sh->args[1]));
		}
	}
	new_pwd = getcwd(NULL, 0);
	change_env(sh->environ, "OLDPWD", old_pwd);
	change_env(sh->environ, "PWD", new_pwd);
	return (0);
}

int	echo_f(t_sh *sh)
{
	int	i;

	i = 1;
	if (sh->args[1] == NULL)
		return (int)write(1, "\n", 1);
	if (!ft_strcmp(sh->args[i], "-n"))
		i++;
	while (sh->args[i])
	{
		write(1, sh->args[i], ft_strlen(sh->args[i]));
		write(1, " ", 1);
		i++;
	}
	if (ft_strcmp(sh->args[1], "-n"))
		write(1, "\n", 1);
	return (0);
}

int	exit_f(t_sh *sh)
{
  int ok;

  ok = sh->status;
	exit(0);
	return (0);
}
