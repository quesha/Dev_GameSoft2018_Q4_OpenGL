#include "stdafx.h"
#include "Object.h"
#include <math.h>
#include <float.h>

Object::Object()
{
}

void Object::Update(float eTime)
{
	float velocity = sqrtf(m_velX*m_velX + m_velY * m_velY);// size of velocity
	if (velocity < FLT_EPSILON) {

	}
	else {
		// gravity force
		float gZ;
		gZ = 9.8 * m_mass; // 수직항력
		float friction;
		friction = m_frictionCoef * gZ;
		
		// friction
		float fX, fY;
		fX = -friction * m_velX / velocity;
		fY = -friction * m_velY / velocity;

		// Calc acc
		float accX, accY;
		accX = fX / m_mass;
		accY = fY / m_mass;

		float aftervelX = m_velX + eTime * accX;
		float aftervelY = m_velY + eTime * accY;

		if (aftervelX*m_velX < 0.f) {
			m_velX = 0.f;
		}
		else {
			m_velX = m_velX + eTime * accX;
		}
		if (aftervelY*m_velY < 0.f) {
			m_velY = 0.f;
		}
		else {
			m_velY = m_velY + eTime * accY;
		}

		m_velX = m_velX + eTime * accX;
		m_velY = m_velY + eTime * accY;
	}
	// Calc velocity
	m_velX = m_velX + eTime * m_accX;
	m_velY = m_velY + eTime * m_accY;

	// Calc position
	m_posX = m_posX + eTime * m_velX;
	m_posY = m_posY + eTime * m_velY;
}
Object::~Object()
{
}

void Object::GetPosition(float* x, float* y,float *z)
{
	*x = m_posX;
	*y = m_posY;
	*z = m_posZ;
}

void Object::SetPosition(float x, float y,float z)
{
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}

void Object::GetSize(float* w, float* h)
{
	*w = m_width;
	*h = m_height;
}

void Object::SetSize(float w, float h)
{
	m_width = w;
	m_height = h;
}

void Object::GetColor(float* r, float* g, float* b, float* a)
{
	*r = m_r;
	*g = m_g;
	*b = m_b;
	*a = m_a;
}

void Object::SetColor(float r, float g, float b, float a)
{
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void Object::GetVel(float* x, float* y)
{
	*x = m_velX;
	*y = m_velY;
}

void Object::SetVel(float x, float y)
{
	m_velX = x;
	m_velY = y;
}

void Object::GetAcc(float* x, float* y)
{
	*x = m_accX;
	*y = m_accY;
}

void Object::SetAcc(float x, float y)
{
	m_accX = x;
	m_accY = y;
}

void Object::GetMass(float* mass)
{
	*mass = m_mass;
}
void Object::SetMass(float mass)
{
	m_mass = mass;
}

void Object::ApplyForce(float x, float y, float eTime)
{
	// Calc acc
	m_accX = x / m_mass;
	m_accY = y / m_mass;

	m_velX = m_velX + m_accX * eTime;
	m_velY = m_velY + m_accY * eTime;

	m_accX = 0;
	m_accY = 0;
}

void Object::SetFrictionCoef(float x)
{
	m_frictionCoef = x;
}

void Object::GetFrictionCoef(float* x)
{
	*x = m_frictionCoef;
}