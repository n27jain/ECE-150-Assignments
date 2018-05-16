//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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

bool stringToInt(const char input[], int& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//
enum state{ SIGN, NUM, /*EXPO, DECI,*/ ENDSTATE, ERRORSTATE};

bool stringToIntHelp(const char input[], int& value, state in=SIGN, int i=0, bool plusOrMinus=true) {
  // Your code here ...
	
	
	switch(in){
		case SIGN:
			
			if (i==0&& input[i]=='-'){
				plusOrMinus=false;
				return stringToIntHelp(input, value, NUM, i+1,plusOrMinus);
			}
			else if (i==0&& input[i]=='+'){
				plusOrMinus=true;
				return stringToIntHelp(input, value, NUM, i+1, plusOrMinus);
			}
			else if (input[i]>=48&&input[i]<=59){
				return stringToIntHelp(input, value, NUM, i, plusOrMinus);
			}
			else if (input[i]=='\0'){
				return stringToIntHelp(input, value, ENDSTATE, i, plusOrMinus);
			}
			else if (value<0) {
				return false;
			}
			else{
				return false;
			}
			
			
		case NUM:
			if (input[i]>=48&&input[i]<=59){
			
				int current=input[i]-48;
				
				int work=value*10+current;
				
				
				if ((work-current)/10==value){
					value=work;
				}
				else{
					return false;
				}
				return stringToIntHelp(input, value, NUM, i+1, plusOrMinus);
		
			}
			else if (input[i]=='\0'){
				return stringToIntHelp(input, value, ENDSTATE, i, plusOrMinus);
			}
			else{
				return false;
			}
			
		case ENDSTATE:
		
		
			if (value<0){
				return false;
			}
			else if (plusOrMinus==false){
				value=value*-1;
				
			}
			return true;
			
		
	}
	
}

bool stringToInt(const char input[], int &value){
	
	return stringToIntHelp(input,value,SIGN,0, true); 
	
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
  
	int argv1;
	char input[4]={'-','1','3','\0'};
	
	if (argc < 2) {
		cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
	return -1;
	}

	if (stringToInt(argv[1],argv1)) 
		cout << "argv[1] is an int with value: " << argv1 <<endl;
	else
		cout << "argv[1] is not an int." << endl;
	return 0;
}

#endif
