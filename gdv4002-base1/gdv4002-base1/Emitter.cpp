#include "Emitter.h"
#include "Engine.h"
#include "Snowflake.h"


using namespace std;

Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval)
	:GameObject2D(initPosition, 0.0f, initSize, 0) {
	
	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval; // Emit immediately

	particleNumber = 0;

	for (int i = 0; i < 8; i++)
	{
		string path = "Resource\\Textures\\Snow\\snowflake" + to_string(i + 1) + string(".png");
		snowflakes[i] = loadTexture(path.c_str());

		if (snowflakes[i] >0)
			cout << "Successfully Loaded Texture" << path << endl;
		else
			cout << "Failed to Load Texture" << path << endl;

	}

	// Random number generator
	random_device rd;

	// Standard mersenne_twister_engine seeded with rd() - mt19937 is a high-quality pseudo-random number generator
	generator = mt19937(rd());

	spriteDistribution = uniform_int_distribution<int>(0, 7); // 8 textures
	normDistribution = uniform_real_distribution<float>(-1.0f, 1.0f); // -1 to 1
	massDistribution = uniform_real_distribution<float>(0.005f, 0.08f); // mass
	scaleDistribution = uniform_real_distribution<float>(0.1f, 0.5f); // scale
}

void Emitter::render() 
{

}

void Emitter::update(double tDelta) {

	emitCounter += (float)tDelta;
	
	while (emitCounter >= emitTimeInterval)
	{
		// Decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
		emitCounter -= emitTimeInterval;

		// New Particle
		float x = position.x + normDistribution(generator) * size.x;
		float y = position.y + normDistribution(generator) * size.y;
		float scale = scaleDistribution(generator);
		float mass = massDistribution(generator);
		float rotationSpeed = glm::radians(normDistribution(generator) * 45.0f);
		int spriteIndex = spriteDistribution(generator);

		Snowflake* s1 = new Snowflake(glm::vec2(x, y), 0.0f, glm::vec2(scale, scale), snowflakes[spriteIndex], mass, rotationSpeed);

		string key = string("snowflake");

		if (particleNumber > 0) // First name in collection must not be numbered if using this approach
		{
			// Add value so it is unique anyway - not using engine mechanism
			key += to_string(particleNumber);
		}

		particleNumber++;
	}
}