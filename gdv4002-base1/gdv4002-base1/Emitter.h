#pragma once

#include "GameObject2D.h"
#include "random"

class Emitter : public GameObject2D {

private: 
	float emitTimeInterval;
	float emitCounter;

	unsigned long long particleNumber; 

	GLuint snowflakes[8];

	// Random number generator
	std::mt19937 generator;

	// Random distributions
	std::uniform_int_distribution<int> spriteDistribution; // Random texture selection
	std::uniform_real_distribution<float> normDistribution; // -1 to 1
	std::uniform_real_distribution<float> massDistribution, scaleDistribution;

public:

	Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval);

	void update(double tDelta) override;
	void render() override;
};