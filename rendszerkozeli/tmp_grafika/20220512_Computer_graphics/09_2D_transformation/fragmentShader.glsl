#version 430

in vec3 myColor;
out vec4 color;

void main(void)
{
	color = vec4(myColor, 1.0);
}