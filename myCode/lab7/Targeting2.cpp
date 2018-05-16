//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN() 
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b, 
							 const float w, float& theta);
							 
bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float t, const float b, 
							const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b, 
							 const float w, float& theta) {
								 
								 
	// Your code here...
	
	
	
}

float bisectionHelperVelocity(const float left, const float right, int limit, const float dY, const float d, float rad){
		
	limit++;
	
	float vXLeft= left*(cos(rad));
	float vYLeft= left*(sin(rad));
	
	float vXRight= right*(cos(rad));
	float vYRight= right*(sin(rad));
	
	float timeL= (-1*(vYLeft)-(sqrt((vYLeft*vYLeft)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float timeR= (-1*(vYRight)-(sqrt((vYRight*vYRight)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float a=timeL*(vXLeft);
	
	float b=timeR*(vXRight);
	
	float mid=(left+right)/2;//
	
	float vXMid= mid*(cos(rad));
	float vYMid= mid*(sin(rad));
	
	float timeMid= (-1*(vYMid)-(sqrt((vYMid*vYMid)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float c=timeMid*(vXMid);

	
	
	if (limit>10000){
		return -1;
	}
	else if (c<=d&&c>=(d*0.99)){ // if the distance lies between 1 percent accuracy 
		return mid;
	}
	if (c>d){
		mid= bisectionHelperVelocity(left,mid,limit,dY,d,rad);
	}
	else if (c<d){
		mid= bisectionHelperVelocity(mid,right,limit,dY,d,rad);
	}
	return mid;

}

	


bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float t, const float b, 
							const float w, float& v) {
	
	if (m<=0||theta>270||h<0||w<=0||b<=0){
		return false;
	}
		
	
	float dY= t-h;
	
	
	float dX=0;
	float setV=1;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
	float rad=0;
	
	while (dX<d){
		
	rad= (theta*0.0174532925);
	setV=setV*10;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
	
	
	float vX= setV*(cos(rad));
	float vY= setV*(sin(rad));
	
	
	
	
	float time= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	dX=vX*time;
	
	}
	
	float velocity= bisectionHelperVelocity(0,setV , 0,  dY, d,rad);
	
	
	if (velocity!=-1){
		
		v=velocity;
		
		return true;
	
	}
	else {
		return false;
	}


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

  float theta = 45; // Angle in degrees;
  float v = 25;	
  
  
  
  /*
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 70;
  float w = 30;
  float m = 1;

  float theta = 73.61; // Angle in degrees;
  float v = 25;	
*/
  cout << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity\n\n";
  }

  cout << "Given initial velocity: " << v << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
    cout << "required angle: " << theta << endl << endl;
  }
  else {
    cout << "cannot calculate the angle\n\n";  
  }
    
  return 0;
}
#endif
