/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_md5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:00:50 by opavliuk          #+#    #+#             */
/*   Updated: 2018/10/22 17:00:53 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

# define F(x, y, z) ((x & y) | (~x & z))
# define G(x, y, z) ((x & z) | (~z & y))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ (~z | x))

void	formula_first(t_md5 *md5)
{
	A = B + ((A + F(B,C,D) + X[0] + TMD5[1]) <<< 7);
	D = A + ((D + F(A,B,C) + X[1] + TMD5[2]) <<< 12);
	C = D + ((C + F(D,A,B) + X[2] + TMD5[3]) <<< 17);
	B = C + ((B + F(C,D,A) + X[3] + TMD5[4]) <<< 22);

	A = B + ((A + F(B,C,D) + X[4] + TMD5[5]) <<< 7);
	D = A + ((D + F(A,B,C) + X[5] + TMD5[6]) <<< 12);
	C = D + ((C + F(D,A,B) + X[6] + TMD5[7]) <<< 17);
	B = C + ((B + F(C,D,A) + X[7] + TMD5[8]) <<< 22);

	A = B + ((A + F(B,C,D) + X[8] + TMD5[9]) <<< 7);
	D = A + ((D + F(A,B,C) + X[9] + TMD5[10]) <<< 12);
	C = D + ((C + F(D,A,B) + X[10] + TMD5[11]) <<< 17);
	B = C + ((B + F(C,D,A) + X[11] + TMD5[12]) <<< 22);

	A = B + ((A + F(B,C,D) + X[12] + TMD5[13]) <<< 7);
	D = A + ((D + F(A,B,C) + X[13] + TMD5[14]) <<< 12);
	C = D + ((C + F(D,A,B) + X[14] + TMD5[15]) <<< 17);
	B = C + ((B + F(C,D,A) + X[15] + TMD5[16]) <<< 22);
}

void	formula_second(t_md5 *md5)
{
	A = B + ((A + G(B,C,D) + X[1] + TMD5[17]) <<< 5);
	D = A + ((D + G(A,B,C) + X[6] + TMD5[18]) <<< 9);
	C = D + ((C + G(D,A,B) + X[11] + TMD5[19]) <<< 14);
	B = C + ((B + G(C,D,A) + X[0] + TMD5[20]) <<< 20);

	A = B + ((A + G(B,C,D) + X[5] + TMD5[21]) <<< 5);
	D = A + ((D + G(A,B,C) + X[10] + TMD5[22]) <<< 9);
	C = D + ((C + G(D,A,B) + X[15] + TMD5[23]) <<< 14);
	B = C + ((B + G(C,D,A) + X[4] + TMD5[24]) <<< 20);

	A = B + ((A + G(B,C,D) + X[9] + TMD5[25]) <<< 5);
	D = A + ((D + G(A,B,C) + X[14] + TMD5[26]) <<< 9);
	C = D + ((C + G(D,A,B) + X[3] + TMD5[27]) <<< 14);
	B = C + ((B + G(C,D,A) + X[8] + TMD5[28]) <<< 20);

	A = B + ((A + G(B,C,D) + X[13] + TMD5[29]) <<< 5);
	D = A + ((D + G(A,B,C) + X[2] + TMD5[30]) <<< 9);
	C = D + ((C + G(D,A,B) + X[7] + TMD5[31]) <<< 14);
	B = C + ((B + G(C,D,A) + X[12] + TMD5[32]) <<< 20);
}

void	formula_third(t_md5 *md5)
{
	A = B + ((A + H(B,C,D) + X[5] + TMD5[33]) <<< 4);
	D = A + ((D + H(A,B,C) + X[8] + TMD5[34]) <<< 11);
	C = D + ((C + H(D,A,B) + X[11] + TMD5[35]) <<< 16);
	B = C + ((B + H(C,D,A) + X[14] + TMD5[36]) <<< 23);

	A = B + ((A + H(B,C,D) + X[1] + TMD5[37]) <<< 4);
	D = A + ((D + H(A,B,C) + X[4] + TMD5[38]) <<< 11);
	C = D + ((C + H(D,A,B) + X[7] + TMD5[39]) <<< 16);
	B = C + ((B + H(C,D,A) + X[10] + TMD5[40]) <<< 23);

	A = B + ((A + H(B,C,D) + X[13] + TMD5[41]) <<< 4);
	D = A + ((D + H(A,B,C) + X[0] + TMD5[42]) <<< 11);
	C = D + ((C + H(D,A,B) + X[3] + TMD5[43]) <<< 16);
	B = C + ((B + H(C,D,A) + X[6] + TMD5[44]) <<< 23);

	A = B + ((A + H(B,C,D) + X[9] + TMD5[45]) <<< 4);
	D = A + ((D + H(A,B,C) + X[12] + TMD5[46]) <<< 11);
	C = D + ((C + H(D,A,B) + X[15] + TMD5[47]) <<< 16);
	B = C + ((B + H(C,D,A) + X[2] + TMD5[48]) <<< 23);
}

void	formula_fourth(t_md5 *md5)
{
	A = B + ((A + I(B,C,D) + X[0] + TMD5[49]) <<< 6);
	D = A + ((D + I(A,B,C) + X[7] + TMD5[50]) <<< 10);
	C = D + ((C + I(D,A,B) + X[14] + TMD5[51]) <<< 15);
	B = C + ((B + I(C,D,A) + X[5] + TMD5[52]) <<< 21);

	A = B + ((A + I(B,C,D) + X[12] + TMD5[53]) <<< 6);
	D = A + ((D + I(A,B,C) + X[3] + TMD5[54]) <<< 10);
	C = D + ((C + I(D,A,B) + X[10] + TMD5[55]) <<< 15);
	B = C + ((B + I(C,D,A) + X[1] + TMD5[56]) <<< 21);

	A = B + ((A + I(B,C,D) + X[8] + TMD5[57]) <<< 6);
	D = A + ((D + I(A,B,C) + X[15] + TMD5[58]) <<< 10);
	C = D + ((C + I(D,A,B) + X[6] + TMD5[59]) <<< 15);
	B = C + ((B + I(C,D,A) + X[13] + TMD5[60]) <<< 21);

	A = B + ((A + I(B,C,D) + X[4] + TMD5[61]) <<< 6);
	D = A + ((D + I(A,B,C) + X[11] + TMD5[62]) <<< 10);
	C = D + ((C + I(D,A,B) + X[2] + TMD5[63]) <<< 15);
	B = C + ((B + I(C,D,A) + X[9] + TMD5[64]) <<< 21);
}

