/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:14:22 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/06 19:34:34 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static inline void	check_file(t_md5 *md5, char *file)
{
	char	buf[1];

	md5->fd = open(file, O_RDONLY);
	md5->flag_data = 1;
	if (md5->fd < 0)
		ft_printf("{red}Error: {yellow}Can't open file!{eoc}\n");
	else
	{
		if (read(md5->fd, &buf[0], 0) < 0)
			ft_printf("{red}Error: {yellow}Can't read file!{eoc}\n");
		else
		{
			md5->str = ft_strdup(file);
			dispatcher_cmd(md5, 0);
			free(md5->str);
		}
		close(md5->fd);
	}
}

void				parsing_argv(t_md5 *md5, char **argv, int *i)
{
	if (!argv || !argv[(*i)])
		return ;
	while (argv[*i] && argv[++(*i)])
	{
		if (argv[*i][0] == '-' && argv[*i][1])
			check_flags(md5, argv, i);
		else if (argv[*i][0] == '-' && !argv[*i][1])
		{
			usage("unknown option");
			md5->flag_usage = 1;
		}
		else
			check_file(md5, argv[*i]);
		update_hashes();
	}
	(!md5->flag_data && !md5->flag_usage) ? dispatcher_cmd(md5, 0) : 0;
}

void				check_command(t_md5 *md5, char *argv)
{
	int i;
	int n;

	if (!argv)
		return ;
	i = -1;
	n = 1;
	while (++i < NUM_CMDS)
	{
		if (!strcmp(argv, g_cmd[i]))
			md5->command = n;
		n += 2;
	}
	if (!md5->command)
		usage("commands");
}
