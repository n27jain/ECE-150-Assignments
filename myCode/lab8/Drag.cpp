//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <math.h>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN() 
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
							 
bool hitTargetGivenAngle (const float h, const float m, const float theta, 
              const float d, const float step, const float k,
              const float t, const float b, const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
float calculate(float h, float m, float theta, float d, float step, float k, float t, float b, float w, float v, float& qwerty) {
		
	float rad = (theta*0.0174532925);
	
	float vX = v*cos(rad);
	float vY = v*sin(rad);
	
	
	float start = v;
	
	float dY = h;
	float dX= 0;
	
	bool turn = true;
	
	while(turn == true) {
		//cout << h << "    " << t << "    " << vY << endl;
		if (h <= t && vY <= 0) {
			qwerty = dX - d;
			turn = false;
			
		}
		h += vY * step;
		dX += vX * step;
		vY -= ((vY*v*k)/m)*step + 9.8*step;
		vX -= ((vX*v*k)/m)*step;
		
		v = sqrt(pow(vX,2)+pow(vY,2));
		
	}
	
	
		return qwerty;
	
	
	
	
	}
		


bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float step, const float k,
              const float t, const float b, const float w, float& v) {
	
	float time=t;
	
	if (m<=0||theta>270||h<0||w<=0||b<=0||k < 0 ||d <= 0|| step <= 0 ){
		return false;
	}

	float rad = (theta*0.0174532925);
	float vMin;
	float vMid;
	float vMax;
	
	v = (t-h)-tan(rad)*d;
	
	
	v= v*pow(cos(rad),2);
	
	
	v= v/((-4.9)*pow(d,2));
	
	
	v = 1/v;
	v = sqrt(v);
	
	
	vMax = 1000;
	vMin = 0;
	
	if(k == 0) {
		return true;
		
	}
	
	else{
		v = 50;
		float qwerty = 0;
		int count = 0;
		
		//float ay, ax;
		
		while((abs(calculate(h, m, theta, d, step, k, t, b, w, v, qwerty)) > step) && (count <= 1000)) {
			if(qwerty > 0) {
				vMax = v;
			}else if(qwerty < 0) {
				vMin = v;
			}
			v = (vMax - vMin)/2 + vMin;
			count++;
			
		}
		
	}
		
	
	return true;
}







#ifndef MARMOSET_TESTING
int main() {
	
   // Some test driver code here ....
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 30;
  float w = 30;
  float m = 1;
  float step = 0.01;
  float k = 0.005;
  float theta = 89; // Angle in degrees;
  float v = 13;

  cout << endl << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, step, k, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity" << endl << endl;
  }
    
  return 0;
}
#endif
