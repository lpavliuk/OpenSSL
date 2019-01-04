/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:43:14 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/04 20:07:10 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	dispatcher_cmd(t_md5 *md5, char string)
{
	int 	i;

	i = -1;
	md5->flag_data = 1;
	while (++i < NUM_CMDS * 2)
	{
		if (md5->command == i)
			(!string) ? g_func[i - 1](md5) : g_func[i](md5);
	}
}
