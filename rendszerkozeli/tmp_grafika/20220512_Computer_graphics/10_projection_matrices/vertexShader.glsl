#version 430

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

out vec3 myColor;

// this will be the MVP structure
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
	gl_Position =  projection * view * model * vec4(aPos, 1.0);
	myColor = color;
}