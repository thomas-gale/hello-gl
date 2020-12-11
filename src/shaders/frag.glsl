#version 330 core

in vec2 texCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

out vec4 fragColor;

void main() {
    fragColor = mix(texture(ourTexture1, texCoord), texture(ourTexture2, texCoord), 0.5);
}
