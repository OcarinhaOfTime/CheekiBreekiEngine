uniform mat4 MVP;

in layout(location = 0) vec3 position;

void main(){
	gl_Position =  MVP * vec4(position,1);
}