#pragma once
#include "SolidPolygonDrawingStrategy.h"
#include "WireOctahedronDrawingStrategy.h"
#include "InterpolatedOctahedronDrawingStrategy.h"
#include "OCTAHEDRON_TYPE.h"

class StrategyChooser
{
public:
	static IOctahedronDrawingStrategy* chooseStrategy(const OCTAHEDRON_TYPE type);

};

