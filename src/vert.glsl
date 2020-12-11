#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

uniform float mov;

out vec3 ourColor;
out vec3 pos;

void main() {
    gl_Position = vec4(aPos, 1.0) + vec4(mov, mov, 0.0, 0.0);
    ourColor = aColor;
    pos = gl_Position.xyz;
}
