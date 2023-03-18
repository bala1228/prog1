#version 430

layout (location = 0) in vec3 aPos;
//out vec3 myColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
	gl_Position =  projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}