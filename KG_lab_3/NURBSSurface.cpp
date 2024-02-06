#include "NURBSSurface.h"

NURBSSurface::NURBSSurface()
{

}

void NURBSSurface::display()
{
	int i{ 0 };
	int j{ 0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.5, 0.6);
	glPushMatrix();

	glRotatef(25.0, 1.0, 1.0, 1.0);

	for (j = 0; j <= 8; j++)
	{
		glBegin(GL_LINE_STRIP);

		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);

		glEnd();

		glBegin(GL_LINE_STRIP);

		for (i = 0; i <= 30; i++)
			glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);

		glEnd();
	}

	glPopMatrix();
	glFlush();
}

void NURBSSurface::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, **this->points);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0f, 1.0f, 20, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);

}

void NURBSSurface::reshape(int width, int height)
{
	glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
		glOrtho(-5.0, 5.0, -5.0 * static_cast<GLfloat>(height) / static_cast<GLfloat>(width), 5.0 * static_cast<GLfloat>(height) / static_cast<GLfloat>(width), -5.0, 5.0);
	else
		glOrtho(-5.0 * static_cast<GLfloat>(width) / static_cast<GLfloat>(height), 5.0 * static_cast<GLfloat>(width) / static_cast<GLfloat>(height), -5.0, 5.0, -5.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
