#pragma once
#include <GL/glut.h>
#include <iostream>
class UpdateNURBSSurface
{
protected:
	GLfloat controlPoints[4][4][3];
	GLUnurbsObj* nurbs;
public:
	UpdateNURBSSurface();
	virtual ~UpdateNURBSSurface();

	void init();
	void init_surface();
	void nurbsError(GLenum errorCode);
	void reshape(int width, int height);
	void display();
	void setTextureType(GLUnurbsObj* nurbs);
};