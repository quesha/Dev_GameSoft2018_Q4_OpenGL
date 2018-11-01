/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "ScnMgr.h"

ScnMgr *g_ScnMgr = NULL;

DWORD g_PrevTime = 0;

bool g_keyW = false;
bool g_keyA = false;
bool g_keyS = false;
bool g_keyD = false;

void RenderScene(void)
{
	if (g_PrevTime == 0) {
		g_PrevTime = timeGetTime();
	}
	DWORD currTime = timeGetTime();
	DWORD elapsedTime = currTime - g_PrevTime;
	g_PrevTime = currTime;
	float eTime = (float)elapsedTime / 1000.f;

	//std::cout << "elapsedTime: " << eTime << std::endl;

	std::cout << "W: " << g_keyW << " "
		<< "A: " << g_keyA << " "
		<< "S: " << g_keyS << " "
		<< "D: " << g_keyD << " " << std::endl;

	float fX = 0.f, fY = 0.f;
	float amount = 1.f;
	if (g_keyW){
		fY += amount;
	}
	if (g_keyS) {
		fY -= amount;
	}
	if (g_keyD) {
		fX += amount;
	}
	if (g_keyA) {
		fX -= amount;
	}
	//Normalize(&fX, &fY);
	g_ScnMgr->ApplyForce(fX, fY, eTime);
	g_ScnMgr->Update(eTime);
	g_ScnMgr->Renderscene();
	
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyDownInput(unsigned char key, int x, int y)
{
	if (key == 'w') {
		g_keyW = true;
	}
	else if (key == 's') {
		g_keyS = true;
	}
	else if (key == 'd') {
		g_keyD = true;
	}
	else if (key == 'a') {
		g_keyA = true;
	}
	
}

void KeyUpInput(unsigned char key, int x, int y)
{
	if (key == 'w') {
		g_keyW = false;
	}
	else if (key == 's') {
		g_keyS = false;
	}
	else if (key == 'd') {
		g_keyD = false;
	}
	else if (key == 'a') {
		g_keyA = false;
	}
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}


	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	g_ScnMgr = new ScnMgr;

	glutMainLoop();

    return 0;
}

