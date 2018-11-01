#pragma once
class Object
{
public:
	Object();
	~Object();

	void Update(float eTime);
	void ApplyForce(float x, float y, float eTime);

	void GetPosition(float* x, float* y,float *z);
	void SetPosition(float x, float y,float z);
	void GetSize(float* w, float* h);
	void SetSize(float w, float h);
	void GetMass(float* mass);
	void SetMass(float mass);
	void GetColor(float* r, float* g, float* b, float* a);
	void SetColor(float r, float g, float b, float a);
	void SetVel(float x, float y);
	void GetVel(float* x, float* y);
	void SetAcc(float x, float y);
	void GetAcc(float* x, float* y);
	void SetFrictionCoef(float x);
	void GetFrictionCoef(float* x);

private:
	float m_posX, m_posY, m_posZ;
	float m_width, m_height;
	float m_r, m_g, m_b, m_a;
	float m_velX, m_velY;
	float m_accX, m_accY;
	float m_mass;
	float m_frictionCoef;
};

