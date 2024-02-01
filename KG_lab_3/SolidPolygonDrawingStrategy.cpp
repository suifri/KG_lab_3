#include "SolidPolygonDrawingStrategy.h"

void SolidPolygonDrawingStrategy::drawOctahedron()
{
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.4f, 0.0f, 0.0f);
	glShadeModel(GL_FLAT);
	glutSolidOctahedron();
	glDisable(GL_COLOR_MATERIAL);
}
