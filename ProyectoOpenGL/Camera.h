#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

float YAW = -90.0f;
float PITCH = 0.0f;
float SPEED = 2.5f;
float SENSITIVITY = 0.1;
float ZOOM = 45.0f;

class Camera
{

};

#endif // !CAMERA_H

