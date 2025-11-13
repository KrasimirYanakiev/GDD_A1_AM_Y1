#pragma once

#include "GameObject2D.h"

class Player : public GameObject2D
{

private:

	float speed;

public:

	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initSpeed);

	void update(double tDelta) override;

};