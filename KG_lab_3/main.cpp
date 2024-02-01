#include <GL/glut.h>
#include "Octahedron.h"
#include "NURBSSurface.h"

const GLint WIDTH = 500;
const GLint HEIGHT = 500;

Octahedron* octa = new Octahedron();
NURBSSurface* nurbsSurf = new NURBSSurface();

void init() 
{
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0); 

    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    GLfloat light_color[] = { 0.56f, 0.35f, 0.32f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

    nurbsSurf->init();

}

void display() 
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glLoadIdentity();
    //
    //octa->display();

    //glutSwapBuffers();

    nurbsSurf->display();
}

void reshape(int width, int height) 
{
    octa->reshape(width, height);
    nurbsSurf->reshape(width, height);
}

//void timer(int value) {
//    octa->timerIncrementation();
//    glutPostRedisplay(); 
//    glutTimerFunc(16, timer, 0); 
//}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lit Octahedron");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutTimerFunc(0, timer, 0);
    glutMainLoop();

    delete octa;
    octa = nullptr;

    return 0;
}
