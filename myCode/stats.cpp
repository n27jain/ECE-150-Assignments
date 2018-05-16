#include <iostream>
#include <iomanip>
#include <stdlib.h>
  
using namespace std;

int main( const int argc, const char* const argv[]){
	
	
	if (argc<5){
		cerr<<"Error: insufficient arguments"<<endl;
	}
	else{
		const char sep = ' ';
		const int width=8;
		float alpha= atof(argv[1]);

		cout<<left<<setw(width)<<"Sample"<<setfill(sep);	
		cout<<left<<setw(width)<<"Value"<<setfill(sep);	
		cout<<left<<setw(width)<<"Minimum"<<setfill(sep);	
		cout<<left<<setw(width)<<"EWMA"<<setfill(sep);	
		cout<<left<<setw(width)<<"Maximum"<<setfill(sep)<<endl;	
		
		int counter=0;
		int location =2;
		int sample=1;
		
		float min= atoi(argv[2]);
		float max= atoi(argv[2]);
		float totalSum=0;
		float average=0;
		
		int windowSize=atoi(argv[1]);
		
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
		
		
		
		/*
		cout<<left<<setw(width)<<1<<setfill(sep);	
		cout<<left<<setw(width)<<atof(argv[counter])<<setfill(sep);	
		cout<<left<<setw(width)<<atof(argv[counter])<<setfill(sep);	
		cout<<left<<setw(width)<<atof(argv[counter])<<setfill(sep);	
		cout<<left<<setw(width)<<atof(argv[counter])<<setfill(sep)<<endl;	
		
		float max=atof(argv[counter]);
		float min=atof(argv[counter]);
		float totalSum=atof(argv[counter]);	
		
		while(counter<=argc){
			float in= atof(argv[counter+1]);
			totalSum= alpha*in+(1-alpha)*(totalSum);
			if(max<in){
				maxCount=0;
				max=in;
			}
			if(min>in){
				minCount=0;
				min=in;
			}
			if(minCount==limit){
				min=in;	
			}
			if(maxCount==limit){
				max=in;	
			}
			cout<<left<<setw(width)<<counter-1<<setfill(sep);	
			cout<<left<<setw(width)<<in<<setfill(sep);	
			cout<<left<<setw(width)<<min<<setfill(sep);	
			cout<<left<<setw(width)<<totalSum<<setfill(sep);	
			cout<<left<<setw(width)<<max<<setfill(sep)<<endl;	
			counter++;	
			maxCount++;
			minCount++;
		}
		*/
	}
	return 0;
}