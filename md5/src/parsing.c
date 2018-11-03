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

static inline void	check_file(t_md5 *md5, char *file)
{
	int		fd;
	char	buf[1];

	fd = open(file, O_RDONLY);
	md5->flag_data = 1;
	if (fd < 0)
		ft_printf("{red}Error: {yellow}Can't open file!{eoc}\n");
	else
	{
		if (read(fd, &buf[0], 0) < 0)
			ft_printf("{red}Error: {yellow}Can't read file!{eoc}\n");
		else
			use_formula(md5, fd, 0);
		close(fd);
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
	(!md5->flag_data && !md5->flag_usage) ? use_formula(md5, 0, 0) : 0;
}

void				check_command(t_md5 *md5, char *argv)
{
	// ft_printf("checks_command()\n"); // DELETE!!
	if (!argv)
		return ;
	if (!strcmp(argv, "md5"))
		md5->command = CMD_MD5;
	else if (!strcmp(argv, "sha256"))
		md5->command = CMD_SHA256;
	else
		usage("commands");
}
