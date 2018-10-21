#include "md5.h"

t_argvs	*new_argvs(t_argvs **head)
{
	t_argvs tmp;

	if (*head)
	{
		(*head) = malloc(sizeof(t_argvs));
		ft_bzero(*head, sizeof(t_argvs));
		return (*head);	
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_argvs));
		ft_bzero(tmp->next, sizeof(t_argvs));
		return (tmp->next);
	}
}

void	parsing_argv(t_md5 *md5, char **argv)
{
	t_argvs *new;
	int		i;
	
	i = 0;
	while (argv[++i])
	{
		new = new_argvs(&md5->argvs);
	}
}


int		main(int argc, char **argv)
{
	t_md5 *md5;
	
	md5 = malloc(sizeof(t_md5));
	ft_bzero(md5, sizeof(t_md5));
	if (argc > 1)
		parsing_argv(md5, argv);
	//else
	//	get_input(md5);	

	return (0);
}
