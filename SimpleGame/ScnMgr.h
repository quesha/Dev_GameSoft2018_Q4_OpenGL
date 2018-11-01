#pragma once
#include "Renderer.h"
#include "Object.h"
class ScnMgr
{
public:
	ScnMgr();
	~ScnMgr();

	void Renderscene();
	void Update(float eTime);
	void ApplyForce(float x, float y, float eTime);

private:
	Renderer * m_Renderer;
	Object* m_TestObj;

	GLuint m_texIssac;
	GLuint m_texshadow;
};

