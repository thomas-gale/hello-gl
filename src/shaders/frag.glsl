#version 330 core

in vec3 ourColor;
in vec2 texCoord;
in vec3 pos;

uniform sampler2D ourTexture;

out vec4 fragColor;

void main() {
    fragColor = texture(ourTexture, texCoord);
    //fragColor = vec4(ourColor * (pos + 0.5), 1.0); 
}
