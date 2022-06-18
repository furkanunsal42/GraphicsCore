#<vertex shader>

#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coordinates;
layout(location = 2) in vec3 normal;
out vec2 tex_coords;
out vec3 frag_normal;
out vec3 frag_space_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	frag_normal = vec3(model * vec4(normal, 0.0f));
	tex_coords = texture_coordinates;
	frag_space_coord = position;
	gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1);
}