#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

//uniform sampler2D tex;

void main()
{
    //color = texture(tex, TexCoord);
    color = vec4(ourColor, 1.0f);
}
