#version 430 compatibility

in vec4 myColor;

void main(void)
{
	gl_FragColor = myColor;
}