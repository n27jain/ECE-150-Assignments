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
#include <limits.h>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size){
	
	
	
	int data[size];
	
	for(int i=0; i<size;i++){
		data[i]=dataset[i];
	}
	bool goOn= sort(data,size);
	
	if (goOn){
		
		
		int out= data[size-1]-data[0];
		
		if (out<0){
			return -1;
		}
		return out;
	}
	return -1;
}
	
	
	

int mode(const int dataset[], const int size, int mode[]){

	
	int data[size];
	
	for(int i=0; i<size;i++){
		data[i]=dataset[i];
		
	}
	bool goOn= sort(data,size);
	
	if (goOn){
		
	int i=1;// starting index
	int last = data[0];// first compared value
	int numMode=0;// the number of Modes found;
	int currentCount=0;// the number of numbers found of a certain number i.e 3 when data has 7, 7, 7
	int max=0;// the mode found to contain the maximum number of reoccuring values. 
	
	int Xmode[size];
	int lastIndexOfArray=0;
		
	while (i<size){
		
		int current = data[i];
		
		if(last==current){
			
			currentCount++;
			
			
		}
		if ((i==(size-1))||(last!=current)){
			if (currentCount>max){// if our newly counted mode is greater than any in the past
				max=currentCount;// make this our new max. the old modes are erased.
				
				numMode=1;
				int q=0;
				while (Xmode[q]!=0&&q<size){ // clean the array.
					Xmode[q]=0;
					q++;
				}
				
				lastIndexOfArray=0;
				Xmode[lastIndexOfArray]=last;
				
				currentCount=0;// reset counter
				
				
			}
			else if (currentCount==max&&currentCount>1){
				numMode++;
				lastIndexOfArray++;// now our new data is added to the next index of the array because we have more than one mode. 
				Xmode[lastIndexOfArray]=last;
				currentCount=0;
			}
			else{  // when the number of items is less than another mode
				currentCount=0;
			}
		}
		
		last=current;
		i++;
	}	
	
	int tCount=0;
	
	
	while(tCount<=lastIndexOfArray){
		
		mode[tCount]=Xmode[tCount];
	
		tCount++;
	}
		
	return numMode;
	

	
	}
	else {
		return -1;
	}
}

bool selection(int dataset[],const int size){
	
	if(size <= 1)
		return true;
	int max = 0;
	for(int i = 0; i < size; i++){
		if(dataset[i] > dataset[max]){
			max = i;
		}
	}
	int tmp = dataset[max];
	dataset[max] = dataset[size-1];
	dataset[size-1] = tmp;
	return selection(dataset, size - 1);
}	




bool sort(int dataset[], const int size){
	
	if (size<=0){
		
		return false;
	}
	
	selection(dataset,size);
	
	return true;
	
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
  int data[] = { 1,1,1,2,2,2,5,5,};
  int size = 12;
  //change this to however many modes you expect to find
  int modeArray[100];
  
 
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout<<modeArray[1]<<endl;
  
 
  cout << "range: " << rng ;
cout <<"        mode:"<<modes<<endl;

  
  cout<<endl;
  
  return 0;
}

#endif
