#include "LabFacade.h"

LabFacade::LabFacade(Octahedron* octahedron, UpdateNURBSSurface* BSpline, RealNURBS* realNurbsSurface, TrimmedBSplineSurface* trimmed)
	:initFlag{true}, displayingUnit{UNIT_TYPE::OCTAHEDRON}
{
	this->octahedron = octahedron == nullptr ? new Octahedron() : octahedron;
	this->BSpline = BSpline == nullptr ? new UpdateNURBSSurface() : BSpline;
	this->realNurbsSurface = realNurbsSurface == nullptr ? new RealNURBS() : realNurbsSurface;
	this->trimmed = trimmed == nullptr ? new TrimmedBSplineSurface() : trimmed;
}

LabFacade::~LabFacade()
{
	delete this->BSpline;
	delete this->octahedron;
	delete this->realNurbsSurface;
	delete this->trimmed;

	this->BSpline = nullptr;
	this->octahedron = nullptr;
	this->realNurbsSurface = nullptr;
	this->trimmed = nullptr;
}

GLUnurbsObj* LabFacade::setNewNurbsObj(const GLboolean textureFlag)
{
	GLUnurbsObj* nurbs = gluNewNurbsRenderer();
	gluNurbsProperty(nurbs, GLU_SAMPLING_TOLERANCE, 25.0);

	if(textureFlag == false)
		gluNurbsProperty(nurbs, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON);
	else if(textureFlag == true)
		gluNurbsProperty(nurbs, GLU_DISPLAY_MODE, GLU_FILL);

	return nurbs;
}

void LabFacade::display()
{
	if (this->displayingUnit == UNIT_TYPE::OCTAHEDRON)
	{
		if (this->initFlag = true)
		{
			this->initFlag = false;
			this->octahedron->init();
		}

		this->octahedron->display();
		this->reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
	}
	else if (this->displayingUnit == UNIT_TYPE::BSpline)
	{
		if (this->initFlag = true)
		{
			this->initFlag = false;
			this->BSpline->init();
		}

		this->BSpline->display();
		this->reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
	}
	else if (this->displayingUnit == UNIT_TYPE::NURBSSurface)
	{
		if (this->initFlag = true)
		{
			this->initFlag = false;
			this->realNurbsSurface->init();
		}

		this->realNurbsSurface->display();
		this->reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
	}
	else if (this->displayingUnit == UNIT_TYPE::TrimmedBSpline)
	{
		if (this->initFlag = true)
		{
			this->initFlag = false;
			this->trimmed->init();
		}

		this->trimmed->display();
		this->reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
	}

}

void LabFacade::timeIncrementation()
{
	if (this->displayingUnit == UNIT_TYPE::OCTAHEDRON)
		this->octahedron->timerIncrementation();
}

void LabFacade::setTextureType(const GLboolean textureFlag)
{
	this->BSpline->setTextureType(this->setNewNurbsObj(textureFlag));
}

void LabFacade::setUnitType(const UNIT_TYPE displayingUnit)
{
	this->initFlag = true;
	this->displayingUnit = displayingUnit;
}

void LabFacade::reshape(const int width, const int height) const
{
	if (this->displayingUnit == UNIT_TYPE::OCTAHEDRON)
	{
		this->octahedron->reshape(width, height);
	}
	else if (this->displayingUnit == UNIT_TYPE::BSpline)
	{
		this->BSpline->reshape(width, height);
	}
	else if (this->displayingUnit == UNIT_TYPE::NURBSSurface)
	{
		this->realNurbsSurface->reshape(width, height);
	}
	else if (this->displayingUnit == UNIT_TYPE::TrimmedBSpline)
	{
		this->trimmed->reshape(width, height);
	}
}

void LabFacade::setOctahedronType(const OCTAHEDRON_TYPE octaShape) noexcept
{
	this->octahedron->setOctahedronDrawingStrategy(octaShape);
}