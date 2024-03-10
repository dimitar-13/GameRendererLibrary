#Shader_type = vertex
#version 330 core
layout(location = 0) in vec2 aWorldPos;
layout(location = 1) in vec3 aColor;

uniform mat4 ViewProjectionMatrix;
out vec3 FragColor;
void main()
{
gl_Position = ViewProjectionMatrix*  vec4(aWorldPos.xy,0,1.0f);
FragColor = aColor;
}

#Shader_type = fragment
#version 330 core
out vec3 Color;
in vec3 FragColor;
void main()
{
Color = FragColor;
}

