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

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool statistics(const float dataset[], const int size,
	   float& min, float& avg, float& max,
	   float& popSD, float& smplSD, float& mdn) {
	if(	   
	
	min= minimum(dataset, size);
	max= maximum(dataset, size);
	avg= average(dataset, size);
	popSD= popStdDev( dataset, size);
	smplSD= smplStdDev(dataset, size);
	mdn= median(dataset, size);
	return true;
  
}

float minimum(const float dataset[], const int size) {
	
	float min=dataset[0];
	
	return min;
	
}

float average(const float dataset[], const int size) {
	
	int i=0;
	float totalSum=0;
	float in =0;
	
	
	while(i<size){
			
		in= dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float out= totalSum/(size);
	
	return out;
}

float maximum(const float dataset[], const int size) {
	
	float max= dataset[size-1];
	return max;
}

float popStdDev(const float dataset[], const int size) {
	
	int i=0;
	float totalSum=0;
	float in=0;
	
	
	while(i<size){
			
		in=dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float average= totalSum/(size);
	
	float newSum=0;//reset the total sum 
	i=0; // reset i counter
	in=0;
	while(i<size){
			
		in= dataset[i];
		
		in=in-average;
		in=in*in;
		newSum=newSum+in;
		in=0;
		i++;
	}
	
	
	float psd=sqrt(newSum/(size));
	return psd;
}

float smplStdDev(const float dataset[], const int size) {
	
	int i=0;
	float totalSum=0;
	float in=0;
	
	
	while(i<size){
			
		in=dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float average= totalSum/(size);
	
	float newSum=0;//reset the total sum 
	i=0; // reset i counter
	in=0;
	
	while(i<size){
			
		in= dataset[i];
		
		in=in-average;
		in=in*in;
		newSum=newSum+in;
		in=0;
		i++;
	}
	float ssd=sqrt(newSum/(size-1));
	return ssd;
	
}

float median(const float dataset[], const int size) {
	float out;
	
	if(size%2==0){//is an even number
	
		int one=size/2;
		
		float current= dataset[one-1];
		
		float secondCurrent = dataset[one];
		
		out = (current+secondCurrent)/2;
	}
	else {
		int location = (size/2)+1;
		out= dataset[location];
	}
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

int main(const int argc, const char* const argv[]) {
	int size = argc-1;
	float dataset [size];
	float min;
	float avg;
	float max;
	float pop;
	float smpl;
	float med;

	
	int i=0;

	while (i<size){
		dataset[i]=atof(argv[i+1]);
		
		i++;
	}
	int x=0;
	float check;
	int index;
	
	while (x<size){
		
		check= dataset[x];
		int index= x;// We use this int to know which int to point to. It will point to the int in the array that is the lowest value. 
		int i=x+1;
		while (i<size){
			
			if (dataset[i]<dataset[index]){// if our checked int is less value then the current lowest value that the pointer is pointing to. 
				index=i;// Our pointer points to the current index unless a number in another index is lesser.	
			}	
			i++;
		}
		
		float tempo= dataset[index]; // temp is the temporary value that is the value of the lowest integer in the remaining array unchecked.
		dataset[index]=check;// The lowest pointer is replaced with the value that was initially  being checked. 
		dataset[x]=tempo;// The initially checked value is replaced with the lowest unchecked array value.
		x++;
		
	}
	

	if (statistics(dataset, size, min, avg, max, pop, smpl, med)) {
	cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << med << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << pop<< endl
	 << "Sample Standard Deviation:     " << smpl<< endl;
	}
	else
	cout << "Error: unable to compute statistics" << endl;

	return 0;
}

#endif
