#include "Snowflake.h"

extern glm::vec2 gravity;

Snowflake::Snowflake(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond)
:GameObject2D(initPosition, initOrientation, initSize, initTextureID){

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);

	this->angleChangePerSecond = angleChangePerSecond;
}

void Snowflake::update(double tDelta) {
	// Physics

	// 1.1 Sum Forces, Gravity Only
	glm::vec2 F = gravity;

	// 1.2 Accelaration
	glm::vec2 accel = F * (1.0f / mass);

	// 1.3 Update Velocity
	velocity = velocity + accel * (float)tDelta;

	// 1.4 Update Position
	position = position + velocity * (float)tDelta;

	
	// Rotation
	orientation += angleChangePerSecond * (float)tDelta;
}