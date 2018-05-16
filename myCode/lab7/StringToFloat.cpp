//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#include <limits>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove



bool stringToFloat(const char input[], float& value);
enum state{ SIGN, NUM, EXPO, DECI, ENDSTATE, REMAINDER, NUMREMAINDER};
//////////////////////////////////////////////////////////////
//
// Your code here ...
bool stringToFloatHelp(const char input[], float& value, float& valueAfterDecimal, int numberAfter, state in, int i, bool plusOrMinus, int decimalMover, 

int decimalCount, bool exponent, bool exponentSign, int charsAllowed) {
		
		switch(in){
		case SIGN:
			
			if (i==0&& input[i]=='-'){
				plusOrMinus=false;
				charsAllowed++;
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUM, i+1,plusOrMinus, decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			else if (i==0&& input[i]=='+'){
				plusOrMinus=true;
				charsAllowed++;
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUM, i+1, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			else if (input[i]>=48&&input[i]<=59){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUM, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			else if (input[i]=='.'){
				
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, DECI, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			else if (input[i]=='\0'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, ENDSTATE, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			else if (input[i]=='e'||input[i]=='E'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
			}
			
			else if (value<0) {
				return false;
			}
			else{
				return false;
			}
			break;
			
		case NUM:
		
			if (input[i]>=48&&input[i]<=59){
				
				float current=input[i]-48;
				
				if (value<=(std::numeric_limits<float>::max())/10){
					
					float work=value*10+current;
					value=work;
	
				}
				else{
					return false;
				}
			
				
			
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUM, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign , charsAllowed);
		
			}
			else if (input[i]=='-'||input[i]=='+'){
				
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, SIGN, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			
			}
			else if (input[i]=='.'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, DECI, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='\0'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, ENDSTATE, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='e'||input[i]=='E'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else{
				return false;
			}
			break;
			
		case DECI:
		
			charsAllowed++;
			decimalCount++;
			if(decimalCount>=2||(!(input[i+1]>=48&&input[i+1]<=59))){
				
				return false;
			}
			else{
				
				stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, REMAINDER, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			
			break;
			
		case REMAINDER:
			
			if (input[i]>=48&&input[i]<=59){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUMREMAINDER, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='.'){ // we cant have more than one decimal point
				return false;
			}
			else if (input[i]=='\0'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, ENDSTATE, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='e'||input[i]=='E'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else{
				return false;
			}
			
			break;
			
		case NUMREMAINDER:
		

			if (input[i]=='0'){// do nothing but increade numberAfter
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter+1, NUMREMAINDER, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
				
			}
			else if (input[i]>=48&&input[i]<=59){
				
				numberAfter++;
				
				float tenPosition=1;
				
				for (int i= numberAfter; i>0;i--){
					tenPosition=tenPosition*10;
					
				}
				
				float current=input[i]-48;
				if(valueAfterDecimal>=(std::numeric_limits<float>::min())*tenPosition){
				
				float work=valueAfterDecimal+current/(tenPosition);
					valueAfterDecimal=work;
				}
				
			
			else{
					
				return false;
			}
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, NUMREMAINDER, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
				
			}
			else if (input[i]=='.'){// we cant have a decimal after a decimal
			
				return false;
			}
			else if (input[i]=='e'||input[i]=='E'){
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i, plusOrMinus,decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='\0'){
				
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, ENDSTATE, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else{
				
				return false;
			}
			
			break;
			
		case EXPO:
			if ((input[i]=='e'||input[i]=='E')&&exponent==true){ 
				return false;
			}
			else if ((input[i]=='e'||input[i]=='E')&& (!(input[i-1]>=48&&input[i-1]<=59))){ // the value before it is not a number
				return false;
			}
			else if (input[i]=='.'&&exponent==true){
				return false;
			}
			else if ((input[i]=='e'||input[i]=='E')&&(input[i+1]!='\0')){
				charsAllowed++;
				exponent=true;
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]>=48&&input[i]<=59&&exponent==true){
				
				int current=input[i]-48;
				
				int work=decimalMover*10+current;
				
				
				if ((work-current)/10==decimalMover){
					decimalMover=work;
				}
				else{
					return false;
				}
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			
			}
			else if ((input[i]=='+'||input[i]=='-')&&(input[i-1]=='e'||input[i-1]=='E')){
				
				charsAllowed++;
				if (input[i]=='-'){
					exponentSign=false;
				}
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, EXPO, i+1, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else if (input[i]=='\0'){
				
				return stringToFloatHelp(input, value,valueAfterDecimal, numberAfter, ENDSTATE, i, plusOrMinus, decimalMover, decimalCount, exponent, exponentSign, charsAllowed);
			}
			else{
				return false;
			}
			
		
			break;
			
		case ENDSTATE:
		
			
			if (value<0||valueAfterDecimal<0){
				return false;
			}
			else if (plusOrMinus==false){
				valueAfterDecimal=valueAfterDecimal*-1;
				value=value*-1;
			}
			if (valueAfterDecimal!=0){
				
				value=value+valueAfterDecimal;
				
			}
			if (exponent==true){
				if (exponentSign==false){
					decimalMover*=-1;
				}
				
				
				if(decimalMover>=0){
					
					for (int i=0; i<decimalMover;i++){
					
						if(value<=(std::numeric_limits<float>::max())/10){
							float work=value*10;
							value=work;
						}
						else{
							return false;
						}	
					}
				}
				else if (decimalMover<0){
					
					for (int i=0; i>decimalMover;i--){
						
						
						if(value>=(std::numeric_limits<float>::max())*10){
							float work=value/10;
							value=work;
						}
						
						
				
					}
				}
			
			}
			
			return true;
			
			break;	
		
	}
		
}	

bool stringToFloat(const char input[], float& value) {
	
	float valueAfterDecimal=0;
	
	
	int decimalMover=0;
	
	return stringToFloatHelp(input,value,valueAfterDecimal, 0, SIGN,0,true, decimalMover, 0, false, true,0); 
	
	
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
	
  
  // Some test driver code here ....
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1)) 
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
