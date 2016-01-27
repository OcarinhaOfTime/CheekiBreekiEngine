uniform mat4 MVP;

in layout(location = 0) vec3 position;
in layout(location = 1) vec2 uv;
in layout(location = 2) vec3 normal;

varying vec2 v_uv;
varying vec3 v_normal;

void main(){
	v_uv = uv;
	v_normal = normal; 
	gl_Position =  MVP * vec4(position,1);
}