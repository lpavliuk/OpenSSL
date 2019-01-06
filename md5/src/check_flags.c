/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:13:55 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/06 20:05:00 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static inline void	flag_s(t_md5 *md5, char **argv, int *i)
{
	int j;

	j = -1;
	while (argv[*i][++j] != 's')
		;
	if (!argv[*i][++j])
		(argv[++(*i)]) ? md5->str = ft_strdup(argv[*i]) : 0;
	else
		md5->str = ft_strdup(&argv[*i][j]);
	if (!argv[*i])
	{
		usage("md5 -s");
		md5->flag_usage = 1;
	}
	else
		dispatcher_cmd(md5, 1);
	(md5->str) ? free(md5->str) : 0;
}

static inline void	flag_p(t_md5 *md5)
{
	md5->str = ft_strdup("");
	if (md5->flags_rqps & FLAG_P)
		dispatcher_cmd(md5, 1);
	else
	{
		md5->flags_rqps += FLAG_P;
		dispatcher_cmd(md5, 0);
		if (md5->flags_rqps & FLAG_Q || md5->flags_rqps & FLAG_R)
		{
			free(md5->str);
			update_hashes();
			md5->str = ft_strdup("");
			dispatcher_cmd(md5, 1);
		}
	}
	(md5->str) ? free(md5->str) : 0;
}

static inline void	flag_q_r(t_md5 *md5, char flag)
{
	if (flag == 'r')
		md5->flags_rqps += FLAG_R;
	else
		md5->flags_rqps += FLAG_Q;
	if (md5->flags_rqps & FLAG_P)
		flag_p(md5);
}

void				check_flags(t_md5 *md5, char **argv, int *i)
{
	int		j;

	j = 0;
	while (argv[(*i)][++j])
	{
		if ((argv[(*i)][j] == 'r' && !(md5->flags_rqps & FLAG_R))
			|| (argv[(*i)][j] == 'q' && !(md5->flags_rqps & FLAG_Q)))
			flag_q_r(md5, argv[(*i)][j]);
		else if (argv[(*i)][j] == 'p')
			flag_p(md5);
		else if (argv[(*i)][j] == 's')
		{
			flag_s(md5, argv, i);
			return ;
		}
		else if (argv[(*i)][j] != 's' && argv[(*i)][j] != 'p'
			&& argv[(*i)][j] != 'r' && argv[(*i)][j] != 'q')
		{
			usage("unknown option");
			md5->flag_usage = 1;
			return ;
		}
		update_hashes();
	}
}
