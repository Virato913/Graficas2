#include "stdafx.h"
#include "MyMath.h"

void XMatMultiply(XMATRIX44 &mpout, const XMATRIX44 &A, const XMATRIX44 &B)
{
	mpout = A*B;
}
void XMatTranslation(XMATRIX44 &mpout, const float &x, const float &y, const float &z) {
	/*mpout.m11 += x;
	mpout.m21 += y;
	mpout.m31 += z;
	mpout.m12 += x;
	mpout.m22 += y;
	mpout.m32 += z;
	mpout.m13 += x;
	mpout.m23 += y;
	mpout.m33 += z;
	mpout.m14 += x;
	mpout.m24 += y;
	mpout.m34 += z;*/
	mpout.m41 += x;
	mpout.m42 += y;
	mpout.m43 += z;
}
void XMatTranslation(XMATRIX44 &mpout, XVECTOR3 &translation) {
	/*mpout.m11 += translation.x;
	mpout.m21 += translation.y;
	mpout.m31 += translation.z;
	mpout.m12 += translation.x;
	mpout.m22 += translation.y;
	mpout.m32 += translation.z;
	mpout.m13 += translation.x;
	mpout.m23 += translation.y;
	mpout.m33 += translation.z;
	mpout.m14 += translation.x;
	mpout.m24 += translation.y;
	mpout.m34 += translation.z;*/
	mpout.m41 += translation.x;
	mpout.m42 += translation.y;
	mpout.m43 += translation.z;
}
void XMatScaling(XMATRIX44 &mpout, const float &x, const float &y, const float &z) {
	mpout.m11 *= x;
	//mpout.m21 *= y;
	//mpout.m31 *= z;

	//mpout.m12 *= x;
	mpout.m22 *= y;
	//mpout.m32 *= z;

	//mpout.m13 *= x;
	//mpout.m23 *= y;
	mpout.m33 *= z;

	/*mpout.m14 *= x;
	mpout.m24 *= y;
	mpout.m34 *= z;*/
}
void XMatRotationXLH(XMATRIX44 &mpout, const float &x) {
	XMATRIX44 pivot = mpout;
	mpout.m21 = pivot.m21*cos(x) + pivot.m31*sin(x);
	mpout.m31 = -pivot.m21*sin(x) + pivot.m31*cos(x);

	mpout.m22 = pivot.m22*cos(x) + pivot.m32*sin(x);
	mpout.m32 = -pivot.m22*sin(x) + pivot.m32*cos(x);

	mpout.m23 = pivot.m23*cos(x) + pivot.m33*sin(x);
	mpout.m33 = -pivot.m23*sin(x) + pivot.m33*cos(x);

	mpout.m24 = pivot.m24*cos(x) + pivot.m34*sin(x);
	mpout.m34 = -pivot.m24*sin(x) + pivot.m34*cos(x);

}
void XMatRotationXRH(XMATRIX44 &mpout, const float &x) {
	XMATRIX44 pivot = mpout;
	mpout.m21 = pivot.m21*cos(x) - pivot.m31*sin(x);
	mpout.m31 = pivot.m21*sin(x) + pivot.m31*cos(x);

	mpout.m22 = pivot.m22*cos(x) - pivot.m32*sin(x);
	mpout.m32 = pivot.m22*sin(x) + pivot.m32*cos(x);

	mpout.m23 = pivot.m23*cos(x) - pivot.m33*sin(x);
	mpout.m33 = pivot.m23*sin(x) + pivot.m33*cos(x);

	mpout.m24 = pivot.m24*cos(x) - pivot.m34*sin(x);
	mpout.m34 = pivot.m24*sin(x) + pivot.m34*cos(x);
}
void XMatRotationYLH(XMATRIX44 &mpout, const float &y) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(y) - pivot.m31*sin(y);
	mpout.m31 = pivot.m11*sin(y) + pivot.m31*cos(y);

	mpout.m12 = pivot.m12*cos(y) - pivot.m32*sin(y);
	mpout.m32 = pivot.m12*sin(y) + pivot.m32*cos(y);

	mpout.m13 = pivot.m13*cos(y) - pivot.m33*sin(y);
	mpout.m33 = pivot.m13*sin(y) + pivot.m33*cos(y);

	mpout.m14 = pivot.m14*cos(y) - pivot.m34*sin(y);
	mpout.m34 = pivot.m14*sin(y) + pivot.m34*cos(y);
}
void XMatRotationYRH(XMATRIX44 &mpout, const float &y) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(y) + pivot.m31*sin(y);
	mpout.m31 = -pivot.m11*sin(y) + pivot.m31*cos(y);

	mpout.m12 = pivot.m12*cos(y) + pivot.m32*sin(y);
	mpout.m32 = -pivot.m12*sin(y) + pivot.m32*cos(y);

	mpout.m13 = pivot.m13*cos(y) + pivot.m33*sin(y);
	mpout.m33 = -pivot.m13*sin(y) + pivot.m33*cos(y);

	mpout.m14 = pivot.m14*cos(y) + pivot.m34*sin(y);
	mpout.m34 = -pivot.m14*sin(y) + pivot.m34*cos(y);
}
void XMatRotationZLH(XMATRIX44 &mpout, const float &z) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(z) + pivot.m21*sin(z);
	mpout.m21 = -pivot.m11*sin(z) + pivot.m21*cos(z);

	mpout.m12 = pivot.m12*cos(z) + pivot.m22*sin(z);
	mpout.m22 = -pivot.m12*sin(z) + pivot.m22*cos(z);

	mpout.m13 = pivot.m13*cos(z) + pivot.m23*sin(z);
	mpout.m23 = -pivot.m13*sin(z) + pivot.m23*cos(z);

	mpout.m14 = pivot.m14*cos(z) + pivot.m24*sin(z);
	mpout.m24 = -pivot.m14*sin(z) + pivot.m24*cos(z);
}
void XMatRotationZRH(XMATRIX44 &mpout, const float &z) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(z) - pivot.m21*sin(z);
	mpout.m21 = pivot.m11*sin(z) + pivot.m21*cos(z);

	mpout.m12 = pivot.m12*cos(z) - pivot.m22*sin(z);
	mpout.m22 = pivot.m12*sin(z) + pivot.m22*cos(z);

	mpout.m13 = pivot.m13*cos(z) - pivot.m23*sin(z);
	mpout.m23 = pivot.m13*sin(z) + pivot.m23*cos(z);

	mpout.m14 = pivot.m14*cos(z) - pivot.m24*sin(z);
	mpout.m24 = pivot.m14*sin(z) + pivot.m24*cos(z);
}
void XMatTranspose(XMATRIX44 &mpout, XMATRIX44 A) {
	mpout = A;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mpout.m[j][i] = A.m[i][j];
		}
	}
}
void XMatIdentity(XMATRIX44 &mpout) {
	mpout *= 0;
	mpout.m11 = 1;
	mpout.m22 = 1;
	mpout.m33 = 1;
	mpout.m44 = 1;
}

void XMatViewLookAtLH(XMATRIX44 &mpout, const XVECTOR3 &camPos, const XVECTOR3 &lookAt, const XVECTOR3 &upAxis) {
	XVECTOR3 zaxe = lookAt - camPos;
	zaxe.Normalize();

	XVECTOR3 xaxe;
	XVecCross(xaxe, upAxis, zaxe);
	xaxe.Normalize();

	XVECTOR3 yaxe;
	XVecCross(yaxe, zaxe, xaxe);

	mpout.m[0][0] = xaxe.x;
	mpout.m[0][1] = yaxe.x;
	mpout.m[0][2] = zaxe.x;
	XVecDot(mpout.m[3][0], xaxe, camPos);
	mpout.m[3][0] = -mpout.m[3][0];

	mpout.m[1][0] = xaxe.y;
	mpout.m[1][1] = yaxe.y;
	mpout.m[1][2] = zaxe.y;
	XVecDot(mpout.m[3][1], yaxe, camPos);
	mpout.m[3][1] = -mpout.m[3][1];

	mpout.m[2][0] = xaxe.z;
	mpout.m[2][1] = yaxe.z;
	mpout.m[2][2] = zaxe.z;
	XVecDot(mpout.m[3][2], zaxe, camPos);
	mpout.m[3][2] = -mpout.m[3][2];

	mpout.m[0][3] = 0.0f;
	mpout.m[1][3] = 0.0f;
	mpout.m[2][3] = 0.0f;
	mpout.m[3][3] = 1.0f;
}

void XMatViewLookAtRH(XMATRIX44 &mpout, const XVECTOR3 &camPos, const XVECTOR3 &lookAt, const XVECTOR3 &upAxis) {
	XVECTOR3 zaxe = camPos - lookAt;
	zaxe.Normalize();

	XVECTOR3 xaxe;
	XVecCross(xaxe, upAxis, zaxe);
	xaxe.Normalize();

	XVECTOR3 yaxe;
	XVecCross(yaxe, zaxe, xaxe);

	mpout.m[0][0] = xaxe.x;
	mpout.m[0][1] = yaxe.x;
	mpout.m[0][2] = zaxe.x;
	XVecDot(mpout.m[3][0], xaxe, camPos);
	mpout.m[3][0] = -mpout.m[3][0];

	mpout.m[1][0] = xaxe.y;
	mpout.m[1][1] = yaxe.y;
	mpout.m[1][2] = zaxe.y;
	XVecDot(mpout.m[3][1], yaxe, camPos);
	mpout.m[3][1] = -mpout.m[3][1];

	mpout.m[2][0] = xaxe.z;
	mpout.m[2][1] = yaxe.z;
	mpout.m[2][2] = zaxe.z;
	XVecDot(mpout.m[3][2], zaxe, camPos);
	mpout.m[3][2] = -mpout.m[3][2];

	mpout.m[0][3] = 0.0f;
	mpout.m[1][3] = 0.0f;
	mpout.m[2][3] = 0.0f;
	mpout.m[3][3] = 1.0f;
}

void XMatPerspectiveLH(XMATRIX44 &mpout, const float &FOV, const float &Aspect, const float &NearPlane, const float &FarPlane) {
	float x, y;
	float ang = FOV / 2.0f;

	y = cos(ang) / sin(ang);
	x = y / Aspect;

	mpout.m[0][0] = x;
	mpout.m[1][1] = y;
	mpout.m[2][2] = FarPlane / (FarPlane - NearPlane);
	mpout.m[2][3] = 1.0;
	mpout.m[3][2] = -(NearPlane*FarPlane) / (FarPlane - NearPlane);
	mpout.m[3][3] = 0.0f;

}

void XMatPerspectiveRH(XMATRIX44 &mpout, const float &FOV, const float &Aspect, const float &NearPlane, const float &FarPlane)
{
	float x, y;
	float ang = FOV / 2.0f;

	y = cos(ang) / sin(ang);
	x = y / Aspect;

	mpout.m[0][0] = x;
	mpout.m[1][1] = y;
	mpout.m[2][2] = FarPlane / (NearPlane - FarPlane);
	mpout.m[2][3] = -1.0;
	mpout.m[3][2] = (NearPlane*FarPlane) / (NearPlane - FarPlane);
	mpout.m[3][3] = 0.0f;
}

void XMatOrthoLH(XMATRIX44 &m, const float &w, const float &h, const float &zn, const float &zf) {
	m.m[0][0] = 2.0f / w;
	m.m[1][1] = 2.0f / h;
	m.m[2][2] = 1.0f / (zf - zn);
	m.m[3][2] = -zn / (zf - zn);
	m.m[3][3] = 1.0f;
}

void XMatOrthoRH(XMATRIX44 &m, const float &w, const float &h, const float &zn, const float &zf) {
	m.m[0][0] = 2.0f / w;
	m.m[1][1] = 2.0f / h;
	m.m[2][2] = 1.0f / (zn - zf);
	m.m[3][2] = zn / (zn - zf);
	m.m[3][3] = 1.0f;
}

void XMATRIX44::Inverse(XMATRIX44 *o) {
#if DOUBLE_FOR_INVERSE
	XMATRIX44_64 tmp64 = XMATRIX44_64(this);
	double det =
#else
	XMATRIX44 tmp64 = *this;
	float det =
#endif
		tmp64.m11*tmp64.m22*tmp64.m33*tmp64.m44 + tmp64.m11*tmp64.m23*tmp64.m34*tmp64.m42 + tmp64.m11*tmp64.m24*tmp64.m32*tmp64.m43
		+ tmp64.m12*tmp64.m21*tmp64.m34*tmp64.m43 + tmp64.m12*tmp64.m23*tmp64.m31*tmp64.m44 + tmp64.m12*tmp64.m24*tmp64.m33*tmp64.m41
		+ tmp64.m13*tmp64.m21*tmp64.m32*tmp64.m44 + tmp64.m13*tmp64.m22*tmp64.m34*tmp64.m41 + tmp64.m13*tmp64.m24*tmp64.m31*tmp64.m42
		+ tmp64.m14*tmp64.m21*tmp64.m33*tmp64.m42 + tmp64.m14*tmp64.m22*tmp64.m31*tmp64.m43 + tmp64.m14*tmp64.m23*tmp64.m32*tmp64.m41
		- tmp64.m11*tmp64.m22*tmp64.m34*tmp64.m43 - tmp64.m11*tmp64.m23*tmp64.m32*tmp64.m44 - tmp64.m11*tmp64.m24*tmp64.m33*tmp64.m42
		- tmp64.m12*tmp64.m21*tmp64.m33*tmp64.m44 - tmp64.m12*tmp64.m23*tmp64.m34*tmp64.m41 - tmp64.m12*tmp64.m24*tmp64.m31*tmp64.m43
		- tmp64.m13*tmp64.m21*tmp64.m34*tmp64.m42 - tmp64.m13*tmp64.m22*tmp64.m31*tmp64.m44 - tmp64.m13*tmp64.m24*tmp64.m32*tmp64.m41
		- tmp64.m14*tmp64.m21*tmp64.m32*tmp64.m43 - tmp64.m14*tmp64.m22*tmp64.m33*tmp64.m41 - tmp64.m14*tmp64.m23*tmp64.m31*tmp64.m42;
#if DOUBLE_FOR_INVERSE
	if (det == 0.0) {
#else
	if (det == 0.0f) {
#endif
		printf("\n\nThe Universe stopped, no det for Matrix, all ends here.\n\n");
		exit(666);
	}
#if DOUBLE_FOR_INVERSE
	det = 1.0 / det;
	XMATRIX44_64 out;
#else
	det = 1.0f / det;
	XMATRIX44 out;
#endif

	out.m11 = tmp64.m22*tmp64.m33*tmp64.m44 + tmp64.m23*tmp64.m34*tmp64.m42 + tmp64.m24*tmp64.m32*tmp64.m43 - tmp64.m22*tmp64.m34*tmp64.m43 - tmp64.m23*tmp64.m32*tmp64.m44 - tmp64.m24*tmp64.m33*tmp64.m42;
	out.m12 = tmp64.m12*tmp64.m34*tmp64.m43 + tmp64.m13*tmp64.m32*tmp64.m44 + tmp64.m14*tmp64.m33*tmp64.m42 - tmp64.m12*tmp64.m33*tmp64.m44 - tmp64.m13*tmp64.m34*tmp64.m42 - tmp64.m14*tmp64.m32*tmp64.m43;
	out.m13 = tmp64.m12*tmp64.m23*tmp64.m44 + tmp64.m13*tmp64.m24*tmp64.m42 + tmp64.m14*tmp64.m22*tmp64.m43 - tmp64.m12*tmp64.m24*tmp64.m43 - tmp64.m13*tmp64.m22*tmp64.m44 - tmp64.m14*tmp64.m23*tmp64.m42;
	out.m14 = tmp64.m12*tmp64.m24*tmp64.m33 + tmp64.m13*tmp64.m22*tmp64.m34 + tmp64.m14*tmp64.m23*tmp64.m32 - tmp64.m12*tmp64.m23*tmp64.m34 - tmp64.m13*tmp64.m24*tmp64.m32 - tmp64.m14*tmp64.m22*tmp64.m33;
	out.m21 = tmp64.m21*tmp64.m34*tmp64.m43 + tmp64.m23*tmp64.m31*tmp64.m44 + tmp64.m24*tmp64.m33*tmp64.m41 - tmp64.m21*tmp64.m33*tmp64.m44 - tmp64.m23*tmp64.m34*tmp64.m41 - tmp64.m24*tmp64.m31*tmp64.m43;
	out.m22 = tmp64.m11*tmp64.m33*tmp64.m44 + tmp64.m13*tmp64.m34*tmp64.m41 + tmp64.m14*tmp64.m31*tmp64.m43 - tmp64.m11*tmp64.m34*tmp64.m43 - tmp64.m13*tmp64.m31*tmp64.m44 - tmp64.m14*tmp64.m33*tmp64.m41;
	out.m23 = tmp64.m11*tmp64.m24*tmp64.m43 + tmp64.m13*tmp64.m21*tmp64.m44 + tmp64.m14*tmp64.m23*tmp64.m41 - tmp64.m11*tmp64.m23*tmp64.m44 - tmp64.m13*tmp64.m24*tmp64.m41 - tmp64.m14*tmp64.m21*tmp64.m43;
	out.m24 = tmp64.m11*tmp64.m23*tmp64.m34 + tmp64.m13*tmp64.m24*tmp64.m31 + tmp64.m14*tmp64.m21*tmp64.m33 - tmp64.m11*tmp64.m24*tmp64.m33 - tmp64.m13*tmp64.m21*tmp64.m34 - tmp64.m14*tmp64.m23*tmp64.m31;
	out.m31 = tmp64.m21*tmp64.m32*tmp64.m44 + tmp64.m22*tmp64.m34*tmp64.m41 + tmp64.m24*tmp64.m31*tmp64.m42 - tmp64.m21*tmp64.m34*tmp64.m42 - tmp64.m22*tmp64.m31*tmp64.m44 - tmp64.m24*tmp64.m32*tmp64.m41;
	out.m32 = tmp64.m11*tmp64.m34*tmp64.m42 + tmp64.m12*tmp64.m31*tmp64.m44 + tmp64.m14*tmp64.m32*tmp64.m41 - tmp64.m11*tmp64.m32*tmp64.m44 - tmp64.m12*tmp64.m34*tmp64.m41 - tmp64.m14*tmp64.m31*tmp64.m42;
	out.m33 = tmp64.m11*tmp64.m22*tmp64.m44 + tmp64.m12*tmp64.m24*tmp64.m41 + tmp64.m14*tmp64.m21*tmp64.m42 - tmp64.m11*tmp64.m24*tmp64.m42 - tmp64.m12*tmp64.m21*tmp64.m44 - tmp64.m14*tmp64.m22*tmp64.m41;
	out.m34 = tmp64.m11*tmp64.m24*tmp64.m32 + tmp64.m12*tmp64.m21*tmp64.m34 + tmp64.m14*tmp64.m22*tmp64.m31 - tmp64.m11*tmp64.m22*tmp64.m34 - tmp64.m12*tmp64.m24*tmp64.m31 - tmp64.m14*tmp64.m21*tmp64.m32;
	out.m41 = tmp64.m21*tmp64.m33*tmp64.m42 + tmp64.m22*tmp64.m31*tmp64.m43 + tmp64.m23*tmp64.m32*tmp64.m41 - tmp64.m21*tmp64.m32*tmp64.m43 - tmp64.m22*tmp64.m33*tmp64.m41 - tmp64.m23*tmp64.m31*tmp64.m42;
	out.m42 = tmp64.m11*tmp64.m32*tmp64.m43 + tmp64.m12*tmp64.m33*tmp64.m41 + tmp64.m13*tmp64.m31*tmp64.m42 - tmp64.m11*tmp64.m33*tmp64.m42 - tmp64.m12*tmp64.m31*tmp64.m43 - tmp64.m13*tmp64.m32*tmp64.m41;
	out.m43 = tmp64.m11*tmp64.m23*tmp64.m42 + tmp64.m12*tmp64.m21*tmp64.m43 + tmp64.m13*tmp64.m22*tmp64.m41 - tmp64.m11*tmp64.m22*tmp64.m43 - tmp64.m12*tmp64.m23*tmp64.m41 - tmp64.m13*tmp64.m21*tmp64.m42;
	out.m44 = tmp64.m11*tmp64.m22*tmp64.m33 + tmp64.m12*tmp64.m23*tmp64.m31 + tmp64.m13*tmp64.m21*tmp64.m32 - tmp64.m11*tmp64.m23*tmp64.m32 - tmp64.m12*tmp64.m21*tmp64.m33 - tmp64.m13*tmp64.m22*tmp64.m31;

	for (int i = 0; i < 16; i++) {
#if DOUBLE_FOR_INVERSE
		double val = det*out.mat[i];
		(*o).mat[i] = static_cast<float>(val);
#else
		(*o).mat[i] = det*out.mat[i];
#endif
	}
	}

void XMatRotationAxisRH(XMATRIX44 &mpout, const XVECTOR3 &A, const float &B) {
	XMATRIX44 Temp = mpout;
	XVECTOR3 Normal;
	float cosB = cos(B);
	float sinB = sin(B);
	float oneminusc = (1 - cosB);
	XVec3Normalize(Normal, A);
	Temp.m11 = (
		(mpout.m11*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m21*((Normal.x*Normal.y*oneminusc) + (sinB*Normal.z))) +
		(mpout.m31*((Normal.x*Normal.z*oneminusc) - (sinB*Normal.y)))
		);
	Temp.m12 = (
		(mpout.m12*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m22*((Normal.x*Normal.y*oneminusc) + (sinB*Normal.z))) +
		(mpout.m32*((Normal.x*Normal.z*oneminusc) - (sinB*Normal.y)))
		);
	Temp.m13 = (
		(mpout.m13*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m23*((Normal.x*Normal.y*oneminusc) + (sinB*Normal.z))) +
		(mpout.m33*((Normal.x*Normal.z*oneminusc) - (sinB*Normal.y)))
		);
	Temp.m14 = (
		(mpout.m14*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m24*((Normal.x*Normal.y*oneminusc) + (sinB*Normal.z))) +
		(mpout.m34*((Normal.x*Normal.z*oneminusc) - (sinB*Normal.y)))
		);

	Temp.m21 = (
		(mpout.m11*((Normal.y*Normal.x*oneminusc) - (sinB*Normal.z))) +
		(mpout.m21*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m31*((Normal.y*Normal.z*oneminusc) + (sinB*Normal.x)))
		);
	Temp.m22 = (
		(mpout.m12*((Normal.y*Normal.x*oneminusc) - (sinB*Normal.z))) +
		(mpout.m22*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m33*((Normal.y*Normal.z*oneminusc) + (sinB*Normal.x)))
		);
	Temp.m23 = (
		(mpout.m13*((Normal.y*Normal.x*oneminusc) - (sinB*Normal.z))) +
		(mpout.m23*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m33*((Normal.y*Normal.z*oneminusc) + (sinB*Normal.x)))
		);
	Temp.m24 = (
		(mpout.m14*((Normal.y*Normal.x*oneminusc) - (sinB*Normal.z))) +
		(mpout.m24*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m34*((Normal.y*Normal.z*oneminusc) + (sinB*Normal.x)))
		);
	Temp.m31 = (
		(mpout.m11*((Normal.z*Normal.x*oneminusc) + (sinB*Normal.y))) +
		(mpout.m21*((Normal.z*Normal.y*oneminusc) - (sinB*Normal.x))) +
		(mpout.m31*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m32 = (
		(mpout.m12*((Normal.z*Normal.x*oneminusc) + (sinB*Normal.y))) +
		(mpout.m22*((Normal.z*Normal.y*oneminusc) - (sinB*Normal.x))) +
		(mpout.m32*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m33 = (
		(mpout.m13*((Normal.z*Normal.x*oneminusc) + (sinB*Normal.y))) +
		(mpout.m23*((Normal.z*Normal.y*oneminusc) - (sinB*Normal.x))) +
		(mpout.m33*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m34 = (
		(mpout.m14*((Normal.z*Normal.x*oneminusc) + (sinB*Normal.y))) +
		(mpout.m24*((Normal.z*Normal.y*oneminusc) - (sinB*Normal.x))) +
		(mpout.m34*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	mpout = Temp;
}
void XMatRotationAxisLH(XMATRIX44 &mpout, const XVECTOR3 &A, const float &B) {
	XMATRIX44 Temp = mpout;
	XVECTOR3 Normal;
	float cosB = cos(B);
	float sinB = sin(B);
	float oneminusc = (1 - cosB);
	XVec3Normalize(Normal, A);
	Temp.m11 = (
		(mpout.m11*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m21*((Normal.x*Normal.y*oneminusc) - (sinB*Normal.z))) +
		(mpout.m31*((Normal.x*Normal.z*oneminusc) + (sinB*Normal.y)))
		);
	Temp.m12 = (
		(mpout.m12*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m22*((Normal.x*Normal.y*oneminusc) - (sinB*Normal.z))) +
		(mpout.m32*((Normal.x*Normal.z*oneminusc) + (sinB*Normal.y)))
		);
	Temp.m13 = (
		(mpout.m13*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m23*((Normal.x*Normal.y*oneminusc) - (sinB*Normal.z))) +
		(mpout.m33*((Normal.x*Normal.z*oneminusc) + (sinB*Normal.y)))
		);
	Temp.m14 = (
		(mpout.m14*((Normal.x*Normal.x*oneminusc) + cosB)) +
		(mpout.m24*((Normal.x*Normal.y*oneminusc) - (sinB*Normal.z))) +
		(mpout.m34*((Normal.x*Normal.z*oneminusc) + (sinB*Normal.y)))
		);

	Temp.m21 = (
		(mpout.m11*((Normal.y*Normal.x*oneminusc) + (sinB*Normal.z))) +
		(mpout.m21*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m31*((Normal.y*Normal.z*oneminusc) - (sinB*Normal.x)))
		);
	Temp.m22 = (
		(mpout.m12*((Normal.y*Normal.x*oneminusc) + (sinB*Normal.z))) +
		(mpout.m22*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m33*((Normal.y*Normal.z*oneminusc) - (sinB*Normal.x)))
		);
	Temp.m23 = (
		(mpout.m13*((Normal.y*Normal.x*oneminusc) + (sinB*Normal.z))) +
		(mpout.m23*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m33*((Normal.y*Normal.z*oneminusc) - (sinB*Normal.x)))
		);
	Temp.m24 = (
		(mpout.m14*((Normal.y*Normal.x*oneminusc) + (sinB*Normal.z))) +
		(mpout.m24*((Normal.y*Normal.y*oneminusc) + cosB)) +
		(mpout.m34*((Normal.y*Normal.z*oneminusc) - (sinB*Normal.x)))
		);
	Temp.m31 = (
		(mpout.m11*((Normal.z*Normal.x*oneminusc) - (sinB*Normal.y))) +
		(mpout.m21*((Normal.z*Normal.y*oneminusc) + (sinB*Normal.x))) +
		(mpout.m31*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m32 = (
		(mpout.m12*((Normal.z*Normal.x*oneminusc) - (sinB*Normal.y))) +
		(mpout.m22*((Normal.z*Normal.y*oneminusc) + (sinB*Normal.x))) +
		(mpout.m32*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m33 = (
		(mpout.m13*((Normal.z*Normal.x*oneminusc) - (sinB*Normal.y))) +
		(mpout.m23*((Normal.z*Normal.y*oneminusc) + (sinB*Normal.x))) +
		(mpout.m33*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	Temp.m34 = (
		(mpout.m14*((Normal.z*Normal.x*oneminusc) - (sinB*Normal.y))) +
		(mpout.m24*((Normal.z*Normal.y*oneminusc) + (sinB*Normal.x))) +
		(mpout.m34*((Normal.z*Normal.z*oneminusc) + cosB))
		);
	mpout = Temp;
}

void XVecTransformLH(XVECTOR3& Transformed, const XVECTOR3& SrcVector, const XMATRIX44& SrcMatrix) {
	Transformed.x = (SrcMatrix.m11 * SrcVector.x) + (SrcMatrix.m12 * SrcVector.y) + (SrcMatrix.m13 * SrcVector.z) + (SrcMatrix.m14 * SrcVector.w);
	Transformed.y = (SrcMatrix.m21 * SrcVector.x) + (SrcMatrix.m22 * SrcVector.y) + (SrcMatrix.m23 * SrcVector.z) + (SrcMatrix.m24 * SrcVector.w);
	Transformed.z = (SrcMatrix.m31 * SrcVector.x) + (SrcMatrix.m32 * SrcVector.y) + (SrcMatrix.m33 * SrcVector.z) + (SrcMatrix.m34 * SrcVector.w);
	Transformed.w = (SrcMatrix.m41 * SrcVector.x) + (SrcMatrix.m42 * SrcVector.y) + (SrcMatrix.m43 * SrcVector.z) + (SrcMatrix.m44 * SrcVector.w);
}
void XVecTransformNormalLH(XVECTOR3& Normal, const XVECTOR3& SrcVector, const XMATRIX44& SrcMatrix) {
	Normal.x = (SrcMatrix.m11 * SrcVector.x) + (SrcMatrix.m12 * SrcVector.y) + (SrcMatrix.m13 * SrcVector.z);
	Normal.y = (SrcMatrix.m21 * SrcVector.x) + (SrcMatrix.m22 * SrcVector.y) + (SrcMatrix.m23 * SrcVector.z);
	Normal.z = (SrcMatrix.m31 * SrcVector.x) + (SrcMatrix.m32 * SrcVector.y) + (SrcMatrix.m33 * SrcVector.z);
}

void XVecTransformRH(XVECTOR3& Transformed, const XVECTOR3& SrcVector, const XMATRIX44& SrcMatrix) {
	Transformed.x = (SrcMatrix.m11 * SrcVector.x) + (SrcMatrix.m12 * SrcVector.y) + (SrcMatrix.m13 * SrcVector.z) + (SrcMatrix.m14 * SrcVector.w);
	Transformed.y = (SrcMatrix.m21 * SrcVector.x) + (SrcMatrix.m22 * SrcVector.y) + (SrcMatrix.m23 * SrcVector.z) + (SrcMatrix.m24 * SrcVector.w);
	Transformed.z = -((SrcMatrix.m31 * SrcVector.x) + (SrcMatrix.m32 * SrcVector.y) + (SrcMatrix.m33 * SrcVector.z) + (SrcMatrix.m34 * SrcVector.w));
	Transformed.w = (SrcMatrix.m41 * SrcVector.x) + (SrcMatrix.m42 * SrcVector.y) + (SrcMatrix.m43 * SrcVector.z) + (SrcMatrix.m44 * SrcVector.w);
}
void XVecTransformNormalRH(XVECTOR3& Normal, const XVECTOR3& SrcVector, const XMATRIX44& SrcMatrix) {
	Normal.x = (SrcMatrix.m11 * SrcVector.x) + (SrcMatrix.m12 * SrcVector.y) + (SrcMatrix.m13 * SrcVector.z);
	Normal.y = (SrcMatrix.m21 * SrcVector.x) + (SrcMatrix.m22 * SrcVector.y) + (SrcMatrix.m23 * SrcVector.z);
	Normal.z = -((SrcMatrix.m31 * SrcVector.x) + (SrcMatrix.m32 * SrcVector.y) + (SrcMatrix.m33 * SrcVector.z));
}

void XVecDot(float &vecDot, const XVECTOR3 &A, const XVECTOR3 &B) {
	vecDot = (A.x*B.x) + (A.y*B.y) + (A.z*B.z);
}
void XVecLength(float &vecLenght, const XVECTOR3 &A) {
	vecLenght = XVECTOR3(A).Length();
}
void XVecCross(XVECTOR3 &vecCross, const XVECTOR3 &A, const XVECTOR3 &B) {
	vecCross.x = (A.y*B.z) - (A.z*B.y);
	vecCross.y = -(A.x*B.z) + (A.z*B.x);
	vecCross.z = (A.x*B.y) - (A.y*B.x);
}
void XVec3Normalize(XVECTOR3 &vecNormal, const XVECTOR3 &A) {
	vecNormal = A;
	vecNormal.Normalize();
}

XVECTOR2& XVECTOR2::operator += (const XVECTOR2& other) {
	this->x = this->x + other.x;
	this->y = this->y + other.y;
	return *this;
}
XVECTOR2& XVECTOR2::operator -= (const XVECTOR2& other) {
	this->x = this->x - other.x;
	this->y = this->y - other.y;
	return *this;
}
XVECTOR2& XVECTOR2::operator *= (float times) {
	this->x = this->x * times;
	this->y = this->y * times;
	return *this;
}
XVECTOR2& XVECTOR2::operator /= (float times) {
	this->x = this->x / times;
	this->y = this->y / times;
	return *this;
}

XVECTOR2 XVECTOR2::operator + () const {
	return *this;
}
XVECTOR2 XVECTOR2::operator - () const {
	return XVECTOR2(-this->x, -this->y);
}

XVECTOR2 XVECTOR2::operator + (const XVECTOR2& other) const {
	return XVECTOR2(this->x + other.x, this->y + other.y);
}
XVECTOR2 XVECTOR2::operator - (const XVECTOR2& other) const {
	return XVECTOR2(this->x - other.x, this->y - other.y);
}
XVECTOR2 XVECTOR2::operator * (float times) const {
	return XVECTOR2(this->x * times, this->y * times);
}
XVECTOR2 XVECTOR2::operator / (float times) const {
	return XVECTOR2(this->x / times, this->y / times);
}

bool XVECTOR2::operator == (const XVECTOR2& other) const {
	return ((this->x == other.x) && (this->y == other.y));
}
bool XVECTOR2::operator != (const XVECTOR2& other) const {
	return !(*this == other);
}

void XVECTOR2::Normalize() {
	*this /= this->Length();
}
float XVECTOR2::Length() {
	return (sqrt(pow(this->x, 2) + pow(this->y, 2)));
}

XVECTOR3& XVECTOR3::operator += (const XVECTOR3& other) {
	this->x = this->x + other.x;
	this->y = this->y + other.y;
	this->z = this->z + other.z;
	return *this;
}
XVECTOR3& XVECTOR3::operator -= (const XVECTOR3& other) {
	this->x = this->x - other.x;
	this->y = this->y - other.y;
	this->z = this->z - other.z;
	return *this;
}
XVECTOR3& XVECTOR3::operator *= (float times) {
	this->x = this->x * times;
	this->y = this->y * times;
	this->z = this->z * times;
	return *this;
}
XVECTOR3& XVECTOR3::operator /= (float times) {
	this->x = this->x / times;
	this->y = this->y / times;
	this->z = this->z / times;
	return *this;
}

XVECTOR3 XVECTOR3::operator + () const {
	return *this;
}
XVECTOR3 XVECTOR3::operator - () const {
	return XVECTOR3(-this->x, -this->y, -this->z);
}

XVECTOR3 XVECTOR3::operator + (const XVECTOR3& other) const {
	return XVECTOR3(this->x + other.x, this->y + other.y, this->z + other.z);
}
XVECTOR3 XVECTOR3::operator - (const XVECTOR3& other) const {
	return XVECTOR3(this->x - other.x, this->y - other.y, this->z - other.z);
}
XVECTOR3 XVECTOR3::operator * (float times) const {
	return XVECTOR3(this->x * times, this->y * times, this->z * times);
}
XVECTOR3 XVECTOR3::operator / (float times) const {
	return XVECTOR3(this->x / times, this->y / times, this->z / times);
}

XVECTOR3 XVECTOR3::operator * (const XVECTOR3& other) {
	return other;
}

//friend XVECTOR3 XVECTOR3::operator * (float, const struct XVECTOR3&){
//
//}

bool XVECTOR3::operator == (const XVECTOR3& other) const {
	return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
}
bool XVECTOR3::operator != (const XVECTOR3& other) const {
	return !(*this == other);
}

void XVECTOR3::Normalize() {
	*this /= this->Length();
}
float XVECTOR3::Length() {
	return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));
}


XMATRIX44_64::XMATRIX44_64() {
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}
XMATRIX44_64::XMATRIX44_64(XMATRIX44* i) {
	m11 = i->m11; m12 = i->m12; m13 = i->m13; m14 = i->m14;
	m21 = i->m21; m22 = i->m22; m23 = i->m23; m24 = i->m24;
	m31 = i->m31; m32 = i->m32; m33 = i->m33; m34 = i->m34;
	m41 = i->m41; m42 = i->m42; m43 = i->m43; m44 = i->m44;
}

XMATRIX44& XMATRIX44::operator *= (const XMATRIX44& other) {
	XMATRIX44 pivot = *this;
	this->m11 = (pivot.m11*other.m11) + (pivot.m12*other.m21) + (pivot.m13*other.m31) + (pivot.m14*other.m41);
	this->m12 = (pivot.m11*other.m12) + (pivot.m12*other.m22) + (pivot.m13*other.m32) + (pivot.m14*other.m42);
	this->m13 = (pivot.m11*other.m13) + (pivot.m12*other.m23) + (pivot.m13*other.m33) + (pivot.m14*other.m43);
	this->m14 = (pivot.m11*other.m14) + (pivot.m12*other.m24) + (pivot.m13*other.m34) + (pivot.m14*other.m44);

	this->m21 = (pivot.m21*other.m11) + (pivot.m22*other.m21) + (pivot.m23*other.m31) + (pivot.m24*other.m41);
	this->m22 = (pivot.m21*other.m12) + (pivot.m22*other.m22) + (pivot.m23*other.m32) + (pivot.m24*other.m42);
	this->m23 = (pivot.m21*other.m13) + (pivot.m22*other.m23) + (pivot.m23*other.m33) + (pivot.m24*other.m43);
	this->m24 = (pivot.m21*other.m14) + (pivot.m22*other.m24) + (pivot.m23*other.m34) + (pivot.m24*other.m44);

	this->m31 = (pivot.m31*other.m11) + (pivot.m32*other.m21) + (pivot.m33*other.m31) + (pivot.m34*other.m41);
	this->m32 = (pivot.m31*other.m12) + (pivot.m32*other.m22) + (pivot.m33*other.m32) + (pivot.m34*other.m42);
	this->m33 = (pivot.m31*other.m13) + (pivot.m32*other.m23) + (pivot.m33*other.m33) + (pivot.m34*other.m43);
	this->m34 = (pivot.m31*other.m14) + (pivot.m32*other.m24) + (pivot.m33*other.m34) + (pivot.m34*other.m44);

	this->m41 = (pivot.m41*other.m11) + (pivot.m42*other.m21) + (pivot.m43*other.m31) + (pivot.m44*other.m41);
	this->m42 = (pivot.m41*other.m12) + (pivot.m42*other.m22) + (pivot.m43*other.m32) + (pivot.m44*other.m42);
	this->m43 = (pivot.m41*other.m13) + (pivot.m42*other.m23) + (pivot.m43*other.m33) + (pivot.m44*other.m43);
	this->m44 = (pivot.m41*other.m14) + (pivot.m42*other.m24) + (pivot.m43*other.m34) + (pivot.m44*other.m44);
	return *this;
}
XMATRIX44& XMATRIX44::operator += (const XMATRIX44& other) {
	this->m11 += other.m11;
	this->m12 += other.m12;
	this->m13 += other.m13;
	this->m14 += other.m14;

	this->m21 += other.m21;
	this->m22 += other.m22;
	this->m23 += other.m23;
	this->m24 += other.m24;

	this->m31 += other.m31;
	this->m32 += other.m32;
	this->m33 += other.m33;
	this->m34 += other.m34;

	this->m41 += other.m41;
	this->m42 += other.m42;
	this->m43 += other.m43;
	this->m44 += other.m44;
	return *this;
}
XMATRIX44& XMATRIX44::operator -= (const XMATRIX44& other) {
	this->m11 -= other.m11;
	this->m12 -= other.m12;
	this->m13 -= other.m13;
	this->m14 -= other.m14;

	this->m21 -= other.m21;
	this->m22 -= other.m22;
	this->m23 -= other.m23;
	this->m24 -= other.m24;

	this->m31 -= other.m31;
	this->m32 -= other.m32;
	this->m33 -= other.m33;
	this->m34 -= other.m34;

	this->m41 -= other.m41;
	this->m42 -= other.m42;
	this->m43 -= other.m43;
	this->m44 -= other.m44;
	return *this;
}
XMATRIX44& XMATRIX44::operator *= (float times) {
	this->m11 *= times;
	this->m12 *= times;
	this->m13 *= times;
	this->m14 *= times;

	this->m21 *= times;
	this->m22 *= times;
	this->m23 *= times;
	this->m24 *= times;

	this->m31 *= times;
	this->m32 *= times;
	this->m33 *= times;
	this->m34 *= times;

	this->m41 *= times;
	this->m42 *= times;
	this->m43 *= times;
	this->m44 *= times;
	return *this;
}
XMATRIX44& XMATRIX44::operator /= (float times) {
	this->m11 /= times;
	this->m12 /= times;
	this->m13 /= times;
	this->m14 /= times;

	this->m21 /= times;
	this->m22 /= times;
	this->m23 /= times;
	this->m24 /= times;

	this->m31 /= times;
	this->m32 /= times;
	this->m33 /= times;
	this->m34 /= times;

	this->m41 /= times;
	this->m42 /= times;
	this->m43 /= times;
	this->m44 /= times;
	return *this;
}

XMATRIX44 XMATRIX44::operator + () const {
	return *this;
}
XMATRIX44 XMATRIX44::operator - () const {
	return XMATRIX44(-this->m11, -this->m12, -this->m13, -this->m14,
		-this->m21, -this->m22, -this->m23, -this->m24,
		-this->m31, -this->m32, -this->m33, -this->m34,
		-this->m41, -this->m42, -this->m43, -this->m44);
}

//XMATRIX44::operator float*(){
//
//}
//XMATRIX44::operator const float* () const{
//
//}

XMATRIX44 XMATRIX44::operator * (const XMATRIX44& other) const {
	return XMATRIX44((this->m11*other.m11) + (this->m12*other.m21) + (this->m13*other.m31) + (this->m14*other.m41),
		(this->m11*other.m12) + (this->m12*other.m22) + (this->m13*other.m32) + (this->m14*other.m42),
		(this->m11*other.m13) + (this->m12*other.m23) + (this->m13*other.m33) + (this->m14*other.m43),
		(this->m11*other.m14) + (this->m12*other.m24) + (this->m13*other.m34) + (this->m14*other.m44),
		(this->m21*other.m11) + (this->m22*other.m21) + (this->m23*other.m31) + (this->m24*other.m41),
		(this->m21*other.m12) + (this->m22*other.m22) + (this->m23*other.m32) + (this->m24*other.m42),
		(this->m21*other.m13) + (this->m22*other.m23) + (this->m23*other.m33) + (this->m24*other.m43),
		(this->m21*other.m14) + (this->m22*other.m24) + (this->m23*other.m34) + (this->m24*other.m44),
		(this->m31*other.m11) + (this->m32*other.m21) + (this->m33*other.m31) + (this->m34*other.m41),
		(this->m31*other.m12) + (this->m32*other.m22) + (this->m33*other.m32) + (this->m34*other.m42),
		(this->m31*other.m13) + (this->m32*other.m23) + (this->m33*other.m33) + (this->m34*other.m43),
		(this->m31*other.m14) + (this->m32*other.m24) + (this->m33*other.m34) + (this->m34*other.m44),
		(this->m41*other.m11) + (this->m42*other.m21) + (this->m43*other.m31) + (this->m44*other.m41),
		(this->m41*other.m12) + (this->m42*other.m22) + (this->m43*other.m32) + (this->m44*other.m42),
		(this->m41*other.m13) + (this->m42*other.m23) + (this->m43*other.m33) + (this->m44*other.m43),
		(this->m41*other.m14) + (this->m42*other.m24) + (this->m43*other.m34) + (this->m44*other.m44));
}
XMATRIX44 XMATRIX44::operator + (const XMATRIX44& other) const {
	return XMATRIX44(this->m11 + other.m11, this->m12 + other.m12, this->m13 + other.m13, this->m14 + other.m14,
		this->m21 + other.m21, this->m22 + other.m22, this->m23 + other.m23, this->m24 + other.m24,
		this->m31 + other.m31, this->m32 + other.m32, this->m33 + other.m33, this->m34 + other.m34,
		this->m41 + other.m41, this->m42 + other.m42, this->m43 + other.m43, this->m44 + other.m44);
}
XMATRIX44 XMATRIX44::operator - (const XMATRIX44& other) const {
	return XMATRIX44(this->m11 + other.m11, this->m12 + other.m12, this->m13 + other.m13, this->m14 + other.m14,
		this->m21 + other.m21, this->m22 + other.m22, this->m23 + other.m23, this->m24 + other.m24,
		this->m31 + other.m31, this->m32 + other.m32, this->m33 + other.m33, this->m34 + other.m34,
		this->m41 + other.m41, this->m42 + other.m42, this->m43 + other.m43, this->m44 + other.m44);
}
XMATRIX44 XMATRIX44::operator * (float times) const {
	return XMATRIX44(this->m11 * times, this->m12 * times, this->m13 * times, this->m14 * times,
		this->m21 * times, this->m22 * times, this->m23 * times, this->m24 * times,
		this->m31 * times, this->m32 * times, this->m33 * times, this->m34 * times,
		this->m41 * times, this->m42 * times, this->m43 * times, this->m44 * times);
}
XMATRIX44 XMATRIX44::operator / (float times) const {
	return XMATRIX44(this->m11 / times, this->m12 / times, this->m13 / times, this->m14 / times,
		this->m21 / times, this->m22 / times, this->m23 / times, this->m24 / times,
		this->m31 / times, this->m32 / times, this->m33 / times, this->m34 / times,
		this->m41 / times, this->m42 / times, this->m43 / times, this->m44 / times);
}

//friend XMATRIX44 XMATRIX44::operator * (float, const XMATRIX44&){}

bool XMATRIX44::operator == (const XMATRIX44& other) const {
	return ((this->m11 == other.m11) && (this->m12 == other.m12) && (this->m13 == other.m13) && (this->m14 == other.m14) &&
		(this->m21 == other.m21) && (this->m22 == other.m22) && (this->m23 == other.m23) && (this->m24 == other.m24) &&
		(this->m31 == other.m31) && (this->m32 == other.m32) && (this->m33 == other.m33) && (this->m34 == other.m34) &&
		(this->m41 == other.m41) && (this->m42 == other.m42) && (this->m43 == other.m43) && (this->m44 == other.m44));
}
bool XMATRIX44::operator != (const XMATRIX44& other) const {
	return (!(*this == other));
}