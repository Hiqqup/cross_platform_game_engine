#version 300 es
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
out vec3 normal;
uniform mat4 mvp;
void main() {
    normal = aNormal;
    gl_Position = vec4(aPos  , 1.0) * mvp;
}
