#include <math.h>
#include  <iostream>
#include <stdlib.h>


using namespace std;
	
	
	
	
void selection(int dataset[],const int size, int index){
	
		if (index==size){
			
			return;
		}
		
		int q=index+1;
		float current =dataset[index];
		int replace=0;
		bool swap=false;
		
		while(q<size){
			
			if (dataset[q]<current){
				current=dataset[q];
				replace=q;
				swap=true;
			}
			
			q++;
		}
		if (swap){
			dataset[replace]=dataset[index];
			dataset[index]=current;
			
		}
		selection(dataset,size,index+1);	
		


	}	
		
		
		
	

	int main( const int argc, const char* const argv[]) {
		
		int data [5]={1,3,2,0,2};
		int size=5;
		int index=0;
		
		selection(data,size,index);
		int i=0;
		
		while (i<size){
			cout<<data[i]<<endl;
			i++;
		}
		
		
		
		
		return 0;
	}