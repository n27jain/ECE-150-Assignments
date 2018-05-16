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

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {
  
	if (a<=0||b<=0){
		return -1;
	}
	int GCD=0;

	if (a==b){
		GCD=a;
	}
	else if (a<b){
		if(b%a==0){
			GCD=a;
		}
		else{
			int x=a/2;// divide the smaller number by two. Any number greater thanits half cannot be a divisor.
	
			while(x>0){
				if(b%x==0&&a%x==0){// is this is a divisor
					GCD=x;
					x=-1;// End the while loop now.
				}
				x--;// Reduce the potential factor by one. As we go down, 
			}
		}
	}
	else if (a>b){
		if(a%b==0){
			GCD=b;
		}
		else{
			int x=b/2;// divide the smaller number by two. Any number greater thanits half cannot be a divisor.
			
			while(x>0){
				if(a%x==0&&b%x==0){// is this is a divisor
					GCD=x;
					x=-1;// End the while loop now.
				}
				x--;// Reduce the potential factor by one. As we go down, 
			}
		}
	}
	return GCD;	
}

int leastCommonMultiple (const int a, const int b) {
	
	if (a<=0||b<=0){
		return -1;
	}
	
	int GCD=greatestCommonDenominator(a,b);
	int LCM=(a/GCD)*b;
	
	if (a==((LCM/b)*GCD)){
		
	
	return LCM;
	}
	else{
		return -2;
	}
  
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

int main(const int argc, const char* const argv[]) {

  if (argc < 3) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
