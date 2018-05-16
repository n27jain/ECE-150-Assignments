#include  <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

using namespace std;

int main( const int argc, const char* const argv[]) {
	int x;
	unsigned int y;
	
	x=atoi(argv[1]);
	y=x;
	unsigned int calc= (sizeof(x)*8)-1;// sizeof counts number of bytes(4) times 8 gives us # of bits -1 tells us number of translation.
	calc= x>>calc;// shift binary 31 to the right.
	
	calc =calc&1;// if we signed int, then we will not be able to get rid of the first 1.
	
	unsigned int second= (sizeof(y)*8)-1;// sizeof counts number of bytes(4) times 8 gives us # of bits -1 tells us number of translation.
	
	second= y>>second;// shift binary 31 to the right.
	
	std::cout<<"The value of x is "<< x <<endl;
	std::cout<<"The value of y is "<< y <<endl;
	std::cout<<"The most significant bit of x is "<< calc <<endl;
	std::cout<<"The most significant bit of y is "<< second <<endl;
	
	
	//10
	std::cout<<"Type: \"short int\";"<< " Size: "<< sizeof(short int)<<" bytes;"<< " Minimum value: " <<SHRT_MIN<< " Maximum value: "<< SCHAR_MAX <<endl; 
	
	std::cout<<"Type: \"unsigned short int\";"<< " Size: "<< sizeof(unsigned short int)<<" bytes;"<< " Minimum value: " <<0<< " Maximum value: "<< USHRT_MAX <<endl; 
	
	std::cout<<"Type: \"signed char\";"<< " Size: "<< sizeof(signed char)<<" bytes;"<< " Minimum value: " <<CHAR_MIN<< " Maximum value: "<< CHAR_MAX <<endl; 

	std::cout<<"Type: \"unsigned char\";"<< " Size: "<< sizeof(unsigned char)<<" bytes;"<< " Minimum value: " <<0<< " Maximum value: "<< UCHAR_MAX <<endl; 
	
	std::cout<<"Type: \"int\";"<< " Size: "<< sizeof(int)<<" bytes;"<< " Minimum value: " <<INT_MIN<< " Maximum value: "<< INT_MAX <<endl; 
	
	std::cout<<"Type: \"unsigned int\";"<< " Size: "<< sizeof(unsigned int)<<" bytes;"<< " Minimum value: " <<0<< " Maximum value: "<< UINT_MAX <<endl; 
	
	std::cout<<"Type: \"long int\";"<< " Size: "<< sizeof(long int)<<" bytes;"<< " Minimum value: " <<LONG_MIN<< " Maximum value: "<< LONG_MAX <<endl; 
	
	std::cout<<"Type: \"unsigned long int\";"<< " Size: "<< sizeof(unsigned long int)<<" bytes;"<< " Minimum value: " <<0<< " Maximum value: "<< ULONG_MAX <<endl; 
	
	std::cout<<"Type: \"long long int\";"<< " Size: "<< sizeof(long long int)<<" bytes;"<< " Minimum value: " <<LLONG_MIN<< " Maximum value: "<< LLONG_MAX <<endl; 
	
	std::cout<<"Type: \"unsigned long long int\";"<< " Size: "<< sizeof(unsigned long long int)<<" bytes;"<< " Minimum value: " <<0<< " Maximum value: "<< ULLONG_MAX <<endl; 
	
	
	
	std::cout<<"Type: \"float\";"<< " Size: "<< sizeof(float)<<" bytes;"<< " Minimum value: " <<FLT_MIN<< " Maximum value: "<< FLT_MAX <<endl; 
	
	std::cout<<"Type: \"double\";"<< " Size: "<< sizeof(double)<<" bytes;"<< " Minimum value: " <<	DBL_MIN<< " Maximum value: "<< 	DBL_MAX <<endl; 
	
	std::cout<<"Type: \"long double\";"<< " Size: "<< sizeof(long double)<<" bytes;"<< " Minimum value: " <<LDBL_MIN<< " Maximum value: "<< LDBL_MAX <<endl; 
	
	return 0;
	
	
}
	