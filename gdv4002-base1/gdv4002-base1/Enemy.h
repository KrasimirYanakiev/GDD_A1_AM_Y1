#pragma once

#include "Gameobject2D.h"
#include <glm/glm.hpp>

class Enemy : public GameObject2D
{

private:

	float angle; // Radians
	float velocity; // Units per second

public:

	Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialAngle, float initialVelocity);

	void update(double tDelta) override;


};