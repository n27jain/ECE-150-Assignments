# include <iostream>
# include <stdlib.h>
#include <math.h> 

using namespace std;

int main( const int argc, const char* const argv[]){
	
	
	
	if (argc<2){
		cerr<<"Error: Insufficient arguments"<<endl;
		return -1;
	}
	

	float storage [argc-1];
	int i=0;
	
	while (i<argc-1){
		storage[i]=atof(argv[i+1]);
		i++;
	}
	
	i=0;
	float totalSum=0;
	float max=storage[0];
	float min=storage[0];
	
	
	while(i<argc-1){
			
		float in= storage[i];
		
		totalSum+=in;
			
		if(max<in)
			max=in;
			
		if(min>in)
			min=in;
			
		i++;
	}
	
	float average= totalSum/(argc-1);
	
	float newSum=0;//reset the total sum 
	i=0; // reset i counter
	while(i<argc-1){
			
		float in= storage[i];
		
		in=in-average;
		in=in*in;
		newSum=newSum+in;
		in=0;
		i++;
	}
	
	
	float psd=sqrt(newSum/(argc-1));

	float ssd= sqrt(newSum/(argc-2));
	
	
	
	
	cout<<"Number of floating-point numbers: " <<argc-1<<endl; 
	cout<<"Minimum floating-point number: " <<min<<endl; 
	cout<<"Average floating-point number: " <<average<<endl;	
	cout<<"Maximum floating-point number: " <<max<<endl;
	cout<<"Population standard deviation: " <<psd<<endl; 
	
	if(argc==2){
		cout<<"Sample standard deviation: infinity" <<ssd<<endl;
	}
	else{
		cout<<"Sample standard deviation: " <<ssd<<endl; 
	}
}