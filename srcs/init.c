#include "minishell.h"

t_path		*create_elm_path(char *name)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		  ft_exit("Failed to Malloc ");
	path->name = ft_strdup(name);
	path->next = NULL;
	return (path);
}

void		add_back_path(t_path **p, char *name)
{
	t_path *path;

	path = *p;
	if (!path)
	{
		(*p) = create_elm_path(name);
		return ;
	}
	while (path->next)
		path = path->next;
	path->next = create_elm_path(name);
}

t_env		*create_elm_env(char *name, char *value)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		  ft_exit("Failed to Malloc ");
	e->name = ft_strdup(name);
  e->value = ft_strdup(value);
	e->next = NULL;
	return (e);
}

void		add_back_env(t_env **p, char *name, char *value)
{
	t_env *e;

	e = *p;
	if (!e)
	{
		(*p) = create_elm_env(name, value);
		return ;
	}
	while (e->next)
		e = e->next;
	e->next = create_elm_env(name, value);
}

t_sh *init_sh(void)
{
    t_sh *e;

    if (!(e = (t_sh*)malloc(sizeof(t_sh))))
  		  ft_exit("Failed to Malloc ");
    // e->parent = getpid();
    // e->pid = fork();
    e->path = NULL;
    e->environ = NULL;
    e->env = NULL;
    e->full_path = NULL;
    e->line = NULL;
    e->args = NULL;
    return e;
}
