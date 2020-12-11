#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 baseTransform;
uniform float mov;

out vec3 ourColor;
out vec2 texCoord;
out vec3 pos;

void main() {
    gl_Position = baseTransform * vec4(aPos, 1.0) + vec4(mov, mov, 0.0, 0.0);
    ourColor = aColor;
    texCoord = aTexCoord;
    pos = gl_Position.xyz;
}
