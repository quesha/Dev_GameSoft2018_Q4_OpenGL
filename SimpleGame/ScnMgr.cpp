#include "stdafx.h"
#include "ScnMgr.h"
#include "Renderer.h"

ScnMgr::ScnMgr()
{
	m_TestObj = new Object();
	m_TestObj->SetPosition(0.f, 0.f,10.f);
	m_TestObj->SetSize(1.f, 1.f);
	m_TestObj->SetColor(1.f, 1.f, 1.f, 1.f);
	m_TestObj->SetVel(0.f, 0.f);
	m_TestObj->SetAcc(0.f, 0.f);
	m_TestObj->SetMass(0.15f);
	m_TestObj->SetFrictionCoef(0.2f);

	m_Renderer = new Renderer(500, 500);

	m_texIssac = m_Renderer->CreatePngTexture("Issac.png");
	m_texshadow = m_Renderer->CreatePngTexture("Shadow.png");
}


ScnMgr::~ScnMgr()
{
	m_Renderer->DeleteTexture(m_texIssac);
	delete m_Renderer;
	delete m_TestObj;
}

float temp = 0.f;
void ScnMgr::Update(float eTime)
{
	m_TestObj->Update(eTime);
}
void ScnMgr::Renderscene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.f, 1.f, 1.f, 1.0f);

	// Renderer Test
	float x, y,z;
	m_TestObj->GetPosition(&x, &y,&z);
	float width, height;
	m_TestObj->GetSize(&width, &height);
	float r, g, b, a;
	m_TestObj->GetColor(&r, &g, &b, &a);

	float newX, newY,newZ, newW, newH;
	newX = x * 100;
	newY = y * 100;
	newZ = z * 100;
	newW = width * 100;
	newH = height * 100;
	
	//int textureID = m_Renderer->CreatePngTexture("Issac.png");

	m_Renderer->DrawTextureRect(newX, newY, 0, newW, newH, r, g, b, a, m_texIssac);
	m_Renderer->DrawTextureRectHeight(newX, newY, 0, newW, newH, r, g, b, a, m_texshadow, newZ);
	//m_Renderer->DrawSolidRect(newX, newY, 0, newW, newH, r, g, b, a);
}

void ScnMgr::ApplyForce(float x, float y, float eTime)
{
	m_TestObj->ApplyForce(x, y, eTime);
}