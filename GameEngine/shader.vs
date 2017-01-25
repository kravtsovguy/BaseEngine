#version 330 core
layout (location = 0) in vec3 position; // Устанавливаем позиция переменной с координатами в 0
layout (location = 1) in vec3 color;    // А позицию переменной с цветом в 1
layout (location = 2) in vec2 texCoord;

out vec3 ourColor; // Передаем цвет во фрагментный шейдер
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    ourColor = color; // Устанавливаем значение цвета, полученное от вершинных данных
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}
