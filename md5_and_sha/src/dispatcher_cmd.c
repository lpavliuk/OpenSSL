/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:43:14 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/06 19:17:55 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	dispatcher_cmd(t_md5 *md5, char string)
{
	int		i;

	i = (int)md5->command;
	md5->flag_data = 1;
	(!string) ? g_func[i - 1](md5) : g_func[i](md5);
}
