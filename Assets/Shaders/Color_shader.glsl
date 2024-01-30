#Shader_type = vertex
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aUvCoords;

uniform mat4 ModelMatrix;
uniform mat4 ViewProjectionMatrix;
out vec4 debug;
out vec2 UvCoords;
void main()
{
gl_Position = ViewProjectionMatrix* ModelMatrix * vec4(aPos.xy,0,1.0f);
UvCoords = aUvCoords;
}

#Shader_type = fragment
#version 330 core
out vec3 Color;
uniform vec3 uColor;
in vec4 debug;
in vec2 UvCoords;
uniform sampler2D samplerTexture;

void main()
{
Color = texture(samplerTexture,UvCoords).rgb;
}

