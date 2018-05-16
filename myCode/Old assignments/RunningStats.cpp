#include <iostream>
#include <iomanip>
#include <stdlib.h>
  
using namespace std;

int main( const int argc, const char* const argv[]){
	
	const char sep = ' ';
	const int width=8;
	int counter= 1;
	
	
	if (argc<3){
		cerr<<"Unable to compute statistics over data set because there are less then 2 arguments. "<<endl;
	}
	
	else{
	
		cout<<left<<setw(width)<<"Sample"<<setfill(sep);	
		cout<<left<<setw(width)<<"Value"<<setfill(sep);	
		cout<<left<<setw(width)<<"Minimum"<<setfill(sep);	
		cout<<left<<setw(width)<<"Average"<<setfill(sep);	
		cout<<left<<setw(width)<<"Maximum"<<setfill(sep)<<endl;	
			
		
		float totalSum;
		float max=atof(argv[counter]);
		float min=atof(argv[counter]);
		
		
		while(counter<argc){
				
			float in= atof(argv[counter]);
			
				totalSum+=in;
				float average= totalSum/(counter);
		
				if(max<in)
					max=in;
				
				if(min>in)
					min=in;
				
			cout<<left<<setw(width)<<counter<<setfill(sep);	
			cout<<left<<setw(width)<<in<<setfill(sep);	
			cout<<left<<setw(width)<<min<<setfill(sep);	
			cout<<left<<setw(width)<<average<<setfill(sep);	
			cout<<left<<setw(width)<<max<<setfill(sep)<<endl;	
			counter++;	
			
		}
		
	
		
	
	}
	return 0;
	
}