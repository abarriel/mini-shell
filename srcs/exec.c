#include "minishell.h"

int find_bin(t_sh *sh, char **envp)
{
    char *str;
    struct stat sb;
    char *path;
    str = NULL;
    while (sh->path)
    {
      path = ft_strjoin(sh->path->name, "/");
      str = ft_strjoin(path, sh->args[0]);
      if(!stat(str, &sb))
        {
          if (execve(str, sh->args, envp) == -1)
            break;
          return 0;
        }
      sh->path = sh->path->next;
    }
    f("minishell: comand not found: %s\n", sh->args[0]);
    return (1);
}

int   len_list(t_env *env)
{
  int len;

  len = 0;
  while (env)
  {
    len++;
    env = env->next;
  }
  return len;
}

char  **get_env(t_sh *sh, t_env *env)
{
  char **envp;
  int len;
  int i;
  char *single_env;

  len = len_list(env);
  i = 0;
  envp = (char **)malloc(sizeof(char *) * len + 1);
  while (env)
  {
    envp[i] = ft_strjoin_three(env->name,"=", env->value);
    env = env->next;
    i++;
  }
  envp[i] = NULL;
  return envp;
}

int launch(t_sh *sh)
{
  char *str;
  char **envp;

  sh->pid = fork();
  envp = get_env(sh, sh->environ);
  if (sh->pid == 0)
  {
    if (execve(sh->args[0], sh->args, envp) == -1)
    {
      find_bin(sh, envp);
    }
    free_tab(envp);
    exit(1);
  }
  if(sh->pid < 0)
  {
    f("minishell: error forking: %s\n", sh->args[0]);
    // // Eroor Forking;
    // perror("lksh");
  }
  else {
    sh->wpid = waitpid(sh->pid, &sh->status, 0);
  }
  free_tab(envp);
  return 1;
}


int execute(t_sh *sh)
{
  int i;

  i = 0;
  if (sh->args[0] == NULL)
    return 1;
  while (built_str[i])
  {
    if (!ft_strcmp(sh->args[0],built_str[i]))
      {
        return(sh->func[i](sh));
      }
    i++;
  }
  return launch(sh);
}
