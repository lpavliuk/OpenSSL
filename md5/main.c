/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:00:34 by opavliuk          #+#    #+#             */
/*   Updated: 2018/10/22 17:00:35 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	check_list(t_argvs *argvs)
{
	t_argvs *tmp;

	tmp = argvs;
	while (tmp)
	{
		ft_printf("%x ", (unsigned char)tmp->flag);
		if (tmp->str)
			ft_printf("==> %s\n", tmp->str);
		else
			ft_printf("\n");
		tmp = tmp->next;
	}
}


/*
** -p : Читает из INPUT и выводит то что считал и хэш
** -s : Читает следущий аргумент для хэширования
** "MD5 ("text") = hash\n"
** "SHA256 ("text") = hash\n"
** -r : Вначале хэш, потом имя файла или текст
** -q : Выводит только хэш и имеет приоритет перед
*/

t_argvs	*new_argvs(t_argvs **head)
{
	t_argvs *tmp;

	if (!(*head))
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

void	usage(char *str)
{
	ft_printf("Usage: %s\n", str);
	system("leaks a.out");
	exit(0);
}

void	parsing_argv(t_md5 *md5, char **argv)
{
	t_argvs *new;
	int		i;
	
	i = 1;
	while (argv[++i])
	{
		new = new_argvs(&md5->argvs);
		if (!strcmp(argv[i], "-p"))		
			new->flag = FLAG_P;	
		else if (!strcmp(argv[i], "-s"))
		{	
			new->flag = FLAG_S;
			if (argv[i + 1] && ++i)
				new->str = ft_strdup(argv[i]);
			else
				usage("md5");
		}	
		else if (!strcmp(argv[i], "-r"))
			new->flag = FLAG_R;
		else if (!strcmp(argv[i], "-q"))
			new->flag = FLAG_Q;
		else
			new->str = ft_strdup(argv[i]);
	}
	check_list(md5->argvs);
}

void	check_command(t_md5 *md5, char *argv)
{
	if (!strcmp(argv, "md5"))
		md5->command = CMD_MD5;
	else if (!strcmp(argv, "sha256"))
		md5->command = CMD_SHA256;
	else
		usage("command");
}

int		main(int argc, char **argv)
{
	t_md5 *md5;
	
	md5 = malloc(sizeof(t_md5));
	ft_bzero(md5, sizeof(t_md5));
	if (argc > 1)
	{
		check_command(md5, argv[1]);
		if (argc > 2)
			parsing_argv(md5, argv);
	//	else
	//		work_input(md5);
	}
	else
		usage("commands");

	system("leaks a.out");
	return (0);
}
