/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:33:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/21 23:56:05 by abarriel         ###   ########.fr       */
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

typedef struct  s_path
{
  char          *name;
  struct s_path *next;
}            t_path;

typedef struct  s_env
{
  char          *name;
  char          *value;
  struct s_env *next;
}            t_env;

typedef struct		s_sh
{
  int       status;
  t_env     *environ;
  char      **env;
  pid_t     wpid;
  pid_t     pid;
	int				start;
  char      *line;
  char      *full_path;
  t_path    *path;
  char      **args;
}					  t_sh;
int   load_env(t_sh *sh);
int   load_path(t_sh *sh);
int print_path(t_path *p);
int print_env(t_env *p);
void		add_back_env(t_env **p, char *name, char *value);
void		add_back_path(t_path **p, char *name);
t_sh *init_sh(void);
#endif
