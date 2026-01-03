#pragma once

// Bullet projectile class

#include "GameObject2D.h"
class Bullet : public GameObject2D {

private:
	// Linear movement of a bullet
	glm::vec2 velocity;
	float orientationInDegrees;
	float speed;

public:
	Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float speed);

	void update(double tDelta) override;
};