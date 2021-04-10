#version 450

layout(location = 0) in vec3 fragColor;     // interpolated color from vertex

layout(location = 0) out vec4 outColor;     // Final output color

void main() {
    outColor = vec4(fragColor, 1.0);
}