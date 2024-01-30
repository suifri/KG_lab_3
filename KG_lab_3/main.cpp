#include <GL/glut.h>
#include "Octahedron.h"

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

Octahedron* octa = new Octahedron();

void init() 
{
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0); 
    //glEnable(GL_COLOR_MATERIAL);

    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    GLfloat light_color[] = { 0.56f, 0.35f, 0.32f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    
    octa->display();

    glutSwapBuffers();

}

void reshape(int width, int height) 
{
    octa->reshape(width, height);
}

void timer(int value) {
    octa->timerIncrementation();
    glutPostRedisplay(); 
    glutTimerFunc(16, timer, 0); 
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lit Octahedron");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    octa->setShadeMode(false);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    delete octa;
    octa = nullptr;

    return 0;
}
