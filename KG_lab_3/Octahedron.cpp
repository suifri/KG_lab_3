#include "Octahedron.h"

Octahedron::Octahedron()
	:angle(0.0), shadeFlag(true)
{
}

void Octahedron::display() const
{
	glPushMatrix();

    glTranslatef(0.0f, 0.0f, -5.0f); 

    glRotatef(angle, 1.0f, 1.0f, 1.0f); 

    this->shadeFlag == true ? glShadeModel(GL_SMOOTH) : glShadeModel(GL_FLAT);

    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidOctahedron();

	glPopMatrix();
}

void Octahedron::reshape(const int width, const int height) const
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<GLfloat>(width) / static_cast<GLfloat>(height), 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Octahedron::timerIncrementation()
{
    this->angle += 2.0f;
}

void Octahedron::setShadeMode(const GLboolean shadeFlag) noexcept
{
    this->shadeFlag = shadeFlag;
}
