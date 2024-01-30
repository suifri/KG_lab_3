#pragma once
#include <GL\glut.h>

class Octahedron
{
private:
	GLfloat angle;
	GLboolean shadeFlag;

public:
	Octahedron();
	void display() const;
	void reshape(const int width, const int height) const;
	void timerIncrementation();
	void setShadeMode(const GLboolean shadeFlag = true) noexcept;
};

