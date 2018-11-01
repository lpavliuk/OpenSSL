/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:14:22 by opavliuk          #+#    #+#             */
/*   Updated: 2018/10/24 09:14:25 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static inline t_argvs	*new_argvs(t_argvs **head)
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

void	parsing_argv(t_md5 *md5, char **argv, int *i)
{
	t_argvs *new;
	
	if (!argv || !argv[++(*i)])
		return ;
	ft_printf("parsing_argv()\n");
	while (argv[++(*i)])
	{
		new = new_argvs(&md5->argvs);
		if (!strcmp(argv[*i], "-p"))		
			new->flag = FLAG_P;	
		else if (!strcmp(argv[*i], "-s"))
		{	
			new->flag = FLAG_S;
			if (argv[*i + 1] && ++(*i))
				new->str = ft_strdup(argv[*i]);
		}	
		else if (!strcmp(argv[*i], "-r"))
			new->flag = FLAG_R;
		else if (!strcmp(argv[*i], "-q"))
			new->flag = FLAG_Q;
		else
			new->str = ft_strdup(argv[*i]);
	}
}

void	check_command(t_md5 *md5, char *argv)
{
	ft_printf("checks_command()\n");
	if (!argv)
		return ;
	if (!strcmp(argv, "md5"))
		md5->command = CMD_MD5;
	else if (!strcmp(argv, "sha256"))
		md5->command = CMD_SHA256;
	else
		usage("command");
}
