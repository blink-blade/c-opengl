#version 460 core
out vec4 FragColor;

void main() {
    vec2 fragCoord = gl_FragCoord.xy;
    FragColor = vec4(fragCoord.x / 800.0f, 0.0f , fragCoord.y / 2000.0f, 1.0f);
};