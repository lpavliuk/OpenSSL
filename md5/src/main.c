/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:00:34 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/26 20:17:23 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
** -p : Читает из INPUT и выводит то что считал и хэш
** -s : Читает следущий аргумент для хэширования
** "MD5 ("text") = hash\n"
** "SHA256 ("text") = hash\n"
** -r : Вначале хэш, потом имя файла или текст
** -q : Выводит только хэш и имеет приоритет перед
*/

unsigned int	g_hash_md5[4] = {
	0x67452301, 0xEFCDAB89,
	0x98BADCFE, 0x10325476
};

unsigned int	g_hash_sha256[8] = {
	0x6A09E667, 0xBB67AE85,
	0x3C6EF372, 0xA54FF53A,
	0x510E527F, 0x9B05688C,
	0x1F83D9AB, 0x5BE0CD19
};

int				main(int argc, char **argv)
{
	t_md5	*md5;

	md5 = malloc(sizeof(t_md5));
	ft_bzero(md5, sizeof(t_md5));
	if (argc == 1)
		loop_ssl(md5);
	else
		argvs(md5, argv);
	system("leaks a.out");
	return (0);
}
