#include <iostream>
#include <iomanip>
#include <stdlib.h>
  
using namespace std;

int main( const int argc, const char* const argv[]){
	
	int size = argc-2;
	float dataset[size];
	int windowSize=atoi(argv[1]);
	int i=0;
	

	while (i<size){
		dataset[i]=atof(argv[i+2]);
		i++;
	}
	
	
	
	
	
	int newSize=size+windowSize-1;
		
		float NewData[newSize];
		float initial= dataset[0];
		i=0;
		
		while(i<windowSize-1){
			NewData[i]=initial;
			i++;
			
		}
		int x=0;
		while(i<newSize){
			NewData[i]=dataset[x];
			
			x++;
			i++;
			
		}
		
		
		
		
		i=0;
		while (i<newSize){
			cout << NewData[i]<< endl;
			i++;
		}
	
	int currentSample=5;
	
	int counter=currentSample+(windowSize-2);

	int q=counter-(windowSize-1);
	float min=NewData[q];


	while (q<=counter){

		float current2;

		current2= NewData[q];

		if(current2<min){
			min=current2;
		}	
		q++;
	}
	cout << min<< endl;
	
}