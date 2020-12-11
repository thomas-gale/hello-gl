#version 330 core

in vec3 ourColor;
in vec3 pos;

out vec4 fragColor;

void main() { 
    fragColor = vec4(ourColor * (pos + 0.5), 1.0); 
}
