#version 430 compatibility

// aPos		= attributum position
// aColor	= attributum color
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 myColor;
out vec3 myPos;

void main(void)
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	myPos = aPos;
	myColor = aColor;
}