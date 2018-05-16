#include  <iostream>
#include <stdlib.h>

  
using namespace std;

int main( const int argc, const char* const argv[]){
	
	int counter= argc;
	
	
	if (argc<3){
		cerr<<"Unable to compute statistics over data set because there are less then 2 arguments. "<<endl;
	}
	
	else{
		
	float totalSum=atof(argv[1]);
	float max=atof(argv[1]);
	float min=atof(argv[1]);
	
	
		while(counter>2){
			
		float in= atof(argv[counter-1]);
		
			totalSum+=in;
			
			if(max<in)
				max=in;
			
			if(min>in)
				min=in;
			
		counter-=1;	
		}
	float average= totalSum/(argc-1);
		
	cout<<"Number of floating-point numbers: " <<argc-1<<endl; 
	cout<<"Minimum floating-point number: " <<min<<endl; 
	cout<<"Average floating-point number: " <<average<<endl;	
	cout<<"Maximum floating-point number: " <<max<<endl; 
	
	}
	return 0;
	
}