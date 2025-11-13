#include "Enemy.h"

Enemy::Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialAngle, float initialVelocity)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	angle = initialAngle;
	velocity = initialVelocity;
}

void Enemy::update(double tDelta)
{
	// Set position based on angle
	position.y = sin(angle);

	// Update angle based on velocity

	angle += velocity * (float)tDelta;
	
}