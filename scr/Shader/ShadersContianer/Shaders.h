#pragma once

//TODO:
//Add more shaders and a way to be able to keep track of uniforms 
inline const char* VertexShader =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 aUvCoords;\n"

"uniform mat4 ModelMatrix;\n"
"uniform mat4 ProjectionMatrix;\n"
"out vec4 debug;\n"
"void main()\n"
"{\n"
"gl_Position = ProjectionMatrix* ModelMatrix * vec4(aPos.xy,0,1.0f);\n"

"}\0";

inline const char* FragmentShader =
"#version 330 core\n"
"out vec3 Color;\n"
"uniform vec3 uColor;\n"
"in vec4 debug;\n"
"void main()\n"
"{\n"
"Color = vec3(1.0,1.0,1.0);\n"
"}\0";

