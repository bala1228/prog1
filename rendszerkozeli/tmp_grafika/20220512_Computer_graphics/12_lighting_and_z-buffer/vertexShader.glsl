#version 430

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 invTMatrix;

void main(void)
{
//	Normal = normalize(vec3(invTMatrix * vec4(aNormal, 0.0)));
	Normal = vec3(invTMatrix * vec4(aNormal, 0.0));
	FragPos = vec3(view * model * vec4(aPos, 1.0));

	gl_Position =  projection * vec4(FragPos, 1.0);
}
