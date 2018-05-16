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
float bisectionHelperAngle (float minAng, float maxAng, float limit, float dY, float d, float velocity ){
	
	limit++;
	
	float vXLeft= velocity*(cos(minAng));
	float vYLeft= velocity*(sin(minAng));
	
	float vXRight= velocity*(cos(maxAng));
	float vYRight= velocity*(sin(maxAng));
	
	float timeL= (-1*(vYLeft)-(sqrt((vYLeft*vYLeft)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float timeR= (-1*(vYRight)-(sqrt((vYRight*vYRight)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float a=timeL*(vXLeft);
	
	float b=timeR*(vXRight);
	
	float mid=(minAng+maxAng)/2;//
	
	float vXMid= velocity*(cos(mid));
	float vYMid= velocity*(sin(mid));
	
	float timeMid= (-1*(vYMid)-(sqrt((vYMid*vYMid)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float c=timeMid*(vXMid);
	
	if (limit>10000){
		return -1;
	}
	else if (c<=(d+d*0.01)&&c>=(d*0.99)){ // if the distance lies between 1 percent accuracy 
		mid=mid/0.0174532925;
		
		return mid;
	}
	else if (c>d){
		mid= bisectionHelperAngle(minAng,mid,limit,dY,d,velocity);
	}
	else if (c<d){
		mid= bisectionHelperAngle(mid,maxAng,limit,dY,d,velocity);
	}
	
	

}

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b, 
							 const float w, float& theta) {
	if (m<=0||theta>270||h<0||w<=0||b<=0){
		return false;
	}
	
	float dY= t-h;
	
	if(t<0){
		
		float minAng=asin((9.8*b*b/(b*v*v)));
		float maxAng=asin((9.8*(b+w)*(b+w))/((b+w)*v*v));
		
		
		theta= bisectionHelperAngle( minAng,maxAng,0,dY,d,v);
		
		
			if (theta!=-1){
			
				return true;
		
			}
			else {
				return false;
			}
	}
	
	
	float vX= v*(cos(45*0.0174532925));
	float vY= v*(sin(45*0.0174532925));
	
	
	
	
	float time= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(-1*dY)))))/-9.8;
	
	float dX=vX*time;
	
	if (dX<=(d+d*0.01)&&dX>=d*0.99){
		theta=45;
		return true;
	}
	else if (dX<d*0.99){ // if out max range is still too short
		
		return false;
	}
	else if (dX>(d*0.99)){
		
		theta= bisectionHelperAngle((90*0.0174532925),(45*0.0174532925),0,dY,d,v);
		
		if(theta==-1){
			return false;
		}
		else{
			return true;
		}
	}
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

	if(vYMid*vYMid-(4*(-4.9)*(-1*dY))<0){
		c=0;
	}
	
	if (limit>10000){
		return -1;
	}
	else if (c<=(d+d*0.01)&&c>=(d*0.99)){ // if the distance lies between 1 percent accuracy 
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
	
	float dX=0;
	float setV=1;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
	float rad=0;
	rad= (theta*0.0174532925);

	float dY= t-h;
	
	if(t<0){
		
		float vMin= sqrt(-4.9*(b*b)/(h-(tan(rad)*b*(cos(rad)*cos(rad)))));// find the velocity nessessary to reach the edge of the trench
		float vMax= sqrt(-4.9*((b+w)*(b+w))/(h-(tan(rad)*(b+w)*(cos(rad)*cos(rad)))));// find the velocity nessary to far end of the trench.
		
		float velocity= bisectionHelperVelocity(vMin,vMax , 0,  dY, d,rad);
		
			if (velocity!=-1){
			
				v=velocity;
				
				return true;
		
			}
			else {
				return false;
			}
	}
	else{
		
		
		while (dX<d){
			
		rad= (theta*0.0174532925);
		setV=setV*10;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
		
		
		float vX= setV*(cos(rad));
		float vY= setV*(sin(rad));
		
		
		if(vY*vY-(4*(-4.9)*(-1*dY))<0){
			dX=-100;
		}
			else{
			
			float time= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(-1*dY)))))/-9.8;
			
			dX=vX*time;
				}
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

  cout << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity\n\n";
  }
  
 
  v = 25;
  
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
