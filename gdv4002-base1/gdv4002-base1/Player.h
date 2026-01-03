#pragma once

#include "GameObject2D.h"

class Player : public GameObject2D
{

private:

	float mass;
	glm::vec2 velocity;
	float rechargeTime;
	float bulletCounter;
	unsigned long long bulletID = 0;

public:

	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initMass);

	void update(double tDelta) override;

};