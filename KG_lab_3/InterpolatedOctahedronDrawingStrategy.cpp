#include "InterpolatedOctahedronDrawingStrategy.h"

void InterpolatedOctahedronDrawingStrategy::drawOctahedron()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // �������� ����
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    // ����� �����
    glColor3f(0.0f, 1.0f, 0.0f); // ������� ����
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // ����� �����
    glColor3f(0.0f, 0.0f, 1.0f); // ���� ����
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    // �������� �����
    glColor3f(1.0f, 0.0f, 0.0f); // �������� ����
    glVertex3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);

    // �'��� �����
    glColor3f(0.0f, 1.0f, 0.0f); // ������� ����
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    // ����� �����
    glColor3f(0.0f, 0.0f, 1.0f); // ���� ����
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // ����� �����
    glColor3f(1.0f, 0.0f, 0.0f); // �������� ����
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    // ������ �����
    glColor3f(0.0f, 1.0f, 0.0f); // ������� ����
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
}
