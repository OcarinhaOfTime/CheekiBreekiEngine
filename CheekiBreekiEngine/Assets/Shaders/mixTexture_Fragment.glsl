uniform sampler2D _mainText;
uniform sampler2D _secondText;

in vec2 v_uv;

void main()
{
	vec4 sample1 = texture2D(_mainText, v_uv);
	vec4 sample2 = texture2D(_secondText, v_uv);
    gl_FragColor = mix(sample1, sample2, 0.2);
}