#include <iostream>
#include <iomanip>
#include <stdlib.h>
  
using namespace std;

int main( const int argc, const char* const argv[]){
	int windowSize;
	bool change=false;
	
	if (argc<3){
		cerr<<"Error: Unable to compute statistics over data set because of insufficient arguements."<<endl;
		return -1;
	}
	
	else if(atoi(argv[1])<1){
		cerr<<"Error: Unable to compute statistics over data set due to non-positive window size."<<endl;
		return -1;
	}
	else if(atoi(argv[1])>argc-2){
		cerr<<"Warning: Window size is is greater than the number of set of data; making window size."<<endl;
		windowSize=argc-2;
		change=true;
		
	}
	else if (atoi(argv[1])==1){
		cerr<<"Warning: Window size is 1; therefore no change."<<endl;
	}
	
		const char sep = ' ';
		const int width=10;
		float alpha= atof(argv[1]);
		if (change==false){
			windowSize=atoi(argv[1]);
		}
		cout<<"Window Size: "<<windowSize<<endl;
		cout<<left<<setw(width)<<"Sample"<<setfill(sep);	
		cout<<left<<setw(width)<<"Value"<<setfill(sep);	
		cout<<left<<setw(width)<<"SWMinimum"<<setfill(sep);	
		cout<<left<<setw(width)<<"SWAverage"<<setfill(sep);	
		cout<<left<<setw(width)<<"SWMaximum"<<setfill(sep)<<endl;	
		
		int counter=0;
		int location =2;
		int sample=1;
		
		float min= atoi(argv[2]);
		float max= atoi(argv[2]);
		float totalSum=0;
		float average=0;
		
		
		
		while (counter<windowSize){
			
			float current= atof(argv[location]);
				
				if(current<min){
					min=current;
				}
				if (current>max){
					max=current;
				}
				
				totalSum+=current;
			
				average=totalSum/(sample);
			
			
				cout<<left<<setw(width)<<sample<<setfill(sep);	
				cout<<left<<setw(width)<<current<<setfill(sep);	
				cout<<left<<setw(width)<<min<<setfill(sep);	
				cout<<left<<setw(width)<<average<<setfill(sep);	
				cout<<left<<setw(width)<<max<<setfill(sep)<<endl;
				counter++;
				sample++;
				location++;
		}
		
		while (location<=argc-1){
			
			float current2;
			counter=0;
			
			counter=location-windowSize+1;
			
			min= atoi(argv[counter]);
			max= atoi(argv[counter]);
			totalSum=0;
			average=0;
			
			while(counter<=location){
				current2= atof(argv[counter]);
				
				if(current2<min){
					min=current2;
				}
				if (current2>max){
					max=current2;
				}
				
				totalSum+=current2;
				counter++;
			}
			average=totalSum/windowSize;
			
			cout<<left<<setw(width)<<sample<<setfill(sep);	
			cout<<left<<setw(width)<<current2<<setfill(sep);	
			cout<<left<<setw(width)<<min<<setfill(sep);	
			cout<<left<<setw(width)<<average<<setfill(sep);	
			cout<<left<<setw(width)<<max<<setfill(sep)<<endl;
			
			location++;
			sample++;
		
		
		}
		
	
	return 0;
}