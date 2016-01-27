varying vec3 diffuseThickness;
varying vec3 unlitThickness;

uniform sampler2D noiseMap;

void main (void)
{
    vec3 color = diffuseThickness;
    vec3 noise = texture2D ( noiseMap, gl_TexCoord [0].xy * vec2 ( 0.7, 2.0 ) ).xyz;

    color = vec3 ( 1.0 ) - color * unlitThickness * noise.x;

    gl_FragColor = vec4 ( color, 1.0 );
}