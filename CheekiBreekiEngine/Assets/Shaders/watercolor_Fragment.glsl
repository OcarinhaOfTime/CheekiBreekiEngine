uniform sampler2D _mainText;
uniform sampler2D _paperText;
uniform sampler2D _noiseText;
uniform float _mainText_width;
uniform float _mainText_height;

uniform float edgeThickness;
uniform float wobbling;
uniform float turbulenceFlow;
uniform float pigmentDispersion;
//varying vec3 v_normal;
varying vec2 v_uv;
varying vec3 v_normal;


//edge detection functions
float threshold(in float thr1, in float thr2 , in float val) {
 if (val < thr1) {return 0.0;}
 if (val > thr2) {return 1.0;}
 return val;
}

// averaged pixel intensity from 3 color channels
float avg_intensity(in vec4 pix) {
 return (pix.r + pix.g + pix.b)/3.;
}

vec4 get_pixel(in vec2 coords, in float dx, in float dy) {
 return texture2D(_mainText,coords + vec2(dx, dy));
}

// returns pixel color
float IsEdge(in vec2 coords){
  float dxtex = 1.0 / _mainText_width /*image width*/;
  float dytex = 1.0 / _mainText_height /*image height*/;
  float pix[9];
  int k = -1;
  float delta;

  // read neighboring pixel intensities
  for (int i=-1; i<2; i++) {
   for(int j=-1; j<2; j++) {
    k++;
    pix[k] = avg_intensity(get_pixel(coords,float(i)*dxtex,
                                          float(j)*dytex));
   }
  }

  // average color differences around neighboring pixels
  delta = (abs(pix[1]-pix[7])+
          abs(pix[5]-pix[3]) +
          abs(pix[0]-pix[8])+
          abs(pix[2]-pix[6])
           )/4.;

  return threshold(0.25 ,0.4,clamp(edgeThickness * delta,0.0,1.0));
}

//==============================

void main()
{
	vec2 wobbleUV = (v_uv + texture2D(_paperText, v_uv).xy * wobbling) - wobbling;
	wobbleUV.x = 1 - wobbleUV.x;
    vec4 color = texture2D(_mainText, wobbleUV);

	float turbulentFlowIntensity = texture2D(_noiseText, wobbleUV).x;
	float _turbulentFlow = 1 + turbulenceFlow * (turbulentFlowIntensity - 0.5);

	float pigmentDispersionIntensity = texture2D(_paperText, wobbleUV).g;
	float _pigmentDispersion = 1 + pigmentDispersion * (pigmentDispersionIntensity - 0.5);

	float edgeIntensity = IsEdge(wobbleUV);
	vec4 edgeColor = -vec4(edgeIntensity, edgeIntensity, edgeIntensity, 1);

	gl_FragColor = color * _turbulentFlow * _pigmentDispersion + edgeColor;
	gl_FragColor.a = texture2D(_mainText, v_uv).a;
  }