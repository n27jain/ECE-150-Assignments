//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
    
	return -3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize, int limit );
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize, int limit){
	
	limit++;
	
	float a= f(left);

	float b= f(right);
	
	float mid=(left+right)/2;//
	
	float c= f(mid);

	float currentInter= fabs(right-left);
	
	
	if (a>0&&b>0||a<0&&b<0||c != c||a!=a||b!=b){
		return std::numeric_limits<float>::quiet_NaN();
	}
	else if (limit>10000){
		return mid;
	}
	else if ((fabs(c))<=precision&&currentInter<=minIntervalSize){
		return mid;
	}
	else if (c<0&&a<0){
		mid= bisectionHelper(mid,right,precision,minIntervalSize,limit);
	}
	else if (c>0&&b>0){
		mid= bisectionHelper(left,mid,precision,minIntervalSize,limit);
	}
	else if (c>0&&a>0){
		mid= bisectionHelper(mid,right,precision,minIntervalSize,limit);
	}
	else if (c<0&&b<0){
		mid= bisectionHelper(left,mid,precision,minIntervalSize,limit);
	}
	
	//*/
	return mid;
	
}

float bisection(const float left, const float right,
		const float precision, const float minIntervalSize) {
			
	if(precision<=0||minIntervalSize<=0||left>=right||(f(left)*f(right)>0)){
		return std::numeric_limits<float>::quiet_NaN();
	}
	
	float out= bisectionHelper(left, right, precision, minIntervalSize,0);
	return out;
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
  
  
	float left=-0.5;
	float right= 20;
	float precision= 0.01;
	float minIntervalSize=0.5;
	
	float out =bisection(-11, 10, 0.00000001, 0.00000001);
	
	cout<<out<<endl;

  

  return 0;
}

#endif
