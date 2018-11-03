/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:38:35 by opavliuk          #+#    #+#             */
/*   Updated: 2018/11/01 20:38:36 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	update_hashes(void)
{
	g_hash_md5[0] = 0x67452301;
	g_hash_md5[1] = 0xEFCDAB89;
	g_hash_md5[2] = 0x98BADCFE;
	g_hash_md5[3] = 0x10325476;
	g_hash_sha256[0] = 0x6A09E667;
	g_hash_sha256[1] = 0xBB67AE85;
	g_hash_sha256[2] = 0x3C6EF372;
	g_hash_sha256[3] = 0xA54FF53A;
	g_hash_sha256[4] = 0x510E527F;
	g_hash_sha256[5] = 0x9B05688C;
	g_hash_sha256[6] = 0x1F83D9AB;
	g_hash_sha256[7] = 0x5BE0CD19;
}
