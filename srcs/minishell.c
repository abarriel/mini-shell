/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:32:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/21 23:56:45 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int launch(t_sh *sh)
{
  sh->pid = fork();
  if (sh->pid == 0) {
    // child process
    char *str = ft_strjoin("/bin/",sh->args[0]);
    if (execve(str, sh->args, 0) == -1) {
      f("lsh");
    }
    exit(1);
  }
  if(sh->pid < 0)
  {
    // Eroor Forking;
    perror("lsh");
  }
  else {
    sh->wpid = waitpid(sh->pid, &sh->status, 0);
  }
  return 1;
}

int   loop(t_sh *sh)
{
  while (write(1, "$> ", 3) && get_next_line(0, &sh->line))
    {
      sh->args = ft_strsplit(sh->line, ' ');
      // (sh);
      launch(sh);
      free(sh->line);
      free_tab(sh->args);
    }
  return (0);
}

int		main(void)
{
  t_sh *sh;
  int i;

  i = 0;
  sh = init_sh();
  load_env(sh);
  load_path(sh);
  print_env(sh->environ);
  print_path(sh->path);
  // while(1)
    // ;
  // print_table(sh->environ);
  loop(sh);
  return (0);
}
