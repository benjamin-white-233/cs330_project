#version 330 core
out vec4 FragColor;

in vec4 vertexColor;

uniform vec3 objectColor;

void main() {
    vec3 objectColor = vertexColor.xyz;
    FragColor = vec4(vertexColor);
}