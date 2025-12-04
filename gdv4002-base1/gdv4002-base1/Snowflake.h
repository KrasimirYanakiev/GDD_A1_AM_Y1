#pragma once

// Model snowflake particle system

#include "GameObject2d.h"

class Snowflake : public GameObject2D {

private:
	// Linear movement of a snowflake
	float mass;
	glm::vec2 velocity;
	// Angle of rotation change per second in radians
	float angleChangePerSecond;

public:
	Snowflake(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond);

	void update(double tDelta) override;
	
};