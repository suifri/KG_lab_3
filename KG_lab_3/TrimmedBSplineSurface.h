#pragma once
#include "UpdateNURBSSurface.h"

//TODO: � �-��������� ������� �������  ����, ����������� NURBS-������
class TrimmedBSplineSurface : public UpdateNURBSSurface
{

public:
	TrimmedBSplineSurface();
	virtual ~TrimmedBSplineSurface() = default;
	void display();
};

