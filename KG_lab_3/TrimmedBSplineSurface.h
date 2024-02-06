#pragma once
#include "UpdateNURBSSurface.h"

class TrimmedBSplineSurface : public UpdateNURBSSurface
{

public:
	TrimmedBSplineSurface();
	virtual ~TrimmedBSplineSurface() = default;
	void display();
};

