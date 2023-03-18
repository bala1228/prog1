#version 430

layout (location = 0) in vec3 aPos;

uniform float offsetX;
uniform float offsetY;

void main(void)
{
	gl_Position = vec4(aPos.x + offsetX, aPos.y + offsetY, aPos.z, 1.0);
}