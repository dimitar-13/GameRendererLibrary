#Shader_type = vertex
#version 330 core
layout(location = 0) in vec2 aWorldPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aUvCoords;
layout(location = 3) in float aTextureID;

uniform mat4 ViewProjectionMatrix;
out vec3 FragColor;
out float FragTextureID;
out vec2 FragUvCoords;
void main()
{
gl_Position = ViewProjectionMatrix*  vec4(aWorldPos.xy,0,1.0f);
FragColor = aColor;
FragTextureID = aTextureID;
FragUvCoords = aUvCoords;
}

#Shader_type = fragment
#version 330 core
#define MAX_TEXTURE_UNIT_COUNT 32
out vec3 Color;
uniform sampler2D samplers[MAX_TEXTURE_UNIT_COUNT];
in vec3 FragColor;
in float FragTextureID;
in vec2 FragUvCoords;
void main()
{
int index = int(FragTextureID);
vec4 Sampledtexel = texture(samplers[index],FragUvCoords);
if(Sampledtexel.a < .1)
	discard;
Color = Sampledtexel.rgb*FragColor;
}

