/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:14:22 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/03 21:05:15 by opavliuk         ###   ########.fr       */
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
			dispatcher_cmd(md5, 0);
		close(md5->fd);
	}
}

void				parsing_argv(t_md5 *md5, char **argv, int *i)
{
	if (!argv || !argv[(*i)])
		return ;
	// ft_printf("parsing_argv()\n"); // DELETE!!
	while (argv[*i] && argv[++(*i)])
	{
		if (argv[*i][0] == '-')
			check_flags(md5, argv, i);
		else
			check_file(md5, argv[*i]);
		update_hashes();
	}
	(!md5->flag_data && !md5->flag_usage) ? dispatcher_cmd(md5, 0) : 0;
}

void				check_command(t_md5 *md5, char *argv)
{
	int i;
	// ft_printf("checks_command()\n"); // DELETE!!
	if (!argv)
		return ;
	i = -1;
	while (++i < NUM_CMDS)
	{
		if (!strcmp(argv, g_cmd[i]))
			md5->command = i + 1;
	}
	if (!md5->command)
		usage("commands");
}
