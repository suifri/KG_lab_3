#pragma once
#include <GL/glut.h>

class IOctahedronDrawingStrategy
{
public:
	virtual ~IOctahedronDrawingStrategy() = default;
	virtual void drawOctahedron() = 0;
};

