#Shader_type = vertex
#version 330 core
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aUvCoords;

uniform mat4 ModelMatrix;
uniform mat4 ViewProjectionMatrix;
out vec2 UvCoords;

out vec2 FragPos;
void main()
{
gl_Position = ViewProjectionMatrix* ModelMatrix * vec4(aPos.xy,0,1.0f);
FragPos = aPos.xy;
UvCoords = aUvCoords;
}

#Shader_type = fragment
#version 330 core
out vec3 Color;
uniform vec3 uColor;
uniform vec2 uOrigin;
in vec2 FragPos;
in vec2 UvCoords;

void main()
{
float distance = 0.5-length(FragPos);
if(distance < 0.0)
{
discard;
}
Color =uColor;
}