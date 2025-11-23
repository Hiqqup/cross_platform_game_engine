#version 300 es
precision mediump float;
in vec3 normal;
out vec4 FragColor;
void main() {

    vec3 light_direction = vec3(1.0, 0.0,0.0);
    vec3 color = vec3(1.0,0.0,0.0);
    float angle  =dot(normal, light_direction);

    FragColor = vec4(color* angle,1.0);
    //FragColor = texture(ourTexture, TexCoord) * vec4(vertexColor, 1.0);
   // FragColor = vec4(vertexColor, 1.0);
}
