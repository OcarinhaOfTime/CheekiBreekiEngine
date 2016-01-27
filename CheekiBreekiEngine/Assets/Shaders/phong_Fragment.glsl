uniform mat4 M;
uniform sampler2D _mainText;
uniform vec4 ambientLight;
uniform vec3 lightPosition;
uniform vec3 eyePosition;

in vec2 v_uv;
in vec3 v_normal;
in vec3 v_position;

void main()
{
	vec3 worldPosition = vec3(M * vec4(v_position, 1));

	vec3 lightVector = -normalize(worldPosition - vec3(2, 1, 0));
	float diffuseLight = dot(v_normal, lightVector);
	diffuseLight = clamp(diffuseLight, 0, 1);

	gl_FragColor = ambientLight + diffuseLight * texture2D(_mainText, v_uv);
}