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

float dragaccleration( float k, float v, float m){
	
	float fdrag= k*v*v;
	float accleration = fdrag/m;
	return accleration;

}
float d(float v, float t, float dX){

		float d= dX+v*t;
		
		return d;
	
}
float newV(float v, float a, float t){
	
		float newV= v+a*t;
		return newV;

}

float projectilePathYTime(float dY, float step, float vY, float k, float m){
	
	float t=0;
	t+=step;
	float dy=0;
	int counter=1;
	while (dy>dY&&counter<100000){
		
		dy= d(vY, t, dy);
		float a= dragaccleration(k,vY,m);
		vY=newV(vY, -(a+9.8), step);
		t+=step;
	counter++;
	}
	
}


/*bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float step, const float k,
              const float t, const float b, const float w, float& v) {
	
	float time=t;
	
	if (m<=0||theta>270||h<0||w<=0||b<=0){
		return false;
	}
	
	float dX=0;
	float setV=1;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
	float rad=0;
	rad= (theta*0.0174532925);

	float dY= t-h;
	float dYTraveled=0;
	/*
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
	
		
		rad= (theta*0.0174532925);
		
		float vX= setV*(cos(rad));
		float vY= setV*(sin(rad));
		float ay1= dragaccleration(k,vY, m);
		float ax1= dragaccleration(k,vX,m);
		
		
		while (dX<d){
			
		setV=setV*10;// we will set a high velocity and keep increasing it by 10 until we surpass the location of the target.
		
		
		ay1= dragaccleration(k,vY, m);
		ax1= dragaccleration(k,vX,m);
		
		
		time = time+step;
		dX= d(vX,-ax1,time,dX);
		dYTraveled= d(vY, -(ay1+9.8), time, dYTraveled);
		vX= newV(vX, -ax1, time);
		vy= newV(vY, -ay1+9.8, time);
		
		
		}
		
		float velocity= bisectionHelperVelocity(0,setV , 0,  dY, d,rad);
		
		
		if (velocity!=-1){
			
			v=velocity;
			
			return true;
		
		}
		else {
			return false;
		}
	
				  
				  
  return false;

}
*/		

#ifndef MARMOSET_TESTING
int main() {
	
  // Some test driver code here ....
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 30;
  float w = 30;
  float m = 1;
  float step = 0.1;
  float k = 0.5;
  float theta = 45; // Angle in degrees;
  float v = 25;	
  
  float rad = (theta*0.0174532925);
  float vY= v*(sin(rad));
  float time= projectilePathYTime(t-h, step, vY, k, m);
  cout<<time<<endl;
  /*cout << endl << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, step, k, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity" << endl << endl;
  }
  */  
  return 0;
}
#endif
