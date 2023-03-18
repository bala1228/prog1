#version 430

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 aNormal;

out vec3 myColor;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
	myColor = color;
	Normal = aNormal;
	FragPos = vec3(model * vec4(aPos, 1.0));

	gl_Position =  projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
