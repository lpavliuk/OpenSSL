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

#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

#define LOOP_SHIFT(x, k) ((x << k) | (x >> (32 - k)))

static inline void	formula_first(t_md5 *md5)
{
	A = B + LOOP_SHIFT((A + F(B, C, D) + md5->input_md5int[0] + TMD5[0]), 7);
	D = A + LOOP_SHIFT((D + F(A, B, C) + md5->input_md5int[1] + TMD5[1]), 12);
	C = D + LOOP_SHIFT((C + F(D, A, B) + md5->input_md5int[2] + TMD5[2]), 17);
	B = C + LOOP_SHIFT((B + F(C, D, A) + md5->input_md5int[3] + TMD5[3]), 22);
	A = B + LOOP_SHIFT((A + F(B, C, D) + md5->input_md5int[4] + TMD5[4]), 7);
	D = A + LOOP_SHIFT((D + F(A, B, C) + md5->input_md5int[5] + TMD5[5]), 12);
	C = D + LOOP_SHIFT((C + F(D, A, B) + md5->input_md5int[6] + TMD5[6]), 17);
	B = C + LOOP_SHIFT((B + F(C, D, A) + md5->input_md5int[7] + TMD5[7]), 22);
	A = B + LOOP_SHIFT((A + F(B, C, D) + md5->input_md5int[8] + TMD5[8]), 7);
	D = A + LOOP_SHIFT((D + F(A, B, C) + md5->input_md5int[9] + TMD5[9]), 12);
	C = D + LOOP_SHIFT((C + F(D, A, B) + md5->input_md5int[10] + TMD5[10]), 17);
	B = C + LOOP_SHIFT((B + F(C, D, A) + md5->input_md5int[11] + TMD5[11]), 22);
	A = B + LOOP_SHIFT((A + F(B, C, D) + md5->input_md5int[12] + TMD5[12]), 7);
	D = A + LOOP_SHIFT((D + F(A, B, C) + md5->input_md5int[13] + TMD5[13]), 12);
	C = D + LOOP_SHIFT((C + F(D, A, B) + md5->input_md5int[14] + TMD5[14]), 17);
	B = C + LOOP_SHIFT((B + F(C, D, A) + md5->input_md5int[15] + TMD5[15]), 22);
}

static inline void	formula_second(t_md5 *md5)
{
	A = B + LOOP_SHIFT((A + G(B, C, D) + md5->input_md5int[1] + TMD5[16]), 5);
	D = A + LOOP_SHIFT((D + G(A, B, C) + md5->input_md5int[6] + TMD5[17]), 9);
	C = D + LOOP_SHIFT((C + G(D, A, B) + md5->input_md5int[11] + TMD5[18]), 14);
	B = C + LOOP_SHIFT((B + G(C, D, A) + md5->input_md5int[0] + TMD5[19]), 20);
	A = B + LOOP_SHIFT((A + G(B, C, D) + md5->input_md5int[5] + TMD5[20]), 5);
	D = A + LOOP_SHIFT((D + G(A, B, C) + md5->input_md5int[10] + TMD5[21]), 9);
	C = D + LOOP_SHIFT((C + G(D, A, B) + md5->input_md5int[15] + TMD5[22]), 14);
	B = C + LOOP_SHIFT((B + G(C, D, A) + md5->input_md5int[4] + TMD5[23]), 20);
	A = B + LOOP_SHIFT((A + G(B, C, D) + md5->input_md5int[9] + TMD5[24]), 5);
	D = A + LOOP_SHIFT((D + G(A, B, C) + md5->input_md5int[14] + TMD5[25]), 9);
	C = D + LOOP_SHIFT((C + G(D, A, B) + md5->input_md5int[3] + TMD5[26]), 14);
	B = C + LOOP_SHIFT((B + G(C, D, A) + md5->input_md5int[8] + TMD5[27]), 20);
	A = B + LOOP_SHIFT((A + G(B, C, D) + md5->input_md5int[13] + TMD5[28]), 5);
	D = A + LOOP_SHIFT((D + G(A, B, C) + md5->input_md5int[2] + TMD5[29]), 9);
	C = D + LOOP_SHIFT((C + G(D, A, B) + md5->input_md5int[7] + TMD5[30]), 14);
	B = C + LOOP_SHIFT((B + G(C, D, A) + md5->input_md5int[12] + TMD5[31]), 20);
}

static inline void	formula_third(t_md5 *md5)
{
	A = B + LOOP_SHIFT((A + H(B, C, D) + md5->input_md5int[5] + TMD5[32]), 4);
	D = A + LOOP_SHIFT((D + H(A, B, C) + md5->input_md5int[8] + TMD5[33]), 11);
	C = D + LOOP_SHIFT((C + H(D, A, B) + md5->input_md5int[11] + TMD5[34]), 16);
	B = C + LOOP_SHIFT((B + H(C, D, A) + md5->input_md5int[14] + TMD5[35]), 23);
	A = B + LOOP_SHIFT((A + H(B, C, D) + md5->input_md5int[1] + TMD5[36]), 4);
	D = A + LOOP_SHIFT((D + H(A, B, C) + md5->input_md5int[4] + TMD5[37]), 11);
	C = D + LOOP_SHIFT((C + H(D, A, B) + md5->input_md5int[7] + TMD5[38]), 16);
	B = C + LOOP_SHIFT((B + H(C, D, A) + md5->input_md5int[10] + TMD5[39]), 23);
	A = B + LOOP_SHIFT((A + H(B, C, D) + md5->input_md5int[13] + TMD5[40]), 4);
	D = A + LOOP_SHIFT((D + H(A, B, C) + md5->input_md5int[0] + TMD5[41]), 11);
	C = D + LOOP_SHIFT((C + H(D, A, B) + md5->input_md5int[3] + TMD5[42]), 16);
	B = C + LOOP_SHIFT((B + H(C, D, A) + md5->input_md5int[6] + TMD5[43]), 23);
	A = B + LOOP_SHIFT((A + H(B, C, D) + md5->input_md5int[9] + TMD5[44]), 4);
	D = A + LOOP_SHIFT((D + H(A, B, C) + md5->input_md5int[12] + TMD5[45]), 11);
	C = D + LOOP_SHIFT((C + H(D, A, B) + md5->input_md5int[15] + TMD5[46]), 16);
	B = C + LOOP_SHIFT((B + H(C, D, A) + md5->input_md5int[2] + TMD5[47]), 23);
}

static inline void	formula_fourth(t_md5 *md5)
{
	A = B + LOOP_SHIFT((A + I(B, C, D) + md5->input_md5int[0] + TMD5[48]), 6);
	D = A + LOOP_SHIFT((D + I(A, B, C) + md5->input_md5int[7] + TMD5[49]), 10);
	C = D + LOOP_SHIFT((C + I(D, A, B) + md5->input_md5int[14] + TMD5[50]), 15);
	B = C + LOOP_SHIFT((B + I(C, D, A) + md5->input_md5int[5] + TMD5[51]), 21);
	A = B + LOOP_SHIFT((A + I(B, C, D) + md5->input_md5int[12] + TMD5[52]), 6);
	D = A + LOOP_SHIFT((D + I(A, B, C) + md5->input_md5int[3] + TMD5[53]), 10);
	C = D + LOOP_SHIFT((C + I(D, A, B) + md5->input_md5int[10] + TMD5[54]), 15);
	B = C + LOOP_SHIFT((B + I(C, D, A) + md5->input_md5int[1] + TMD5[55]), 21);
	A = B + LOOP_SHIFT((A + I(B, C, D) + md5->input_md5int[8] + TMD5[56]), 6);
	D = A + LOOP_SHIFT((D + I(A, B, C) + md5->input_md5int[15] + TMD5[57]), 10);
	C = D + LOOP_SHIFT((C + I(D, A, B) + md5->input_md5int[6] + TMD5[58]), 15);
	B = C + LOOP_SHIFT((B + I(C, D, A) + md5->input_md5int[13] + TMD5[59]), 21);
	A = B + LOOP_SHIFT((A + I(B, C, D) + md5->input_md5int[4] + TMD5[60]), 6);
	D = A + LOOP_SHIFT((D + I(A, B, C) + md5->input_md5int[11] + TMD5[61]), 10);
	C = D + LOOP_SHIFT((C + I(D, A, B) + md5->input_md5int[2] + TMD5[62]), 15);
	B = C + LOOP_SHIFT((B + I(C, D, A) + md5->input_md5int[9] + TMD5[63]), 21);
}

void				formula_md5(t_md5 *md5)
{
	unsigned int aa;
	unsigned int bb;
	unsigned int cc;
	unsigned int dd;

	aa = A;
	bb = B;
	cc = C;
	dd = D;
	formula_first(md5);
	formula_second(md5);
	formula_third(md5);
	formula_fourth(md5);
	A = aa + A;
	B = bb + B;
	C = cc + C;
	D = dd + D;
}
