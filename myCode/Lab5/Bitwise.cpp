#include <math.h>
#include  <iostream>
#include <stdlib.h>


using namespace std;


	int main( const int argc, const char* const argv[]) {
		
		
	int dataset[28]={1,1,2,2,2,3,7,7,7,11,11,11,13,13,15,15,17,17,19,20,1,2,8,8,8,8,8,1};

	int size=28;
	
	
	int i=1;// starting index
	int last = dataset[0];// first compared value
	int numMode=0;// the number of Modes found;
	int currentCount=0;// the number of numbers found of a certain number i.e 3 when data has 7, 7, 7
	int max=0;// the mode found to contain the maximum number of reoccuring values. 
	
	int Xmode[size];
	int lastIndexOfArray=0;
		
	while (i<size){
		
		int current = dataset[i];
		
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
			else if (currentCount==max){
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
	int mode[lastIndexOfArray+1];
	
	while(tCount<=lastIndexOfArray){
		
		mode[tCount]=Xmode[tCount];
		cout<<mode[tCount]<<endl;
		tCount++;
	}
		
	
	cout<<"   "<<endl;
	cout<<numMode<<endl;
	
	
	
	
	return 0;
	}