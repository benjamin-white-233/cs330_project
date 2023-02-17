#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
in vec3 fragNormal;
in vec3 fragPos;

uniform sampler2D tex0; // GL_TEXTURE0
uniform sampler2D tex1; // GL_TEXTURE1
uniform sampler2D tex2; // GL_TEXTURE2
uniform sampler2D tex3; // GL_TEXTURE3

uniform sampler2D tex;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;


void main() {
    vec3 objectColor = vertexColor.xyz;

    vec3 lightColor = vec3(1.f, 1.f, 0.95f);
//    vec3 objectColor = vec3(1.f, 0.2f, 0.2f);
    // ambient
    float ambientStrength = 3.f;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    float specularStrength = 15.f;
    float shine = 32;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shine);
    vec3 specular = specularStrength * spec * lightColor;

    // combining object color and texture
    objectColor = vec3(vertexColor * mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.5));

    // combining textured object color and light
    vec3 result = (ambient + diffuse + specular) * objectColor;

//    vec3 finalColor = result * objectColor;
    FragColor = vec4(result, 1.0);

}