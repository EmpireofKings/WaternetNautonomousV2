/*
 *    This file was auto-generated using the ACADO Toolkit.
 *    
 *    While ACADO Toolkit is free software released under the terms of
 *    the GNU Lesser General Public License (LGPL), the generated code
 *    as such remains the property of the user who used ACADO Toolkit
 *    to generate this code. In particular, user dependent data of the code
 *    do not inherit the GNU LGPL license. On the other hand, parts of the
 *    generated code that are a direct copy of source code from the
 *    ACADO Toolkit or the software tools it is based on, remain, as derived
 *    work, automatically covered by the LGPL license.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    
 */


#include "acado_common.h"


void acado_rhs(const real_t* in, real_t* out)
{
const real_t* xd = in;
const real_t* u = in + 8;
const real_t* od = in + 10;
/* Vector of auxiliary variables; number of elements: 4. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = (cos(xd[2]));
a[1] = (sin(xd[2]));
a[2] = (sin(xd[2]));
a[3] = (cos(xd[2]));

/* Compute outputs: */
out[0] = ((xd[3]*a[0])+(xd[4]*a[1]));
out[1] = ((xd[3]*a[2])-(xd[4]*a[3]));
out[2] = ((real_t)(0.0000000000000000e+00)-xd[5]);
out[3] = ((((u[0]+u[1])-((real_t)(3.8000000000000000e+01)*xd[3]))/(real_t)(2.0000000000000000e+02))+(xd[5]*xd[4]));
out[4] = ((((real_t)(-5.2800000000000000e+03)*xd[4])/(real_t)(2.0000000000000000e+02))-(xd[5]*xd[3]));
out[5] = ((((real_t)(8.0000000000000004e-01)*(u[0]-u[1]))-((real_t)(1.0400000000000000e+02)*xd[5]))/(real_t)(5.0000000000000000e+02));
out[6] = od[0];
out[7] = od[1];
}



void acado_diffs(const real_t* in, real_t* out)
{
const real_t* xd = in;
/* Vector of auxiliary variables; number of elements: 13. */
real_t* a = acadoWorkspace.rhs_aux;

/* Compute intermediate quantities: */
a[0] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[2])));
a[1] = (cos(xd[2]));
a[2] = (cos(xd[2]));
a[3] = (sin(xd[2]));
a[4] = (cos(xd[2]));
a[5] = ((real_t)(-1.0000000000000000e+00)*(sin(xd[2])));
a[6] = (sin(xd[2]));
a[7] = (cos(xd[2]));
a[8] = ((real_t)(1.0000000000000000e+00)/(real_t)(2.0000000000000000e+02));
a[9] = ((real_t)(1.0000000000000000e+00)/(real_t)(2.0000000000000000e+02));
a[10] = ((real_t)(1.0000000000000000e+00)/(real_t)(2.0000000000000000e+02));
a[11] = ((real_t)(1.0000000000000000e+00)/(real_t)(5.0000000000000000e+02));
a[12] = ((real_t)(1.0000000000000000e+00)/(real_t)(5.0000000000000000e+02));

/* Compute outputs: */
out[0] = (real_t)(0.0000000000000000e+00);
out[1] = (real_t)(0.0000000000000000e+00);
out[2] = ((xd[3]*a[0])+(xd[4]*a[1]));
out[3] = a[2];
out[4] = a[3];
out[5] = (real_t)(0.0000000000000000e+00);
out[6] = (real_t)(0.0000000000000000e+00);
out[7] = (real_t)(0.0000000000000000e+00);
out[8] = (real_t)(0.0000000000000000e+00);
out[9] = (real_t)(0.0000000000000000e+00);
out[10] = (real_t)(0.0000000000000000e+00);
out[11] = (real_t)(0.0000000000000000e+00);
out[12] = ((xd[3]*a[4])-(xd[4]*a[5]));
out[13] = a[6];
out[14] = ((real_t)(0.0000000000000000e+00)-a[7]);
out[15] = (real_t)(0.0000000000000000e+00);
out[16] = (real_t)(0.0000000000000000e+00);
out[17] = (real_t)(0.0000000000000000e+00);
out[18] = (real_t)(0.0000000000000000e+00);
out[19] = (real_t)(0.0000000000000000e+00);
out[20] = (real_t)(0.0000000000000000e+00);
out[21] = (real_t)(0.0000000000000000e+00);
out[22] = (real_t)(0.0000000000000000e+00);
out[23] = (real_t)(0.0000000000000000e+00);
out[24] = (real_t)(0.0000000000000000e+00);
out[25] = ((real_t)(0.0000000000000000e+00)-(real_t)(1.0000000000000000e+00));
out[26] = (real_t)(0.0000000000000000e+00);
out[27] = (real_t)(0.0000000000000000e+00);
out[28] = (real_t)(0.0000000000000000e+00);
out[29] = (real_t)(0.0000000000000000e+00);
out[30] = (real_t)(0.0000000000000000e+00);
out[31] = (real_t)(0.0000000000000000e+00);
out[32] = (real_t)(0.0000000000000000e+00);
out[33] = (((real_t)(0.0000000000000000e+00)-(real_t)(3.8000000000000000e+01))*a[8]);
out[34] = xd[5];
out[35] = xd[4];
out[36] = (real_t)(0.0000000000000000e+00);
out[37] = (real_t)(0.0000000000000000e+00);
out[38] = a[9];
out[39] = a[9];
out[40] = (real_t)(0.0000000000000000e+00);
out[41] = (real_t)(0.0000000000000000e+00);
out[42] = (real_t)(0.0000000000000000e+00);
out[43] = ((real_t)(0.0000000000000000e+00)-xd[5]);
out[44] = ((real_t)(-5.2800000000000000e+03)*a[10]);
out[45] = ((real_t)(0.0000000000000000e+00)-xd[3]);
out[46] = (real_t)(0.0000000000000000e+00);
out[47] = (real_t)(0.0000000000000000e+00);
out[48] = (real_t)(0.0000000000000000e+00);
out[49] = (real_t)(0.0000000000000000e+00);
out[50] = (real_t)(0.0000000000000000e+00);
out[51] = (real_t)(0.0000000000000000e+00);
out[52] = (real_t)(0.0000000000000000e+00);
out[53] = (real_t)(0.0000000000000000e+00);
out[54] = (real_t)(0.0000000000000000e+00);
out[55] = (((real_t)(0.0000000000000000e+00)-(real_t)(1.0400000000000000e+02))*a[11]);
out[56] = (real_t)(0.0000000000000000e+00);
out[57] = (real_t)(0.0000000000000000e+00);
out[58] = ((real_t)(8.0000000000000004e-01)*a[12]);
out[59] = (((real_t)(-8.0000000000000004e-01))*a[12]);
out[60] = (real_t)(0.0000000000000000e+00);
out[61] = (real_t)(0.0000000000000000e+00);
out[62] = (real_t)(0.0000000000000000e+00);
out[63] = (real_t)(0.0000000000000000e+00);
out[64] = (real_t)(0.0000000000000000e+00);
out[65] = (real_t)(0.0000000000000000e+00);
out[66] = (real_t)(0.0000000000000000e+00);
out[67] = (real_t)(0.0000000000000000e+00);
out[68] = (real_t)(0.0000000000000000e+00);
out[69] = (real_t)(0.0000000000000000e+00);
out[70] = (real_t)(0.0000000000000000e+00);
out[71] = (real_t)(0.0000000000000000e+00);
out[72] = (real_t)(0.0000000000000000e+00);
out[73] = (real_t)(0.0000000000000000e+00);
out[74] = (real_t)(0.0000000000000000e+00);
out[75] = (real_t)(0.0000000000000000e+00);
out[76] = (real_t)(0.0000000000000000e+00);
out[77] = (real_t)(0.0000000000000000e+00);
out[78] = (real_t)(0.0000000000000000e+00);
out[79] = (real_t)(0.0000000000000000e+00);
}



void acado_solve_dim16_triangular( real_t* const A, real_t* const b )
{

b[15] = b[15]/A[255];
b[14] -= + A[239]*b[15];
b[14] = b[14]/A[238];
b[13] -= + A[223]*b[15];
b[13] -= + A[222]*b[14];
b[13] = b[13]/A[221];
b[12] -= + A[207]*b[15];
b[12] -= + A[206]*b[14];
b[12] -= + A[205]*b[13];
b[12] = b[12]/A[204];
b[11] -= + A[191]*b[15];
b[11] -= + A[190]*b[14];
b[11] -= + A[189]*b[13];
b[11] -= + A[188]*b[12];
b[11] = b[11]/A[187];
b[10] -= + A[175]*b[15];
b[10] -= + A[174]*b[14];
b[10] -= + A[173]*b[13];
b[10] -= + A[172]*b[12];
b[10] -= + A[171]*b[11];
b[10] = b[10]/A[170];
b[9] -= + A[159]*b[15];
b[9] -= + A[158]*b[14];
b[9] -= + A[157]*b[13];
b[9] -= + A[156]*b[12];
b[9] -= + A[155]*b[11];
b[9] -= + A[154]*b[10];
b[9] = b[9]/A[153];
b[8] -= + A[143]*b[15];
b[8] -= + A[142]*b[14];
b[8] -= + A[141]*b[13];
b[8] -= + A[140]*b[12];
b[8] -= + A[139]*b[11];
b[8] -= + A[138]*b[10];
b[8] -= + A[137]*b[9];
b[8] = b[8]/A[136];
b[7] -= + A[127]*b[15];
b[7] -= + A[126]*b[14];
b[7] -= + A[125]*b[13];
b[7] -= + A[124]*b[12];
b[7] -= + A[123]*b[11];
b[7] -= + A[122]*b[10];
b[7] -= + A[121]*b[9];
b[7] -= + A[120]*b[8];
b[7] = b[7]/A[119];
b[6] -= + A[111]*b[15];
b[6] -= + A[110]*b[14];
b[6] -= + A[109]*b[13];
b[6] -= + A[108]*b[12];
b[6] -= + A[107]*b[11];
b[6] -= + A[106]*b[10];
b[6] -= + A[105]*b[9];
b[6] -= + A[104]*b[8];
b[6] -= + A[103]*b[7];
b[6] = b[6]/A[102];
b[5] -= + A[95]*b[15];
b[5] -= + A[94]*b[14];
b[5] -= + A[93]*b[13];
b[5] -= + A[92]*b[12];
b[5] -= + A[91]*b[11];
b[5] -= + A[90]*b[10];
b[5] -= + A[89]*b[9];
b[5] -= + A[88]*b[8];
b[5] -= + A[87]*b[7];
b[5] -= + A[86]*b[6];
b[5] = b[5]/A[85];
b[4] -= + A[79]*b[15];
b[4] -= + A[78]*b[14];
b[4] -= + A[77]*b[13];
b[4] -= + A[76]*b[12];
b[4] -= + A[75]*b[11];
b[4] -= + A[74]*b[10];
b[4] -= + A[73]*b[9];
b[4] -= + A[72]*b[8];
b[4] -= + A[71]*b[7];
b[4] -= + A[70]*b[6];
b[4] -= + A[69]*b[5];
b[4] = b[4]/A[68];
b[3] -= + A[63]*b[15];
b[3] -= + A[62]*b[14];
b[3] -= + A[61]*b[13];
b[3] -= + A[60]*b[12];
b[3] -= + A[59]*b[11];
b[3] -= + A[58]*b[10];
b[3] -= + A[57]*b[9];
b[3] -= + A[56]*b[8];
b[3] -= + A[55]*b[7];
b[3] -= + A[54]*b[6];
b[3] -= + A[53]*b[5];
b[3] -= + A[52]*b[4];
b[3] = b[3]/A[51];
b[2] -= + A[47]*b[15];
b[2] -= + A[46]*b[14];
b[2] -= + A[45]*b[13];
b[2] -= + A[44]*b[12];
b[2] -= + A[43]*b[11];
b[2] -= + A[42]*b[10];
b[2] -= + A[41]*b[9];
b[2] -= + A[40]*b[8];
b[2] -= + A[39]*b[7];
b[2] -= + A[38]*b[6];
b[2] -= + A[37]*b[5];
b[2] -= + A[36]*b[4];
b[2] -= + A[35]*b[3];
b[2] = b[2]/A[34];
b[1] -= + A[31]*b[15];
b[1] -= + A[30]*b[14];
b[1] -= + A[29]*b[13];
b[1] -= + A[28]*b[12];
b[1] -= + A[27]*b[11];
b[1] -= + A[26]*b[10];
b[1] -= + A[25]*b[9];
b[1] -= + A[24]*b[8];
b[1] -= + A[23]*b[7];
b[1] -= + A[22]*b[6];
b[1] -= + A[21]*b[5];
b[1] -= + A[20]*b[4];
b[1] -= + A[19]*b[3];
b[1] -= + A[18]*b[2];
b[1] = b[1]/A[17];
b[0] -= + A[15]*b[15];
b[0] -= + A[14]*b[14];
b[0] -= + A[13]*b[13];
b[0] -= + A[12]*b[12];
b[0] -= + A[11]*b[11];
b[0] -= + A[10]*b[10];
b[0] -= + A[9]*b[9];
b[0] -= + A[8]*b[8];
b[0] -= + A[7]*b[7];
b[0] -= + A[6]*b[6];
b[0] -= + A[5]*b[5];
b[0] -= + A[4]*b[4];
b[0] -= + A[3]*b[3];
b[0] -= + A[2]*b[2];
b[0] -= + A[1]*b[1];
b[0] = b[0]/A[0];
}

real_t acado_solve_dim16_system( real_t* const A, real_t* const b, int* const rk_perm )
{
real_t det;

int i;
int j;
int k;

int indexMax;

int intSwap;

real_t valueMax;

real_t temp;

for (i = 0; i < 16; ++i)
{
rk_perm[i] = i;
}
det = 1.0000000000000000e+00;
for( i=0; i < (15); i++ ) {
	indexMax = i;
	valueMax = fabs(A[i*16+i]);
	for( j=(i+1); j < 16; j++ ) {
		temp = fabs(A[j*16+i]);
		if( temp > valueMax ) {
			indexMax = j;
			valueMax = temp;
		}
	}
	if( indexMax > i ) {
for (k = 0; k < 16; ++k)
{
	acadoWorkspace.rk_dim16_swap = A[i*16+k];
	A[i*16+k] = A[indexMax*16+k];
	A[indexMax*16+k] = acadoWorkspace.rk_dim16_swap;
}
	acadoWorkspace.rk_dim16_swap = b[i];
	b[i] = b[indexMax];
	b[indexMax] = acadoWorkspace.rk_dim16_swap;
	intSwap = rk_perm[i];
	rk_perm[i] = rk_perm[indexMax];
	rk_perm[indexMax] = intSwap;
	}
	det *= A[i*16+i];
	for( j=i+1; j < 16; j++ ) {
		A[j*16+i] = -A[j*16+i]/A[i*16+i];
		for( k=i+1; k < 16; k++ ) {
			A[j*16+k] += A[j*16+i] * A[i*16+k];
		}
		b[j] += A[j*16+i] * b[i];
	}
}
det *= A[255];
det = fabs(det);
acado_solve_dim16_triangular( A, b );
return det;
}

void acado_solve_dim16_system_reuse( real_t* const A, real_t* const b, int* const rk_perm )
{

acadoWorkspace.rk_dim16_bPerm[0] = b[rk_perm[0]];
acadoWorkspace.rk_dim16_bPerm[1] = b[rk_perm[1]];
acadoWorkspace.rk_dim16_bPerm[2] = b[rk_perm[2]];
acadoWorkspace.rk_dim16_bPerm[3] = b[rk_perm[3]];
acadoWorkspace.rk_dim16_bPerm[4] = b[rk_perm[4]];
acadoWorkspace.rk_dim16_bPerm[5] = b[rk_perm[5]];
acadoWorkspace.rk_dim16_bPerm[6] = b[rk_perm[6]];
acadoWorkspace.rk_dim16_bPerm[7] = b[rk_perm[7]];
acadoWorkspace.rk_dim16_bPerm[8] = b[rk_perm[8]];
acadoWorkspace.rk_dim16_bPerm[9] = b[rk_perm[9]];
acadoWorkspace.rk_dim16_bPerm[10] = b[rk_perm[10]];
acadoWorkspace.rk_dim16_bPerm[11] = b[rk_perm[11]];
acadoWorkspace.rk_dim16_bPerm[12] = b[rk_perm[12]];
acadoWorkspace.rk_dim16_bPerm[13] = b[rk_perm[13]];
acadoWorkspace.rk_dim16_bPerm[14] = b[rk_perm[14]];
acadoWorkspace.rk_dim16_bPerm[15] = b[rk_perm[15]];
acadoWorkspace.rk_dim16_bPerm[1] += A[16]*acadoWorkspace.rk_dim16_bPerm[0];

acadoWorkspace.rk_dim16_bPerm[2] += A[32]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[2] += A[33]*acadoWorkspace.rk_dim16_bPerm[1];

acadoWorkspace.rk_dim16_bPerm[3] += A[48]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[3] += A[49]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[3] += A[50]*acadoWorkspace.rk_dim16_bPerm[2];

acadoWorkspace.rk_dim16_bPerm[4] += A[64]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[4] += A[65]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[4] += A[66]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[4] += A[67]*acadoWorkspace.rk_dim16_bPerm[3];

acadoWorkspace.rk_dim16_bPerm[5] += A[80]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[5] += A[81]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[5] += A[82]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[5] += A[83]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[5] += A[84]*acadoWorkspace.rk_dim16_bPerm[4];

acadoWorkspace.rk_dim16_bPerm[6] += A[96]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[6] += A[97]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[6] += A[98]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[6] += A[99]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[6] += A[100]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[6] += A[101]*acadoWorkspace.rk_dim16_bPerm[5];

acadoWorkspace.rk_dim16_bPerm[7] += A[112]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[7] += A[113]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[7] += A[114]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[7] += A[115]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[7] += A[116]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[7] += A[117]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[7] += A[118]*acadoWorkspace.rk_dim16_bPerm[6];

acadoWorkspace.rk_dim16_bPerm[8] += A[128]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[8] += A[129]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[8] += A[130]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[8] += A[131]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[8] += A[132]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[8] += A[133]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[8] += A[134]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[8] += A[135]*acadoWorkspace.rk_dim16_bPerm[7];

acadoWorkspace.rk_dim16_bPerm[9] += A[144]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[9] += A[145]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[9] += A[146]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[9] += A[147]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[9] += A[148]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[9] += A[149]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[9] += A[150]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[9] += A[151]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[9] += A[152]*acadoWorkspace.rk_dim16_bPerm[8];

acadoWorkspace.rk_dim16_bPerm[10] += A[160]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[10] += A[161]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[10] += A[162]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[10] += A[163]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[10] += A[164]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[10] += A[165]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[10] += A[166]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[10] += A[167]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[10] += A[168]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[10] += A[169]*acadoWorkspace.rk_dim16_bPerm[9];

acadoWorkspace.rk_dim16_bPerm[11] += A[176]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[11] += A[177]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[11] += A[178]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[11] += A[179]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[11] += A[180]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[11] += A[181]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[11] += A[182]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[11] += A[183]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[11] += A[184]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[11] += A[185]*acadoWorkspace.rk_dim16_bPerm[9];
acadoWorkspace.rk_dim16_bPerm[11] += A[186]*acadoWorkspace.rk_dim16_bPerm[10];

acadoWorkspace.rk_dim16_bPerm[12] += A[192]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[12] += A[193]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[12] += A[194]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[12] += A[195]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[12] += A[196]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[12] += A[197]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[12] += A[198]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[12] += A[199]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[12] += A[200]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[12] += A[201]*acadoWorkspace.rk_dim16_bPerm[9];
acadoWorkspace.rk_dim16_bPerm[12] += A[202]*acadoWorkspace.rk_dim16_bPerm[10];
acadoWorkspace.rk_dim16_bPerm[12] += A[203]*acadoWorkspace.rk_dim16_bPerm[11];

acadoWorkspace.rk_dim16_bPerm[13] += A[208]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[13] += A[209]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[13] += A[210]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[13] += A[211]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[13] += A[212]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[13] += A[213]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[13] += A[214]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[13] += A[215]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[13] += A[216]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[13] += A[217]*acadoWorkspace.rk_dim16_bPerm[9];
acadoWorkspace.rk_dim16_bPerm[13] += A[218]*acadoWorkspace.rk_dim16_bPerm[10];
acadoWorkspace.rk_dim16_bPerm[13] += A[219]*acadoWorkspace.rk_dim16_bPerm[11];
acadoWorkspace.rk_dim16_bPerm[13] += A[220]*acadoWorkspace.rk_dim16_bPerm[12];

acadoWorkspace.rk_dim16_bPerm[14] += A[224]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[14] += A[225]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[14] += A[226]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[14] += A[227]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[14] += A[228]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[14] += A[229]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[14] += A[230]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[14] += A[231]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[14] += A[232]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[14] += A[233]*acadoWorkspace.rk_dim16_bPerm[9];
acadoWorkspace.rk_dim16_bPerm[14] += A[234]*acadoWorkspace.rk_dim16_bPerm[10];
acadoWorkspace.rk_dim16_bPerm[14] += A[235]*acadoWorkspace.rk_dim16_bPerm[11];
acadoWorkspace.rk_dim16_bPerm[14] += A[236]*acadoWorkspace.rk_dim16_bPerm[12];
acadoWorkspace.rk_dim16_bPerm[14] += A[237]*acadoWorkspace.rk_dim16_bPerm[13];

acadoWorkspace.rk_dim16_bPerm[15] += A[240]*acadoWorkspace.rk_dim16_bPerm[0];
acadoWorkspace.rk_dim16_bPerm[15] += A[241]*acadoWorkspace.rk_dim16_bPerm[1];
acadoWorkspace.rk_dim16_bPerm[15] += A[242]*acadoWorkspace.rk_dim16_bPerm[2];
acadoWorkspace.rk_dim16_bPerm[15] += A[243]*acadoWorkspace.rk_dim16_bPerm[3];
acadoWorkspace.rk_dim16_bPerm[15] += A[244]*acadoWorkspace.rk_dim16_bPerm[4];
acadoWorkspace.rk_dim16_bPerm[15] += A[245]*acadoWorkspace.rk_dim16_bPerm[5];
acadoWorkspace.rk_dim16_bPerm[15] += A[246]*acadoWorkspace.rk_dim16_bPerm[6];
acadoWorkspace.rk_dim16_bPerm[15] += A[247]*acadoWorkspace.rk_dim16_bPerm[7];
acadoWorkspace.rk_dim16_bPerm[15] += A[248]*acadoWorkspace.rk_dim16_bPerm[8];
acadoWorkspace.rk_dim16_bPerm[15] += A[249]*acadoWorkspace.rk_dim16_bPerm[9];
acadoWorkspace.rk_dim16_bPerm[15] += A[250]*acadoWorkspace.rk_dim16_bPerm[10];
acadoWorkspace.rk_dim16_bPerm[15] += A[251]*acadoWorkspace.rk_dim16_bPerm[11];
acadoWorkspace.rk_dim16_bPerm[15] += A[252]*acadoWorkspace.rk_dim16_bPerm[12];
acadoWorkspace.rk_dim16_bPerm[15] += A[253]*acadoWorkspace.rk_dim16_bPerm[13];
acadoWorkspace.rk_dim16_bPerm[15] += A[254]*acadoWorkspace.rk_dim16_bPerm[14];


acado_solve_dim16_triangular( A, acadoWorkspace.rk_dim16_bPerm );
b[0] = acadoWorkspace.rk_dim16_bPerm[0];
b[1] = acadoWorkspace.rk_dim16_bPerm[1];
b[2] = acadoWorkspace.rk_dim16_bPerm[2];
b[3] = acadoWorkspace.rk_dim16_bPerm[3];
b[4] = acadoWorkspace.rk_dim16_bPerm[4];
b[5] = acadoWorkspace.rk_dim16_bPerm[5];
b[6] = acadoWorkspace.rk_dim16_bPerm[6];
b[7] = acadoWorkspace.rk_dim16_bPerm[7];
b[8] = acadoWorkspace.rk_dim16_bPerm[8];
b[9] = acadoWorkspace.rk_dim16_bPerm[9];
b[10] = acadoWorkspace.rk_dim16_bPerm[10];
b[11] = acadoWorkspace.rk_dim16_bPerm[11];
b[12] = acadoWorkspace.rk_dim16_bPerm[12];
b[13] = acadoWorkspace.rk_dim16_bPerm[13];
b[14] = acadoWorkspace.rk_dim16_bPerm[14];
b[15] = acadoWorkspace.rk_dim16_bPerm[15];
}



/** Matrix of size: 2 x 2 (row major format) */
static const real_t acado_Ah_mat[ 4 ] = 
{ 6.2500000000000000e-02, 1.3466878364870322e-01, 
-9.6687836487032164e-03, 6.2500000000000000e-02 };


/* Fixed step size:0.25 */
int acado_integrate( real_t* const rk_eta, int resetIntegrator )
{
int error;

int i;
int j;
int k;
int run;
int run1;
int tmp_index1;
int tmp_index2;

real_t det;

acadoWorkspace.rk_ttt = 0.0000000000000000e+00;
acadoWorkspace.rk_xxx[8] = rk_eta[88];
acadoWorkspace.rk_xxx[9] = rk_eta[89];
acadoWorkspace.rk_xxx[10] = rk_eta[90];
acadoWorkspace.rk_xxx[11] = rk_eta[91];
acadoWorkspace.rk_xxx[12] = rk_eta[92];
acadoWorkspace.rk_xxx[13] = rk_eta[93];
acadoWorkspace.rk_xxx[14] = rk_eta[94];

for (run = 0; run < 4; ++run)
{
if( run > 0 ) {
for (i = 0; i < 8; ++i)
{
acadoWorkspace.rk_diffsPrev2[i * 10] = rk_eta[i * 8 + 8];
acadoWorkspace.rk_diffsPrev2[i * 10 + 1] = rk_eta[i * 8 + 9];
acadoWorkspace.rk_diffsPrev2[i * 10 + 2] = rk_eta[i * 8 + 10];
acadoWorkspace.rk_diffsPrev2[i * 10 + 3] = rk_eta[i * 8 + 11];
acadoWorkspace.rk_diffsPrev2[i * 10 + 4] = rk_eta[i * 8 + 12];
acadoWorkspace.rk_diffsPrev2[i * 10 + 5] = rk_eta[i * 8 + 13];
acadoWorkspace.rk_diffsPrev2[i * 10 + 6] = rk_eta[i * 8 + 14];
acadoWorkspace.rk_diffsPrev2[i * 10 + 7] = rk_eta[i * 8 + 15];
acadoWorkspace.rk_diffsPrev2[i * 10 + 8] = rk_eta[i * 2 + 72];
acadoWorkspace.rk_diffsPrev2[i * 10 + 9] = rk_eta[i * 2 + 73];
}
}
if( resetIntegrator ) {
for (i = 0; i < 1; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 8; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 80 ]) );
for (j = 0; j < 8; ++j)
{
tmp_index1 = (run1 * 8) + (j);
acadoWorkspace.rk_A[tmp_index1 * 16] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 1] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 2] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 3] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 4] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 5] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 6] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 6)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 7] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 7)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 16) + (j)] -= 1.0000000000000000e+00;
acadoWorkspace.rk_A[tmp_index1 * 16 + 8] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 9] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 10] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 11] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 12] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 13] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 14] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 6)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 15] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 7)];
if( 1 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 16) + (j + 8)] -= 1.0000000000000000e+00;
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 8] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 8 + 1] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 8 + 2] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 8 + 3] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 8 + 4] = acadoWorkspace.rk_kkk[run1 + 8] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 8 + 5] = acadoWorkspace.rk_kkk[run1 + 10] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 8 + 6] = acadoWorkspace.rk_kkk[run1 + 12] - acadoWorkspace.rk_rhsTemp[6];
acadoWorkspace.rk_b[run1 * 8 + 7] = acadoWorkspace.rk_kkk[run1 + 14] - acadoWorkspace.rk_rhsTemp[7];
}
det = acado_solve_dim16_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim16_perm );
for (j = 0; j < 2; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 8];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 8 + 1];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 8 + 2];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 8 + 3];
acadoWorkspace.rk_kkk[j + 8] += acadoWorkspace.rk_b[j * 8 + 4];
acadoWorkspace.rk_kkk[j + 10] += acadoWorkspace.rk_b[j * 8 + 5];
acadoWorkspace.rk_kkk[j + 12] += acadoWorkspace.rk_b[j * 8 + 6];
acadoWorkspace.rk_kkk[j + 14] += acadoWorkspace.rk_b[j * 8 + 7];
}
}
}
for (i = 0; i < 5; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 8; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
acado_rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 8] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 8 + 1] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 8 + 2] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 8 + 3] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 8 + 4] = acadoWorkspace.rk_kkk[run1 + 8] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 8 + 5] = acadoWorkspace.rk_kkk[run1 + 10] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 8 + 6] = acadoWorkspace.rk_kkk[run1 + 12] - acadoWorkspace.rk_rhsTemp[6];
acadoWorkspace.rk_b[run1 * 8 + 7] = acadoWorkspace.rk_kkk[run1 + 14] - acadoWorkspace.rk_rhsTemp[7];
}
acado_solve_dim16_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim16_perm );
for (j = 0; j < 2; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 8];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 8 + 1];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 8 + 2];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 8 + 3];
acadoWorkspace.rk_kkk[j + 8] += acadoWorkspace.rk_b[j * 8 + 4];
acadoWorkspace.rk_kkk[j + 10] += acadoWorkspace.rk_b[j * 8 + 5];
acadoWorkspace.rk_kkk[j + 12] += acadoWorkspace.rk_b[j * 8 + 6];
acadoWorkspace.rk_kkk[j + 14] += acadoWorkspace.rk_b[j * 8 + 7];
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 8; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
acado_diffs( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 80 ]) );
for (j = 0; j < 8; ++j)
{
tmp_index1 = (run1 * 8) + (j);
acadoWorkspace.rk_A[tmp_index1 * 16] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 1] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 2] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 3] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 4] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 5] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 6] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 6)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 7] = + acado_Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 7)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 16) + (j)] -= 1.0000000000000000e+00;
acadoWorkspace.rk_A[tmp_index1 * 16 + 8] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 9] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 10] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 11] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 12] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 13] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 14] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 6)];
acadoWorkspace.rk_A[tmp_index1 * 16 + 15] = + acado_Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 80) + (j * 10 + 7)];
if( 1 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 16) + (j + 8)] -= 1.0000000000000000e+00;
}
}
for (run1 = 0; run1 < 8; ++run1)
{
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_b[i * 8] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1)];
acadoWorkspace.rk_b[i * 8 + 1] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 10)];
acadoWorkspace.rk_b[i * 8 + 2] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 20)];
acadoWorkspace.rk_b[i * 8 + 3] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 30)];
acadoWorkspace.rk_b[i * 8 + 4] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 40)];
acadoWorkspace.rk_b[i * 8 + 5] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 50)];
acadoWorkspace.rk_b[i * 8 + 6] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 60)];
acadoWorkspace.rk_b[i * 8 + 7] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (run1 + 70)];
}
if( 0 == run1 ) {
det = acado_solve_dim16_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim16_perm );
}
 else {
acado_solve_dim16_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim16_perm );
}
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 8];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 8 + 1];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 8 + 2];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 8 + 3];
acadoWorkspace.rk_diffK[i + 8] = acadoWorkspace.rk_b[i * 8 + 4];
acadoWorkspace.rk_diffK[i + 10] = acadoWorkspace.rk_b[i * 8 + 5];
acadoWorkspace.rk_diffK[i + 12] = acadoWorkspace.rk_b[i * 8 + 6];
acadoWorkspace.rk_diffK[i + 14] = acadoWorkspace.rk_b[i * 8 + 7];
}
for (i = 0; i < 8; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 10) + (run1)] = (i == run1-0);
acadoWorkspace.rk_diffsNew2[(i * 10) + (run1)] += + acadoWorkspace.rk_diffK[i * 2]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_diffK[i * 2 + 1]*(real_t)1.2500000000000000e-01;
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (i = 0; i < 2; ++i)
{
for (j = 0; j < 8; ++j)
{
tmp_index1 = (i * 8) + (j);
tmp_index2 = (run1) + (j * 10);
acadoWorkspace.rk_b[tmp_index1] = - acadoWorkspace.rk_diffsTemp2[(i * 80) + (tmp_index2 + 8)];
}
}
acado_solve_dim16_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim16_perm );
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 8];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 8 + 1];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 8 + 2];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 8 + 3];
acadoWorkspace.rk_diffK[i + 8] = acadoWorkspace.rk_b[i * 8 + 4];
acadoWorkspace.rk_diffK[i + 10] = acadoWorkspace.rk_b[i * 8 + 5];
acadoWorkspace.rk_diffK[i + 12] = acadoWorkspace.rk_b[i * 8 + 6];
acadoWorkspace.rk_diffK[i + 14] = acadoWorkspace.rk_b[i * 8 + 7];
}
for (i = 0; i < 8; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 10) + (run1 + 8)] = + acadoWorkspace.rk_diffK[i * 2]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_diffK[i * 2 + 1]*(real_t)1.2500000000000000e-01;
}
}
rk_eta[0] += + acadoWorkspace.rk_kkk[0]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[1]*(real_t)1.2500000000000000e-01;
rk_eta[1] += + acadoWorkspace.rk_kkk[2]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[3]*(real_t)1.2500000000000000e-01;
rk_eta[2] += + acadoWorkspace.rk_kkk[4]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[5]*(real_t)1.2500000000000000e-01;
rk_eta[3] += + acadoWorkspace.rk_kkk[6]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[7]*(real_t)1.2500000000000000e-01;
rk_eta[4] += + acadoWorkspace.rk_kkk[8]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[9]*(real_t)1.2500000000000000e-01;
rk_eta[5] += + acadoWorkspace.rk_kkk[10]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[11]*(real_t)1.2500000000000000e-01;
rk_eta[6] += + acadoWorkspace.rk_kkk[12]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[13]*(real_t)1.2500000000000000e-01;
rk_eta[7] += + acadoWorkspace.rk_kkk[14]*(real_t)1.2500000000000000e-01 + acadoWorkspace.rk_kkk[15]*(real_t)1.2500000000000000e-01;
if( run == 0 ) {
for (i = 0; i < 8; ++i)
{
for (j = 0; j < 8; ++j)
{
tmp_index2 = (j) + (i * 8);
rk_eta[tmp_index2 + 8] = acadoWorkspace.rk_diffsNew2[(i * 10) + (j)];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 72] = acadoWorkspace.rk_diffsNew2[(i * 10) + (j + 8)];
}
}
}
else {
for (i = 0; i < 8; ++i)
{
for (j = 0; j < 8; ++j)
{
tmp_index2 = (j) + (i * 8);
rk_eta[tmp_index2 + 8] = + acadoWorkspace.rk_diffsNew2[i * 10]*acadoWorkspace.rk_diffsPrev2[j];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 1]*acadoWorkspace.rk_diffsPrev2[j + 10];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 2]*acadoWorkspace.rk_diffsPrev2[j + 20];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 3]*acadoWorkspace.rk_diffsPrev2[j + 30];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 4]*acadoWorkspace.rk_diffsPrev2[j + 40];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 5]*acadoWorkspace.rk_diffsPrev2[j + 50];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 6]*acadoWorkspace.rk_diffsPrev2[j + 60];
rk_eta[tmp_index2 + 8] += + acadoWorkspace.rk_diffsNew2[i * 10 + 7]*acadoWorkspace.rk_diffsPrev2[j + 70];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 72] = acadoWorkspace.rk_diffsNew2[(i * 10) + (j + 8)];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10]*acadoWorkspace.rk_diffsPrev2[j + 8];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 1]*acadoWorkspace.rk_diffsPrev2[j + 18];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 2]*acadoWorkspace.rk_diffsPrev2[j + 28];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 3]*acadoWorkspace.rk_diffsPrev2[j + 38];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 4]*acadoWorkspace.rk_diffsPrev2[j + 48];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 5]*acadoWorkspace.rk_diffsPrev2[j + 58];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 6]*acadoWorkspace.rk_diffsPrev2[j + 68];
rk_eta[tmp_index2 + 72] += + acadoWorkspace.rk_diffsNew2[i * 10 + 7]*acadoWorkspace.rk_diffsPrev2[j + 78];
}
}
}
resetIntegrator = 0;
acadoWorkspace.rk_ttt += 2.5000000000000000e-01;
}
for (i = 0; i < 8; ++i)
{
}
if( det < 1e-12 ) {
error = 2;
} else if( det < 1e-6 ) {
error = 1;
} else {
error = 0;
}
return error;
}



