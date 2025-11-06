#include "Engine.h"
#include "Keys.h"
#include <bitset>

//Usings
using namespace glm;

//Global variables

//Phase is the starting position in the sine wave
//Phase Velocity is how fast the enemy moves through the sine wave
float enemyPhase[3] = { 0.0f, 0.0f, 0.0f };
float enemyPhaseVelocity[3] = { radians(45.0f),
								radians(180.0f),
								radians(90.0f) };

float playerphase = 0.0f;
float playerphaseVelocity = radians(1080.0f);

// Storage for the key states
std::bitset<5> keys{ 0x0 }; //WASD + Space

const float playerSpeed = 5.0f;
const float playerRotateSpeed = 90.0f; // degrees per second


// Function prototypes

void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);



int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024, 5.0f);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	GameObject2D* addObject(
		const char* name,
		glm::vec2 initPosition = vec2(0.0f, 0.0f),
		float initOrientation = 0.0f,
		glm::vec2 initSize = vec2(1.0f, 1.0f),
		const char* texturePath = nullptr,
		TextureProperties texProperties = TextureProperties());


	//Adding an player
	addObject(
		"player", 
		vec2(-1.5f, 0.0f), 
		0.0f, 
		vec2(0.5f, 0.5f), 
		"Resources\\Textures\\player1_ship.png");

	//Adding the enemies
	addObject(
		"alien",
		vec2(0.0f, 0.0f),
		0.0f,
		vec2(0.75f, 0.75f),
		"Resources\\Textures\\alien.png");

	addObject(
		"alien",
		vec2(1.0f, 0.0f),
		0.0f,
		vec2(0.75f, 0.75f),
		"Resources\\Textures\\alien.png");

	addObject(
		"alien",
		vec2(2.0f, 0.0f),
		0.0f,
		vec2(0.75f, 0.75f),
		"Resources\\Textures\\alien.png");



	//
	// Setup game scene objects here
	//
	
	//Setting my own update and keyboard handler functions
	setUpdateFunction(myUpdate);
	setKeyboardHandler(myKeyboardHandler);

	// List all game object keys and their count in the engine 
	listGameObjectKeys();
	listObjectCounts();

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

// Function definitions

void myUpdate(GLFWwindow* window, double tDelta)
{
	setViewplaneWidth(10.0f);

	GameObject2D* player1 = getObject("player");

	if (keys.test(Key::W) == true)
	{
		player1->position.y += playerSpeed * (float)tDelta;
		//player1->orientation += playerRotateSpeed * (float)tDelta;
	}
	else if (keys.test(Key::S) == true)
	{
		player1->position.y -= playerSpeed * (float)tDelta;
		//player1->orientation -= playerRotateSpeed * (float)tDelta;
	}
	else if (keys.test(Key::A) == true)
	{
		player1->position.x -= playerSpeed * (float)tDelta;
		//player1->orientation -= playerRotateSpeed * (float)tDelta;
	}
	else if (keys.test(Key::D) == true)
	{
		player1->position.x += playerSpeed * (float)tDelta;
		//player1->orientation += playerRotateSpeed * (float)tDelta;
	}

	//Getting all the enemies
	GameObjectCollection enemies = getObjectCollection("alien");
	//Getting the first enemy
	//GameObject2D* enemy1 = enemies.objectArray[0];
	//Alternative way
	//enemies.objectArray[0];

	//Updating enemies position
	//enemy1->position.y = sin(enemyPhase[0]);//Phase is stored as radians no need for convesion
	//
	//enemyPhase[0] += enemyPhaseVelocity[0] * (float)tDelta;
	//
	////Enemy 2
	//enemy1->position.y = sin(enemyPhase[0]);//Phase is stored as radians no need for convesion
	//
	//enemyPhase[0] += enemyPhaseVelocity[0] * (float)tDelta;
	//
	////Enemy 3
	//enemy1->position.y = sin(enemyPhase[0]);//Phase is stored as radians no need for convesion
	//
	//enemyPhase[0] += enemyPhaseVelocity[0] * (float)tDelta;


	//Iterating through all enemies to update their position using a for loop (There can be 100 enemies, adds flexability)
	for (int i = 0; i < enemies.objectCount; i++)
	{
		enemies.objectArray[i]->position.y = sin(enemyPhase[i]);
		enemyPhase[i] += enemyPhaseVelocity[i] * (float)tDelta;
	}

	//Updating player position on the other axi
	//player1->position.x = sin(playerphase);
	//
	//playerphase += playerphaseVelocity * (float)tDelta;


}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	//Handle key press events
	if (action == GLFW_PRESS)
	{
		//Handle specific key presses
		switch (key){
		case GLFW_KEY_ESCAPE: //Close the window when escape is pressed
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W: //Handle W key press
			keys[Key::W] = true;
			break;
		case GLFW_KEY_A: //Handle A key press
			keys[Key::A] = true;
			break;
		case GLFW_KEY_S: //Handle S key press
			keys[Key::S] = true;
			break;
		case GLFW_KEY_D: //Handle D key press
			keys[Key::D] = true;
			break;
		case GLFW_KEY_SPACE: //Handle SPACE key press
			keys[Key::SPACE] = true;
			break;
		}
		
	}
	else if (action == GLFW_RELEASE) //Handle key release events
	{
		switch(key){
		case GLFW_KEY_W: //Handle W key release
			keys[Key::W] = false;
			break;
		case GLFW_KEY_A: //Handle A key release
			keys[Key::A] = false;
			break;
		case GLFW_KEY_S: //Handle S key release
			keys[Key::S] = false;
			break;
		case GLFW_KEY_D: //Handle D key release
			keys[Key::D] = false;
			break;
		case GLFW_KEY_SPACE: //Handle SPACE key press
			keys[Key::SPACE] = false;
			break;
		}
	}
}