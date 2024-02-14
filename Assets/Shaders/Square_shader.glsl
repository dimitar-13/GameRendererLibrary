#Shader_type = vertex
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aUvCoords;

uniform mat4 ModelMatrix;
uniform mat4 ViewProjectionMatrix;
void main()
{
gl_Position = ViewProjectionMatrix* ModelMatrix * vec4(aPos.xy,0,1.0f);
}

#Shader_type = fragment
#version 330 core
out vec3 Color;
uniform vec3 uColor;
void main()
{
Color = uColor;
}

