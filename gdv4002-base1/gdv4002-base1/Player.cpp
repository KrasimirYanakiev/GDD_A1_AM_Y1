#include "Player.h"
#include "Keys.h"
#include "bitset"

extern std::bitset<5> keys; //WASD + Space

Player::Player(glm::vec2 initPosition, float initOrientation, 
	glm::vec2 initSize, GLuint initTextureID, float initialSpeed) : 
	GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	speed = initialSpeed;
}


void Player::update(double tDelta) {
	if (keys.test(Key::W) == true)
	{
		position.y += speed * (float)tDelta;
	}
	else if (keys.test(Key::S) == true)
	{
		position.y -= speed * (float)tDelta;
	}
	if (keys.test(Key::A) == true)
	{
		position.x -= speed * (float)tDelta;
	}
	else if (keys.test(Key::D) == true)
	{
		position.x += speed * (float)tDelta;
	}
}

