#include "Bullet.h"
#include "Engine.h"
using namespace std;

Bullet::Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float speed)
	:GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	// Convert orientation from degrees to radians for velocity calculation

	orientationInDegrees = glm::degrees(initOrientation);
	velocity = glm::vec2(0.0f, 0.0f);
	Bullet::speed = speed;
}

void Bullet::update(double tDelta) {
	// Update position based on velocity
	velocity = glm::vec2(cos(glm::radians(orientationInDegrees)), sin(glm::radians(orientationInDegrees))) * speed;
	position += velocity * (float)tDelta;
}