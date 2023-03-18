#version 430 compatibility

out vec4 myColor;

void main(void)
{
	gl_Position = gl_Vertex;
	myColor = gl_Color;
}