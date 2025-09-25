#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out FragPos;
out Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	FragPos = vec3(model * vec(aPos, 1.0));
	Normal	= aNormal;

	gl_Position = projection * view * model * vec4(aPos, 1.0);
}