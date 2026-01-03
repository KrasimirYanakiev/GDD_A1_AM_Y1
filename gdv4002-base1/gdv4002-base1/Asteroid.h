#pragma once

// Model asteroid particle system

#include "GameObject2d.h"

class Asteroid : public GameObject2D {

private:
	// Linear movement of a asteroid
	float mass;
	glm::vec2 velocity;
	// Angle of rotation change per second in radians
	float angleChangePerSecond;

public:
	Asteroid(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond);

	void update(double tDelta) override;
	
};