#include "StdAfx.h"
#include "MathUtil.h"

using namespace PhysX;

Matrix MathUtil::PxTransformToMatrix(PxTransform* transform)
{
	Quaternion q = Quaternion(transform->q.x, transform->q.y, transform->q.z, transform->q.w);
	Matrix m = 
		Matrix::CreateFromQuaternion(q) *
		Matrix::CreateTranslation(transform->p.x, transform->p.y, transform->p.z);
	
	return m;
}
PxTransform MathUtil::MatrixToPxTransform(Matrix matrix)
{
	Quaternion q = Quaternion::CreateFromRotationMatrix(matrix);

	PxTransform t;
		t.p = PxVec3(matrix.M41, matrix.M42, matrix.M43);
		t.q = PxQuat(q.X, q.Y, q.Z, q.W);

	return t;
}

Matrix MathUtil::PxMat33ToMatrix(PxMat33* matrix)
{
	Matrix m = Matrix::Identity;

	m.M11 = matrix->column0.x;
	m.M21 = matrix->column0.y;
	m.M31 = matrix->column0.z;
	
	m.M12 = matrix->column1.x;
	m.M22 = matrix->column1.y;
	m.M32 = matrix->column1.z;
			
	m.M13 = matrix->column2.x;
	m.M23 = matrix->column2.y;
	m.M33 = matrix->column2.z;

	return m;
}
PxMat33 MathUtil::MatrixToPxMat33(Matrix matrix)
{
	float values[9];
		values[0] = matrix.M11;
		values[1] = matrix.M21;
		values[2] = matrix.M31;

		values[3] = matrix.M12;
		values[4] = matrix.M22;
		values[5] = matrix.M32;

		values[6] = matrix.M13;
		values[7] = matrix.M23;
		values[8] = matrix.M33;

	PxMat33 m(values);

	return m;
}

Matrix MathUtil::PxMat44ToMatrix(PxMat44* mat44)
{
	Matrix m;

	pin_ptr<Matrix> m_pin = &m;

	memcpy(m_pin, mat44, sizeof(PxMat44));

	return m;
}
PxMat44 MathUtil::MatrixToPxMat44(Matrix matrix)
{
	pin_ptr<Matrix> m_pin = &matrix;

	PxMat44 mat44;

	memcpy(&mat44, m_pin, sizeof(PxMat44));

	return mat44;
}

Vector3 MathUtil::PxVec3ToVector3(PxVec3 vector)
{
	return Vector3(vector.x, vector.y, vector.z);
}
PxVec3 MathUtil::Vector3ToPxVec3(Vector3 vector)
{
	return PxVec3(vector.X, vector.Y, vector.Z);
}

Vector3 MathUtil::PxExtendedVec3ToVector3(PxExtendedVec3 vector)
{
	return Vector3((float)vector.x, (float)vector.y, (float)vector.z);
}
PxExtendedVec3 MathUtil::Vector3ToPxExtendedVec3(Vector3 vector)
{
	return PxExtendedVec3(vector.X, vector.Y, vector.Z);
}

Vector2 MathUtil::PxVec2ToVector2(PxVec2 vector)
{
	return Vector2(vector.x, vector.y);
}
PxVec2 MathUtil::Vector2ToPxVec2(Vector2 vector)
{
	return PxVec2(vector.X, vector.Y);
}

Quaternion MathUtil::PxQuatToQuaternion(PxQuat quat)
{
	return Quaternion(quat.x, quat.y, quat.z, quat.w);
}
PxQuat MathUtil::QuaternionToPxQuat(Quaternion quat)
{
	return PxQuat(quat.X, quat.Y, quat.Z, quat.W);
}

bool MathUtil::IsMultipleOf(int num, int divisor)
{
	return (num % divisor) == 0;
}