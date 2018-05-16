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

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn) {
			
		if(windowSize<=0||size<1){
			return -1;
		}
		else if(windowSize==1||windowSize>size){
			return 1;
		}
		
		
		int newSize=size+windowSize-1;
		
		float NewData[newSize];
		float initial= dataset[0];
		int i=0;
		
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
		
		float m;
		
		SWMaximum(NewData, newSize, currentSample, windowSize, max);
		
		SWMinimum(NewData, newSize, currentSample, windowSize, min);
		SWAverage(NewData, newSize, currentSample, windowSize, avg);
		SWMedian(NewData, newSize, currentSample, windowSize, mdn);
		SWSmplStdDev(NewData, newSize, currentSample, windowSize, smplSD);
		
		return 0;

}

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum) {
	
	int counter=currentSample+1+(windowSize-2);

	int q=counter-(windowSize-1);
	float min=dataset[q];


	while (q<=counter){

		float current2;

		current2= dataset[q];

		if(current2<min){
			min=current2;
		}	
		q++;
	}
	
	minimum=min;
	return 0;
}

int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average) {
	
	int counter=currentSample+1+(windowSize-2);

	int q=counter-(windowSize-1);
	float totalSum=0;
	float av=0;


	while (q<=counter){
		
		float current= dataset[q];
		totalSum+=current;
		q++;
	}
	av=totalSum/(windowSize);
	average=av;
	return 0;
}

int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum) {
	
	int counter=currentSample+1+(windowSize-2);

	int q=counter-(windowSize-1);
	float maxi=dataset[q];


	while (q<=counter){

		float current2;

		current2= dataset[q];
		
		if(current2>maxi){
			maxi=current2;
		}	
		q++;
	}
	
	maximum=maxi;
	return 0;
}

int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev) {
			 
	int counter=currentSample+1+(windowSize-2);

	int q=counter-(windowSize-1);
	float totalSum=0;
	float av=0;


	while (q<=counter){
		
		float current= dataset[q];
		totalSum+=current;
		q++;
	}
	av=totalSum/(windowSize);
	
	float newSum=0;//reset the total sum 
	int z=counter-(windowSize-1);
	float current=0 ;
	
	
	
	while(z<=counter){
			
		current= dataset[z];
		
		current=current-av;
		current=current*current;
		newSum=newSum+current;
		current=0;
		z++;
	}
	/*cout<<"number of z"<<z<<endl;*/
	
	float ssd=sqrt(newSum/(windowSize-1));
	smplStdDev=ssd;
	return 0; 
}

int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median) {
			 
	int counter=currentSample+1+(windowSize-2);

	int q=counter-(windowSize-1);
	
	float DataSelect[windowSize];
	int i=0;
	while (q<=counter){
		DataSelect[i]=dataset[q];
		q++;
		i++;
		
	}
	
	int x=0;
	float check;
	int index;
	
	while (x<windowSize){
		
		check= DataSelect[x];
		int index= x;// We use this int to know which int to point to. It will point to the int in the array that is the lowest value. 
		int i=x+1;
		while (i<windowSize){
			
			if (DataSelect[i]<DataSelect[index]){// if our checked int is less value then the current lowest value that the pointer is pointing to. 
				index=i;// Our pointer points to the current index unless a number in another index is lesser.	
			}	
			i++;
		}
		
		float tempo= DataSelect[index]; // temp is the temporary value that is the value of the lowest integer in the remaining array unchecked.
		DataSelect[index]=check;// The lowest pointer is replaced with the value that was initially  being checked. 
		DataSelect[x]=tempo;// The initially checked value is replaced with the lowest unchecked array value.
		x++;
	}
	
	float out=0;

	if(windowSize%2==0){//is an even number
	
		int one=windowSize/2;
		
		float current= DataSelect[one-1];
		
		float secondCurrent = DataSelect[one];
		
		out = (current+secondCurrent)/2;
	}
	else{
		int location= (windowSize/2);
		out =DataSelect[location];
	}
	
	median=out;
	
	return 0;	
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
	
	int size = argc-2;
	float dataset[size];
	int windowSize=atoi(argv[1]);
	int currentSample = 0;
	float min;
	float avg;
	float max;
	float smplSD;
	float median;
	
	int i=0;
	

	while (i<size){
		dataset[i]=atof(argv[i+2]);
		i++;
	}


  cout << "Sample \t Minimum \t Average \t Maximum \t Median\t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << "\t " <<"Min is:" << min << "\t " << "\t " <<"avg is:"<<  avg << "\t " << "\t "<<"Max is:"<< max << "\t " << "\t " <<"MED is:"<< median << "\t "  << "\t "<< "STD is:"<< smplSD << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }
    ++currentSample;
  }
  return 0;
  
}

#endif
