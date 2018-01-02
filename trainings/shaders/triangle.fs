#version 450 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

//uniform vec2 mixTexture;

void main()
{
    vec2 tmpVec = vec2(2 * TexCoord.x, (-1)*TexCoord.y);
    FragColor = mix( texture(texture1, TexCoord), texture(texture2, tmpVec), 0.2);
//      FragColor = texture(texture1,TexCoord);
}
