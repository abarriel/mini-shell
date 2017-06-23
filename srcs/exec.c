#include "minishell.h"

int launch(t_sh *sh)
{
  char *str;
  sh->pid = fork();
  if (sh->pid == 0) {
    // child process
    if (!ft_strcmp(sh->args[0],"tenv"))
    {
      char *argv[] = { "/bin/sh", "-c", "env", 0 };
   char *envp[] =
   {
       "HOME=/",
       "PATH=/bin:/usr/bin",
       "TZ=UTC0",
       "USER=beelzebub",
       "LOGNAME=tarzan",
       0
   };
   execve(argv[0], &argv[0], envp);
        execvp("env", sh->args);
          exit(1);
    }
    else
        str = ft_strjoin("/bin/",sh->args[0]);
    if (execve(sh->args[0], sh->args, 0) == -1)
    {
      if (execve(str, sh->args, 0) == -1) {
        f("minishell: command not found: %s\n", sh->args[0]);
      }
    }
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
