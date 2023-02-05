#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D tex0; // GL_TEXTURE0
uniform sampler2D tex1; // GL_TEXTURE1
uniform sampler2D tex2; // GL_TEXTURE2

uniform sampler2D tex; // GL_TEXTURE0


void main() {
//    FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), texture(tex2, texCoord), 0.5) * vertexColor;

    FragColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5);

    //    FragColor = texture(tex, texCoord);

}