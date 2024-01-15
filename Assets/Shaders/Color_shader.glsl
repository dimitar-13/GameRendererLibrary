#Shader_type = vertex
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUvCoords;

uniform mat4 ModelMatrix;
uniform mat4 ProjectionMatrix;
out vec4 debug;
void main()
{
gl_Position = ProjectionMatrix* ModelMatrix * vec4(aPos.xy,0,1.0f);
}

#Shader_type = fragment
#version 330 core
out vec3 Color;
uniform vec3 uColor;
in vec4 debug;
void main()
{
Color = vec3(1.0,1.0,1.0);
}

