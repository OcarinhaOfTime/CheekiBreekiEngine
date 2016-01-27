uniform vec3  lightPos;
uniform vec3  eyePos;
uniform mat4 MVP;
uniform mat4 MV;


varying vec3  diffuseThickness;
varying vec3  unlitThickness;

void main(void)
{
    const vec3  one       = vec3 ( 1.0 );
    const vec3  ambient   = vec3 ( 0.4, 0.4, 0.4 );
    const vec3  diffuse   = vec3 ( 0.0, 0.0, 1.0 );
    const float specPower = 50.0;

    vec3 p = vec3 ( MV * gl_Vertex );
    vec3 l = normalize ( lightPos - p );
    vec3 v = normalize ( vec3 ( eyePos ) - p );
    vec3 h = normalize ( l + v );
    vec3 n = normalize ( gl_NormalMatrix * gl_Normal );

                                              // compute layers thicknesses
    diffuseThickness = (1.0 - pow ( max ( dot ( n, h ), 0.0 ), specPower ) ) * 
                       (one - diffuse) * max ( dot ( n, v ), 0.0 );
    unlitThickness   = (1.0 - max ( dot ( n, l ), 0.0 ) ) * (one - ambient);

    gl_Position     = MVP * gl_Vertex;
    gl_TexCoord [0] = gl_MultiTexCoord0;
}