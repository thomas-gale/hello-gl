#version 330 core

in vec3 ourColor;
in vec2 texCoord;
in vec3 pos;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

out vec4 fragColor;

void main() {
    fragColor = mix(texture(ourTexture1, texCoord), texture(ourTexture2, texCoord), pos.x+0.5) * vec4(ourColor, 0.5f);
}
