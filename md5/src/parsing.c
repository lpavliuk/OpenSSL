/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:14:22 by opavliuk          #+#    #+#             */
/*   Updated: 2019/02/05 19:57:12 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define INV "is an invalid command."
#define ERR0 "No such file or directory"
#define ERR1 "Can't read file or directory"

static inline void	check_file(t_md5 *md5, char *file)
{
	char	buf[1];

	md5->fd = open(file, O_RDONLY);
	md5->flag_data = 1;
	md5->flag_file = 1;
	if (md5->fd < 0)
		ft_printf("{red}Error:{yellow} %s: %s{eoc}\n", file, ERR0);
	else
	{
		if (read(md5->fd, &buf[0], 1) < 0)
			ft_printf("{red}Error:{yellow} %s: %s{eoc}\n", file, ERR1);
		else
		{
			md5->str = ft_strdup(file);
			dispatcher_cmd(md5, 0);
			free(md5->str);
			md5->str = NULL;
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
		if (argv[*i][0] == '-' && argv[*i][1] && !md5->flag_file)
			check_flags(md5, argv, i);
		else if (argv[*i][0] == '-' && !argv[*i][1])
			error_option(md5, argv[*i]);
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
	{
		ft_printf("{blue}ft_ssl: ");
		ft_printf("{red}Error:{yellow} '%s' {blue}is %s{eoc}\n", argv, INV);
		ft_printf("\n{blue}Standard commands:\n\nMessage Digest commands:\n");
		ft_printf("{yellow}md5\nsha256\nsha224\n");
		write(1, "\e[94m", 5);
		ft_printf("\nCipher commands:\n");
		write(1, "\e[0m", 4);
	}
}
