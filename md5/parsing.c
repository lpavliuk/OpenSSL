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
	if (!argv[*i][++j])
		(argv[++(*i)]) ? md5->str = ft_strdup(argv[*i]): 0;
	else
		md5->str = ft_strdup(&argv[*i][j]);
	(!argv[*i]) ? usage("md5 -s"): use_formula(md5, 0, 1);
	(md5->str) ? free(md5->str): 0;
}

void	check_flags(t_md5 *md5, char **argv, int *i)
{
	int j;

	j = 0;
	ft_printf("check flags ==> %s\n", argv[(*i)]);
	while (argv[(*i)][++j])
	{
		if (argv[(*i)][j] == 'r' && !(md5->flags_rqp & FLAG_P))
			md5->flags_rqp += FLAG_R;
		else if (argv[(*i)][j] == 'q' && !(md5->flags_rqp & FLAG_P))
			md5->flags_rqp += FLAG_Q;
		else if (argv[(*i)][j] == 'p' && !(md5->flags_rqp & FLAG_P)
			&& (md5->flags_rqp += FLAG_P))
			use_formula(md5, 0, 0);
		else if (argv[(*i)][j] == 'p')
			use_formula(md5, 0, 1);
		else if (argv[(*i)][j] == 's')
		{
			flag_s(md5, argv, i);
			break ;
		}
		else if (argv[(*i)][j] != 's' && argv[(*i)][j] != 'p'
			&& argv[(*i)][j] != 'r' && argv[(*i)][j] != 'q')
			usage("md5 not valid flag!");
	}
}

void	check_file(t_md5 *md5, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_printf("{red}Error: {yellow}Can't open file!{eoc}\n");
	else
		use_formula(md5, fd, 0);
	close(fd);
}

void	parsing_argv(t_md5 *md5, char **argv, int *i)
{
	if (!argv || !argv[(*i)])
		return ;
	ft_printf("parsing_argv()\n");
	while (argv[++(*i)])
	{
		if (argv[*i][0] == '-')
			check_flags(md5, argv, i);
		else
			check_file(md5, argv[*i]);
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
		printf("Usage: command\n");
}
