#include "RealNURBS.h"

RealNURBS::RealNURBS()
	:nurbs(nullptr)
{}

RealNURBS::~RealNURBS()
{
	delete nurbs;
	nurbs = nullptr;
}

void RealNURBS::init()
{
	GLfloat matDiffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat matShininess[] = { 100.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	init_surface();

	this->nurbs = gluNewNurbsRenderer();
	gluNurbsProperty(this->nurbs, GLU_SAMPLING_TOLERANCE, 25.0);
	gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON);
}

void RealNURBS::setTextureType(GLboolean textureType)
{
	textureType == false ? gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON) : gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_FILL);
}

void RealNURBS::init_surface()
{
	GLint u{ 0 };
	GLint v{ 0 };

	for (u = 0; u < 4; ++u)
	{
		for (v = 0; v < 4; ++v)
		{
			**(*(this->controlPoints + u) + v) = 2.0 * (static_cast<GLfloat>(u) - 1.5);
			*(*(*(this->controlPoints + u) + v) + 1) = 2.0 * (static_cast<GLfloat>(v) - 1.5);

			if ((u == 1 || u == 2) && (v == 1 || v == 2))
				*(*(*(this->controlPoints + u) + v) + 2) = 1.5;
			else
				*(*(*(this->controlPoints + u) + v) + 2) = -1.0;

			*(*(*(this->controlPoints + u) + v) + 3) = 1.0;
		}
	}
}

void RealNURBS::reshape(int width, int height)
{
	glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, static_cast<GLdouble>(width) / static_cast<GLdouble>(height), 3.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void RealNURBS::display()
{
	GLfloat knots[]{ 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

	GLint i{ 0 };
	GLint j{ 0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(330.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);

	gluBeginSurface(this->nurbs);
	gluNurbsSurface(this->nurbs, 8, knots, 8, knots, 4 * 4, 4, **this->controlPoints, 4, 4, GL_MAP2_VERTEX_4);
	gluEndSurface(this->nurbs);

	glPopMatrix();
	glFlush();
}