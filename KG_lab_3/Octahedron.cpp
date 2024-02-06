#include "Octahedron.h"

void Octahedron::lightMovement() const
{
    glPushMatrix();
    glRotatef(this->angle + 0.45, 0, 1, 0);
    GLfloat position[] = { 0, 0, 1, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glPopMatrix();
}

Octahedron::Octahedron()
    :angle(0.0), angle_(60), drawingStrategy(new SolidPolygonDrawingStrategy())
{}

Octahedron::~Octahedron()
{
    delete this->drawingStrategy;
    this->drawingStrategy = nullptr;
}

void Octahedron::display() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	glPushMatrix();

    glTranslatef(0.0f, 0.0f, -5.0f); 

    glRotatef(angle, 1.0f, 1.0f, 1.0f); 

    this->lightMovement();

    this->drawingStrategy->drawOctahedron();

	glPopMatrix();

    glutSwapBuffers();
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


void Octahedron::setOctahedronDrawingStrategy(const OCTAHEDRON_TYPE octaShape) noexcept
{
    this->drawingStrategy = StrategyChooser::chooseStrategy(octaShape);
}

void Octahedron::init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    GLfloat light_color[] = { 0.56f, 0.35f, 0.32f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
