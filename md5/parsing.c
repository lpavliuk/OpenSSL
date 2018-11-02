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

void	flag_s(t_md5 *md5, char **argv, int *i)
{
	int j;

	j = -1;
	while (argv[*i][++j] != 's')
		;
	if (!argv[*i][j])
	{
		if (argv[++(*i)])
			md5->str = ft_strdup(argv[*i]);
		else
			usage("md5 -s");
	}
	else
		md5->str = ft_strdup(&argv[*i][j]);
	use_formula(md5, 0, 1);
	free(md5->str);
}

void	check_flags(t_md5 *md5, char **argv, int *i)
{
	int j;

	j = 0;
	while (argv[(*i)][++j])
	{
		if (argv[(*i)][j] == 'r' && !(md5->flag_rqp & FLAG_P))
			md5->flag += FLAG_R;
		else if (argv[(*i)][j] == 'q' && !(md5->flag_rqp & FLAG_P))
			md5->flag += FLAG_Q;
		else if (argv[(*i)][j] == 'p' && !(md5->flag_rqp & FLAG_P)
			&& (md5->flag_rqp += FLAG_P))
			use_formula(md5, 0, 0);
		else if (argv[(*i)][j] == 'p')
			use_formula(md5, 0, 1);
		else if (argv[(*i)][j] == 's')
			flag_s(md5, argv, i);
		else if (argv[(*i)][j] != 's' && argv[(*i)][j] != 'p'
			&& argv[(*i)][j] != 'r' && argv[(*i)][j] != 'q')
			usage("md5 not valid flag!");
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
		if (argv[*i][0] == '-')
			check_flags(md5, argv, i)
		// else
		// 	check_file(md5, argv[*i])
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
