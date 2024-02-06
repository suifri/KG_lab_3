#pragma once
#include "StrategyChooser.h"

class Octahedron
{
private:
	GLfloat angle;
	GLfloat angle_;
	IOctahedronDrawingStrategy* drawingStrategy;

	void lightMovement() const;
public:
	Octahedron();
	~Octahedron();
	void display() const;
	void reshape(const int width, const int height) const;
	void timerIncrementation();
	void setOctahedronDrawingStrategy(const OCTAHEDRON_TYPE octaShape = OCTAHEDRON_TYPE::SOLID) noexcept;
	void init();
};

