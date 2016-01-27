uniform sampler2D _mainText;
uniform vec3 lightDir;

in vec3 v_normal;
in vec2 v_uv;

void main()
{
	float intensity;
	vec4 color = texture2D(_mainText, v_uv);
	intensity = dot(lightDir, v_normal);

	if (intensity > 0.95)
		color = color;
	else if (intensity > 0.5)
		color = color * vec4(0.5,0.5,0.5,1.0);
	else if (intensity > 0.25)
		color = color * vec4(0.25,0.25,0.25,1.0);
	else
		color = color *  vec4(0.1,0.1,0.1,1.0);

	gl_FragColor = color;

}