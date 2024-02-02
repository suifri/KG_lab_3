#include "TrimmedBSplineSurface.h"

TrimmedBSplineSurface::TrimmedBSplineSurface()
{
}

//TODO: у бі-сплайновій поверхні вразіати  отвір, сформований NURBS-кривою
void TrimmedBSplineSurface::display()
{
    GLfloat knots[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };
    GLfloat curveKnots[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };
    GLfloat curvePt[6][2] = /* clockwise */
    { {0.25, 0.5}, {0.25, 0.75}, {0.75, 0.75}, {0.75, 0.5}, {0.5, 0.25}, {0.25, 0.5} };
    GLfloat pwlPt[4][2] = /* clockwise */
    { {0.75, 0.5}, {0.5, 0.25}, {0.25, 0.5} };

    GLfloat edgePt[5][2] = /* counter clockwise */
    { {0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0},
     {0.0, 0.0} };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(330.0, 1., 0., 0.);
    glScalef(0.5, 0.5, 0.5);

    gluBeginSurface(this->nurbs);
    gluNurbsSurface(this->nurbs, 8, knots, 8, knots,
        4 * 3, 3, &this->controlPoints[0][0][0],
        4, 4, GL_MAP2_VERTEX_3);

    //gluBeginTrim(this->nurbs);
    //gluPwlCurve(this->nurbs, 5, &edgePt[0][0], 2,
    //    GLU_MAP1_TRIM_2);
    //gluEndTrim(this->nurbs);

    gluBeginTrim(this->nurbs);
    gluNurbsCurve(this->nurbs, 8, curveKnots, 2,
        &edgePt[0][0], 5, GLU_MAP1_TRIM_2);
    gluEndTrim(this->nurbs);
    gluEndSurface(this->nurbs);

    glPopMatrix();
    glFlush();
}
