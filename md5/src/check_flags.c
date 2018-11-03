/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:13:55 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/03 15:13:56 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

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
	if (md5->flags_rqps & FLAG_P)
	{
		md5->str = ft_strdup("");
		dispatcher_cmd(md5, 1);
		free(md5->str);
	}
	else
	{
		dispatcher_cmd(md5, 0);
		md5->flags_rqps += FLAG_P;
	}
}

void				check_flags(t_md5 *md5, char **argv, int *i)
{
	int		j;

	j = 0;
	// ft_printf("check flags ==> %s\n", argv[(*i)]); // DELETE!!
	while (argv[(*i)][++j])
	{
		if (argv[(*i)][j] == 'r' && !(md5->flags_rqps & FLAG_P))
			md5->flags_rqps += FLAG_R;
		else if (argv[(*i)][j] == 'q' && !(md5->flags_rqps & FLAG_P))
			md5->flags_rqps += FLAG_Q;
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
			usage("md5 not valid flag!");
			md5->flag_usage = 1;
			return ;
		}
	}
}
