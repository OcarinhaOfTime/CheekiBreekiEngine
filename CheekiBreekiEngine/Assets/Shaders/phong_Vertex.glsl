in layout(location = 0) vec3 position;
in layout(location = 1) vec2 uv;
in layout(location = 2) vec3 normal;

out vec2 v_uv;
out vec3 v_normal;
out vec3 v_position;

uniform mat4 MVP;

void main(){
	v_uv = texCoord;
	v_normal = normal;
	v_position = position;

	gl_Position =  MVP * vec4(position,1);
}

