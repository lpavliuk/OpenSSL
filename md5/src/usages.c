/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:30:42 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/01 20:30:44 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define	OPT "ft_ssl: illegal option --"

void		error_option(t_md5 *md5, char *argv)
{
	ft_printf("{red}Error:{yellow} %s '%s'{eoc}\n", OPT, argv);
	ft_printf("{yellow}./ft_ssl command [-psqr] [-s string] [files ...]\n");
	ft_printf("	-p  echo STDIN to STDOUT and append the checksum to STDOUT\n");
	ft_printf("	-s  print the sum of the given string\n");
	ft_printf("	-q  quiet mode\n");
	ft_printf("	-r  reverse the format of the output.\n");
	write(1, "\e[0m", 4);
	md5->flag_usage = 1;
}
