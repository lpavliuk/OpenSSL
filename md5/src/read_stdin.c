/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:05:41 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/06 20:05:59 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void				read_stdin(t_md5 *md5)
{
	int		i;
	char	buf[64];
	char	*tmp;

	i = 0;
	if (!md5->str)
		md5->str = ft_memalloc(1);
	while ((i = read(0, &buf, 64)))
	{
		tmp = md5->str;
		buf[i] = '\0';
		md5->str = ft_strjoin(md5->str, buf);
		free(tmp);
	}
	g_func[(int)md5->command](md5);
	free(md5->str);
}
