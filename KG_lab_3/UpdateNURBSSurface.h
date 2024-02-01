#pragma once
#include <GL/glut.h>
#include <iostream>
class UpdateNURBSSurface
{
private:
	GLfloat controlPoints[4][4][3];
	GLUnurbsObj* nurbs;
public:
	UpdateNURBSSurface();
	~UpdateNURBSSurface();

	void init();
	void init_surface();
	void nurbsError(GLenum errorCode);
	void reshape(int width, int height);
	void display();
};