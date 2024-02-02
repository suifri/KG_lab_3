#pragma once
#include <GL/glut.h>
#include <iostream>

class RealNURBS
{
private:
	GLfloat controlPoints[4][4][4] = {
 {{-1.5, 1.0, -1.5, 1.0}, {-0.5, 1.0,-1.5, 1.0 }, {0.5, 1.0, -1.5, 1.0 }, {1.5, 1.0,-1.5, 1.0}},
 {{-1.5, 2.0, -0.5, 1.0}, {-0.5, 1.5,-0.5, 1.0 }, {0.5, 1.0, -0.5, 1.0 }, {1.5, 3.0,-0.5, 1.0}},
 {{-1.5, 2.0,  0.5, 1.0}, {-0.5, 1.0, 0.5, 1.0 }, {0.5, 1.0,  0.5, 1.0 }, {1.5, 3.0, 0.5, 1.0}},
 {{-1.5, 1.0,  1.5, 1.0}, {-0.5, 1.0, 1.5, 1.0 }, {0.5, 1.0,  1.5, 1.0 }, {1.5, 1.0, 1.5, 1.0}}
	};
	GLUnurbsObj* nurbs;
public:
	RealNURBS();
	~RealNURBS();

	void init();
	void init_surface();
	void nurbsError(GLenum errorCode);
	void reshape(int width, int height);
	void display();
};

