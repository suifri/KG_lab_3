#include <GL/glut.h>
#include "Octahedron.h"
#include "NURBSSurface.h"
#include "TrimmedBSplineSurface.h"
#include "RealNURBS.h"
#include "LabFacade.h"

const GLint WIDTH = 500;
const GLint HEIGHT = 500;

LabFacade* facade = new LabFacade();

void mainMenuHandler(int choice)
{
    switch (choice)
    {
    case 0:
        facade->setUnitType();
        glutPostRedisplay();
        break;
    case 1:
        facade->setUnitType(UNIT_TYPE::BSpline);
        glutPostRedisplay();
        break;
    case 2:
        facade->setUnitType(UNIT_TYPE::NURBSSurface);
        glutPostRedisplay();
        break;
    case 3:
        facade->setUnitType(UNIT_TYPE::TrimmedBSpline);
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void subMenuHandler(int choice)
{
    switch (choice)
    {
    case 0:
        facade->setOctahedronType();
        break;
    case 1:
        facade->setOctahedronType(OCTAHEDRON_TYPE::WIRE);
        break;
    case 2:
        facade->setOctahedronType(OCTAHEDRON_TYPE::INTERPOLATED);
        break;
    default:
        break;
    }
}

void NURBSSubMenuHandler(int choice)
{
    switch (choice)
    {
    case 0:
        facade->setTextureType();
        break;
    case 1:
        facade->setTextureType(true);
        break;
    default:
        break;
    }
}
void display() 
{
    facade->display();
}

void reshape(int width, int height) 
{
    facade->reshape(width, height);
}

void timer(int value) {
    facade->timeIncrementation();
    glutPostRedisplay(); 
    glutTimerFunc(16, timer, 0); 
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lit Octahedron");
    
    
    int octahedronSubMenu = glutCreateMenu(subMenuHandler);
    glutAddMenuEntry("Solid", 0);
    glutAddMenuEntry("Wire", 1);
    glutAddMenuEntry("Interpolated", 2);

   /* int NurbsSubMenu = glutCreateMenu(NURBSSubMenuHandler);
    glutAddMenuEntry("Not fill", 0);
    glutAddMenuEntry("Fill", 1);*/

    glutCreateMenu(mainMenuHandler);
    glutAddMenuEntry("Octahedron", 0);
    glutAddMenuEntry("B-Spline", 1);
    glutAddMenuEntry("NURBS-surface", 2);
    glutAddMenuEntry("Trimmed B-spline", 3);
    glutAddSubMenu("Octahedron texture", octahedronSubMenu);
    //glutAddSubMenu("NURBS texture", NurbsSubMenu);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    delete facade;
    facade = nullptr;

    return 0;
}
