#pragma once
#include <GL/glut.h>
#include <vector>

class NURBSSurface
{
private:
	GLfloat points[4][4][3] = {
 {{-1.5, 1.0, -1.5}, {-0.5, 1.0,-1.5 }, {0.5, 1.0, -1.5 }, {1.5, 1.0,-1.5}},
 {{-1.5, 1.0, -0.5}, {-0.5, 2.0,-0.5 }, {0.5, 2.0, -0.5 }, {1.5, 1.0,-0.5}},
 {{-1.5, 1.0,  0.5}, {-0.5, 2.0, 0.5 }, {0.5, 2.0,  0.5 }, {1.5, 1.0, 0.5}},
 {{-1.5, 1.0,  1.5}, {-0.5, 1.0, 1.5 }, {0.5, 1.0,  1.5 }, {1.5, 1.0, 1.5}}
	};
public:
	NURBSSurface();
	void display();
	void init();
	void reshape(int width, int height);
};

