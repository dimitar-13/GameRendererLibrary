#pragma once

const char* VertexShader =
"#version 330 core\n"
"layout(location = 0) in vec2 aPos;\n"
"layout(location = 1) in vec3 aColor;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos,1,1);\n"
"}\0";

const char* FragmentShader =
"#version 330 core\n"
"out vec3 Color;\n"
"uniform vec3 uColor;\n"
"void main()\n"
"{\n"
"Color = uColor;\n"
"}\0";

