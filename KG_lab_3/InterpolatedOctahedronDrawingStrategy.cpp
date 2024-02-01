#include "InterpolatedOctahedronDrawingStrategy.h"

void InterpolatedOctahedronDrawingStrategy::drawOctahedron()
{
    glShadeModel(GL_SMOOTH);

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
}
