/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_sha256.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:16:33 by opavliuk          #+#    #+#             */
/*   Updated: 2019/02/05 19:01:30 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define ROTR(x, k) ((x >> k) | (x << (32 - k)))

#define CH(x, y, z) ((x & y) ^ ((~x) & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define BSIG0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define BSIG1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SSIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define SSIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

static inline void	prepare_sha(t_md5 *md5, unsigned int *sha256)
{
	int i;

	i = -1;
	while (++i < 16)
		sha256[i] = rev_bytes(md5->input_md5int[i], 4);
	while (i < 64)
	{
		sha256[i] = SSIG1(sha256[i - 2]) + sha256[i - 7] +
					SSIG0(sha256[i - 15]) + sha256[i - 16];
		++i;
	}
}

static inline void	algorithm_sha256(unsigned int *sha256, unsigned int *hash)
{
	int				i;
	unsigned int	t1;
	unsigned int	t2;

	i = -1;
	while (++i < 64)
	{
		t1 = hash[7] + BSIG1(hash[4]) +
			CH(hash[4], hash[5], hash[6])
			+ g_table_sha256[i] + sha256[i];
		t2 = BSIG0(hash[0]) +
			MAJ(hash[0], hash[1], hash[2]);
		hash[7] = hash[6];
		hash[6] = hash[5];
		hash[5] = hash[4];
		hash[4] = hash[3] + t1;
		hash[3] = hash[2];
		hash[2] = hash[1];
		hash[1] = hash[0];
		hash[0] = t1 + t2;
	}
}

static inline void	start_algo(unsigned int *sha256, char command)
{
	unsigned int	copy_hash[8];
	int				i;

	i = -1;
	while (++i < 8)
		copy_hash[i] = (command == 3) ? g_hash_sha256[i] : g_hash_sha224[i];
	algorithm_sha256(sha256, &copy_hash[0]);
	i = -1;
	if (command == 3)
		while (++i < 8)
			g_hash_sha256[i] = copy_hash[i] + g_hash_sha256[i];
	else
		while (++i < 8)
			g_hash_sha224[i] = copy_hash[i] + g_hash_sha224[i];
}

void				formula_sha256(t_md5 *md5)
{
	unsigned int sha256[64];

	ft_bzero(&sha256[0], 64);
	prepare_sha(md5, &sha256[0]);
	start_algo(&sha256[0], md5->command);
}
