#version 460 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in mat4 instanceMatrix;

out vec2 TexCoord;
uniform float time;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    //gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    gl_Position = projection * view * instanceMatrix * vec4(aPos.x, aPos.y, aPos.z, 3.0);
    //gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //gl_Position = projection * view * model * vec4(aPos, 1.0);
}