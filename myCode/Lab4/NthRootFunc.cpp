//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.

//
#include <limits>

float power (float base, int x){
	float out=1;
	int counter=x;
	
	while (counter>0){
		out= out*base;
		counter--;
	}
	
	return out;
}

float NthRoot(const float S, const int N, const float precision) {

		float s=S;
		int n=N;
		float p=precision;
		float R=1;
		float done;
		float checker;
		
		if ((s<0&&(n%2==0))||n<2||p<=0){
		
		return std::numeric_limits<float>::quiet_NaN();
		}
		else if (s==0){
			R=0;
			return R;
		}
		
		
		int x=0;
		do{
			int counter=n-1;
			float ReR= R; // This will be the R that is not modified.
			float fractionDone= power(R,counter);
	
			R=((n-1)*ReR/n);
			
			R= R+(s/(n*fractionDone));
			
			done=power(R,n);
		
			checker=((s-done)/s);
			
			if (checker<0)
				checker=checker*-1;
		
			x++;
		}while (checker>p&&x<4000);
		
		return R;
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
  
  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else{
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl; 
  }
  return 0;
}

#endif
