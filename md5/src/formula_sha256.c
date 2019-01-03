/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_sha256.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:16:33 by opavliuk          #+#    #+#             */
/*   Updated: 2019/01/03 20:58:44 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define ROTR(x, k) ((x << k) | (x >> (32 - k)))

#define CH( x, y, z) ((x & y) ^ (~x & z))
#define MAJ( x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define BSIG0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define BSIG1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SSIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define SSIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

void	prepare_sha(t_md5 *md5, unsigned int *sha256)
{
	int i;
	int n;

	i = -1;
	while (++i < 16)
        sha256[i] = md5->input_md5int[i];
    while (i < 64)
    {
    	n = i - 15;
        sha256[i] = SSIG1(sha256[i - 2]) + sha256[i - 7] +
    				SSIG0(n) + sha256[i - 16];
    	i++;
    }
}

void	formula_sha256(t_md5 *md5)
{
	unsigned int sha256[64];

	ft_bzero(&sha256[0], 64);

	int n = -1;
	ft_printf("Before!\nsha256 = ");
	while (++n < 64)
		ft_printf("%d", sha256[n]);

	prepare_sha(md5, &sha256[0]);

	n = -1;
	ft_printf("AFTER!\nsha256 = ");
	while (++n < 64)
		ft_printf("%d", sha256[n]);
}
