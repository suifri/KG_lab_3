#include "Octahedron.h"

Octahedron::Octahedron()
	:angle(0.0), shadeFlag(true), octaShape(true)
{
}

void Octahedron::display() const
{
	glPushMatrix();

    glTranslatef(0.0f, 0.0f, -5.0f); 

    glRotatef(angle, 1.0f, 1.0f, 1.0f); 

   // glEnable(GL_COLOR_MATERIAL);

    this->shadeFlag == true ? glShadeModel(GL_SMOOTH) : glShadeModel(GL_FLAT);
    glColor3f(0.0f, 0.5f, 0.0f);
    //this->octaShape == true ? glutSolidOctahedron() : glutWireOctahedron();

    //glDisable(GL_COLOR_MATERIAL);
    
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    // Друга грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // Третя грань
    glColor3f(0.0f, 0.0f, 1.0f); // Синій колір
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    // Четверта грань
    glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);

    // П'ята грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    // Шоста грань
    glColor3f(0.0f, 0.0f, 1.0f); // Синій колір
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // Сьома грань
    glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    // Восьма грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glEnd();
    glDisable(GL_COLOR_MATERIAL);

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

void Octahedron::setOctahedronShape(const GLboolean octaShape) noexcept
{
    this->octaShape = octaShape;
}
