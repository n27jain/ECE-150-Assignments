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

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
	//float h;   // b1 height
	//float t; // target height
	// float b // distance to building;	
	//float v;   // velocity
	//float theta; // angle
	//float m;// max height

	//float w; //width 

	//REMAINING TESTS: HIT NEGATIVE BUILDING.
	//HIT INSIDE WALL
	//THROW AT NEGATIVE ANGLE
	// 
	
	
	
	
	float rad= (theta*0.0174532925);
	float vX= (v*cos(rad));
	float vY= (v*sin(rad));
	

	float dY= t-h;
	
	float timeToFall=0;

	if (v<0||m<=0||theta>270||h<0||w<=0||b<=0){
		return false;
	}
	
	else if (theta==90||v==0||theta==-90){
		destX=0;
		destY=h;
		
		
	return true;
	}
	
	float time= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(-1*dY)))))/-9.8;
	float dX=vX*time;
	
	if (theta>90){		// the projectile goes backwards
		
		float testime= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(h)))))/-9.8;
		destX=vX*testime;
		destY=0;
	
	}
	else if (theta>-90||theta<90){// projectile goes forwards
		
		if (theta<0||dY>0){
			
			time= b/vX;
			dY=vY*time+(0.5*(-9.8)*(time*time));
			
			if (dY>(h*-1)){
				destX=b;
				destY= h+dY;
			}
			
			else{
				destY=0;
				float testime= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(h)))))/-9.8;
				destX=vX*testime;
			}
		}
		else if (dX>=b&&dX<=(b+w)){
			destX=dX;
			destY=t;
		}
		
		else if(dX<b||dX>(b+w)){
			

			float testime= (-1*(vY)-(sqrt((vY*vY)-(4*(-4.9)*(h)))))/-9.8;
			
			float newDx=testime*vX;
			
			if (newDx<=b||dX>(b+w)){// if it hits the wall at the bottom or before it.
				destX=newDx;
					
				destY=0;
				
				
			}
			else if (newDx>b){
				float newTime=b/vX;
				destX=b;
				destY= h+vY*(newTime)+(0.5*(-9.8)*(newTime*newTime));
				
				
			}
			
		}
		
	}
	return true;


// when b2 is lower

	
	
  // Your code here ...
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....

  float h = 10;
  float t = -5;
  //height
  
  float v = 10;
  float theta = 25;        // Angle in degrees; will need to be converted by function
  //velocities
 
  //useless shits
  float m = 10;
  float d = 1;
  
  //distance to cover
  float b = 10;
  float w = 1000;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
