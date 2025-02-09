#include <GL\glut.h>

GLfloat xRotated, yRotated, zRotated;
// Octahedron
void displayOctahedron(void)
{

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0, 0.0, -5.5);
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    // scaling transfomation 
    glScalef(1.0, 1.0, 1.0);
    // built-in (glut library) function , draw you a Octahedron.
    glutSolidOctahedron();
    // Flush buffers to screen

    glFlush();
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void reshapeOctahedron(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);

    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleOctahedron(void)
{

    yRotated += 0.03;

    displayOctahedron();
}

GLfloat black[] = {0.2, 1.0, 0.3, 1.0};

int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // window size
    glutInitWindowSize(400, 350);
    // create the window 
    glutCreateWindow("Octahedron Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    xRotated = yRotated = zRotated = 40.0;
    xRotated = 33;
    yRotated = 40;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    //Assign  the function used in events
    glutDisplayFunc(displayOctahedron);
    glutReshapeFunc(reshapeOctahedron);
    //glutIdleFunc(idleOctahedron);
    //Let start glut loop
    glutMainLoop();
    return 0;
}