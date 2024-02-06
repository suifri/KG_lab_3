#pragma once
#include "RealNURBS.h"
#include "Octahedron.h"
#include "TrimmedBSplineSurface.h"
#include "UpdateNURBSSurface.h"
#include "UNIT_TYPE.h"

class LabFacade
{
private:
	Octahedron* octahedron;
	UpdateNURBSSurface* BSpline;
	RealNURBS* realNurbsSurface;
	TrimmedBSplineSurface* trimmed;
	GLboolean initFlag;
	UNIT_TYPE displayingUnit;

	GLUnurbsObj* setNewNurbsObj(const GLboolean textureFlag = false);

public:
	LabFacade(Octahedron* octahedron = nullptr, UpdateNURBSSurface* BSpline = nullptr, RealNURBS* realNurbsSurface = nullptr, TrimmedBSplineSurface* trimmed = nullptr);
	~LabFacade();

	void display();
	void reshape(const int width = 500, const int heigh = 500) const;
	void timeIncrementation();

	void setOctahedronType(const OCTAHEDRON_TYPE octaShape = OCTAHEDRON_TYPE::SOLID) noexcept;
	void setUnitType(const UNIT_TYPE displayingUnit = UNIT_TYPE::OCTAHEDRON);
	void setTextureType(const GLboolean textureFlag = false);
};

