#version 430

layout (points) in;
layout(triangle_strip, max_vertices = 5) out;
out vec2 gs_TexCoord;

uniform mat4 scale;

void main()
{
	gl_Position = gl_in[0].gl_Position - scale * vec4(-1, -1, 0.0, 0.0);
	gs_TexCoord = vec2(0.0, 0.0);
	EmitVertex();

	gl_Position = gl_in[0].gl_Position - scale * vec4(-1, 1, 0.0, 0.0);
	gs_TexCoord = vec2(0.0, 1.0);
	EmitVertex();

	gl_Position = gl_in[0].gl_Position - scale * vec4(1, 1, 0.0, 0.0);
	gs_TexCoord = vec2(1.0, 0.0);
	EmitVertex();

	gl_Position = gl_in[0].gl_Position - scale * vec4(1, 1, 0.0, 0.0);
	gs_TexCoord = vec2(1.0, 1.0);
	EmitVertex();

	EndPrimitive();
}