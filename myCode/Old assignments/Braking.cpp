#include  <iostream>
#include <stdlib.h>


using namespace std;

int main( const int argc, const char* const argv[]) {
	
	float one= atof(argv[1]);
	
	float two= atof(argv[2]);
	
	float ac= one*one; // squared
	
	ac/=2;
	ac/=two;

	float time= one/ac;
	
	std::cout<<"Initial car velocity: " <<one << " m/s" <<endl;
	std::cout<<"Distance to obstacle: " <<two << " m" <<endl;
	std::cout<<"Minimum deceleration: " <<ac<< " m/s/s" <<endl;
	std::cout<<"Maximum stopping time: " <<time<< " s" <<endl;
	
	
	
	
	
	return 0;
	
	
}
	