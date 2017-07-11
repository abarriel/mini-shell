/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:33:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/07/11 23:39:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "limits.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>

typedef struct	s_path
{
	char			*name;
	struct s_path	*next;
}				t_path;

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct	s_sh
{
	int		status;
	t_env	*environ;
	char	**env;
	pid_t	wpid;
	pid_t	pid;
	int		start;
	char	*line;
	char	*full_path;
	t_path	*path;
	char	**args;
	int		(*func[6])(struct s_sh *sh);
}				t_sh;

int				change_env(t_env *e, char *name, char *value);
t_sh			*init_sh(void);
int				load_env(t_sh *sh);
void			add_back_env(t_env **p, char *name, char *value);
void			add_back_path(t_path **p, char *name);
char			*find_env(t_env *e, char *name);
int				execute(t_sh *sh);
int				load_path(t_sh *sh);
int				echo_f(t_sh *sh);
int				cd_f(t_sh *sh);
int				exit_f(t_sh *sh);
int				setenv_f(t_sh *sh);
int				unsetenv_f(t_sh *sh);
int				env_f(t_sh *sh);
int				print_path(t_path *p);
int				print_env(t_env *p);
#endif
