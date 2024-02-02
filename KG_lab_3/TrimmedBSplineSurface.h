#pragma once
#include "UpdateNURBSSurface.h"

//TODO: у бі-сплайновій поверхні вразіати  отвір, сформований NURBS-кривою
class TrimmedBSplineSurface : public UpdateNURBSSurface
{

public:
	TrimmedBSplineSurface();
	virtual ~TrimmedBSplineSurface() = default;
	void display();
};

