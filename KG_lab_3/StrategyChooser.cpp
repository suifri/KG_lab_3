#include "StrategyChooser.h"

IOctahedronDrawingStrategy* StrategyChooser::chooseStrategy(const OCTAHEDRON_TYPE type)
{
    IOctahedronDrawingStrategy* choice = nullptr;

	switch (type)
	{
	case OCTAHEDRON_TYPE::SOLID:
		choice = new SolidPolygonDrawingStrategy();
		break;
	case OCTAHEDRON_TYPE::WIRE:
		choice = new WireOctahedronDrawingStrategy();
		break;
	case OCTAHEDRON_TYPE::INTERPOLATED:
		choice = new InterpolatedOctahedronDrawingStrategy();
		break;
	default:
		break;
	}

    return choice;
}
