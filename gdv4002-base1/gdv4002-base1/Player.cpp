#include "Player.h"
#include "Keys.h"
#include "bitset"

extern std::bitset<5> keys; //WASD + Space

Player::Player(glm::vec2 initPosition, float initOrientation, 
	glm::vec2 initSize, GLuint initTextureID, float mass) : 
	GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);
}


void Player::update(double tDelta) {

	glm::vec2 F = glm::vec2(0.0f, 0.0f);
	const float thrust = 3.0f;


	if (keys.test(Key::W) == true)
	{
		F += glm::vec2(0.0f, thrust);
	}
	else if (keys.test(Key::S) == true)
	{
		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(Key::A) == true)
	{
		F += glm::vec2(-thrust, 0.0f);
	}
	else if (keys.test(Key::D) == true)
	{
		F += glm::vec2(thrust, 0.0f);
	}

	// Calculate acceleration
	glm::vec2 a = F * (1.0f / mass);
	
	// Integrate to get new velocity
	velocity += a * (float)tDelta;

	// Integrate to get new position
	position += velocity * (float)tDelta;
}

