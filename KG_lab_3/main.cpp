#include <GL/glut.h>
#include "Octahedron.h"
#include "NURBSSurface.h"
#include "UpdateNURBSSurface.h"

const GLint WIDTH = 500;
const GLint HEIGHT = 500;

Octahedron* octa = new Octahedron();
NURBSSurface* nurbsSurf = new NURBSSurface();
UpdateNURBSSurface* updNurbs = new UpdateNURBSSurface();

void init() 
{
    updNurbs->init();

}

void display() 
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glLoadIdentity();
    //
    //octa->display();

    //glutSwapBuffers();

    //nurbsSurf->display();

    updNurbs->display();
}

void reshape(int width, int height) 
{
    //octa->reshape(width, height);
    //nurbsSurf->reshape(width, height);
    updNurbs->reshape(width, height);
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
