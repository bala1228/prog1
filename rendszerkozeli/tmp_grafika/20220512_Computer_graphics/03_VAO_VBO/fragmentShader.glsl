#version 430 compatibility

in vec3 myPos;
in vec3 myColor;
out vec4 color;

void main(void)
{
	color = vec4(myColor, 1.0);
//	color = vec4(myColor * (myPos.x + 1.0) / 2.0, 1.0);
//	color = vec4(myColor * (1.0 - (myPos.x + 1.0) / 2.0), 1.0);
}