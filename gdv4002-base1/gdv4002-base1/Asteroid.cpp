#include "Asteroid.h"
#include "Engine.h"

extern glm::vec2 gravity;

Asteroid::Asteroid(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond)
:GameObject2D(initPosition, initOrientation, initSize, initTextureID){

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);

	maxVelocity = 1.5f;
	minVelocity = 1.5f;

	this->angleChangePerSecond = angleChangePerSecond;
}

void Asteroid::update(double tDelta) {
	// Physics

	// 1.1 Sum Forces, Gravity Only
	glm::vec2 F = gravity;

	// 1.2 Accelaration
	glm::vec2 accel = F * (3.0f / mass);

	// 1.3 Update Velocity
	velocity = velocity + accel * (float)tDelta;

	// 1.4 Update Position
	position = position + velocity * (float)tDelta;

	
	// Rotation
	orientation += (angleChangePerSecond * (float)tDelta) * 5;

	if (velocity.x > maxVelocity)
		velocity.x = maxVelocity;
	else if (velocity.x < minVelocity)
		velocity.x = minVelocity;
	if (velocity.y > maxVelocity)
		velocity.y = maxVelocity;
	else if (velocity.y < minVelocity)
		velocity.y = minVelocity;


	// I have given them more space as they are smaller objects and it makes the screen a little less cluttered
	// Floor collision
	if (position.y < -getViewplaneHeight() / 2.0f)
	{
		position.y = getViewplaneHeight() / 2.0f;
	}
	// Ceiling collision
	if (position.y > getViewplaneHeight() / 2.0f)
	{
		position.y = -getViewplaneHeight() / 2.0f;
	}
	// Left wall collision
	if (position.x < -getViewplaneWidth() / 2.0f)
	{
		position.x = getViewplaneWidth() / 2.0f;
	}
	// Right wall collision
	if (position.x > getViewplaneWidth() / 2.0f)
	{
		position.x = -getViewplaneWidth() / 2.0f;
	}
}