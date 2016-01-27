uniform mat4 MVP;

in layout(location = 0) vec3 position;
in layout(location = 1) vec2 uv;

varying vec2 v_uv;

void main(){
	v_uv = uv;
	gl_Position =  MVP * vec4(position,1);
}

