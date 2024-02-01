#include "WireOctahedronDrawingStrategy.h"

void WireOctahedronDrawingStrategy::drawOctahedron()
{
	glEnable(GL_COLOR_MATERIAL);
	glutWireOctahedron();
}
