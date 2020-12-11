#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

uniform float movX;

out vec3 ourColor;

void main() {
    gl_Position = vec4(aPos, 1.0) + vec4(movX, 0.0, 0.0, 0.0);
    ourColor = aColor;
}
