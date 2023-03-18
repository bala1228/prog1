#version 430

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

out vec3 myColor;

uniform mat4 transform;

void main(void)
{
	gl_Position = transform * vec4(aPos, 1.0);
	myColor = color;
}