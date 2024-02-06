#pragma once
#include <GL/glut.h>
#include <iostream>

class RealNURBS
{
private:
	GLfloat controlPoints[4][4][4];
	GLUnurbsObj* nurbs;
public:
	RealNURBS();
	~RealNURBS();

	void init();
	void init_surface();
	void nurbsError(GLenum errorCode);
	void reshape(int width, int height);
	void display();
	void setTextureType(const GLboolean textureType = false);
};

