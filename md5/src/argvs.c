/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:50:35 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/03 20:50:36 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	argvs(t_md5 *md5, char **argv)
{
	int i;

	i = 1;
	if (argv && argv[1])
		check_command(md5, argv[1]);
	if (md5->command && argv && argv[2])
		parsing_argv(md5, argv, &i);
	else if (md5->command)
		dispatcher_cmd(md5, 0);
}
