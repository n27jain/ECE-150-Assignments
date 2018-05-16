#include <iostream>
#include <iomanip>
#include <stdlib.h>
  
using namespace std;

int main( const int argc, const char* const argv[]){
	float alpha;
	
	if (argc<5){
		cerr<<"Error: insufficient arguments"<<endl;
	}
	
	else if ((alpha=atof(argv[1]))>1||(alpha=atof(argv[1]))<0){
		cerr<<"Error: alpha must be a value between 0 and 1."<<endl;
	}
	else{
		const char sep = ' ';
		const int width=8;
		float alpha= atof(argv[1]);
		int limit=atoi(argv[2]);
		
		if(limit<1){
			cerr<<"Error: invalid limit."<<endl;
			return -1;
		}
		
		
		
		int counter= 3;
		int minCount=1;
		int maxCount=1;
	
		cout<<left<<setw(width)<<"Sample"<<setfill(sep);	
		cout<<left<<setw(width)<<"Value"<<setfill(sep);	
		cout<<left<<setw(width)<<"Minimum"<<setfill(sep);	
		cout<<left<<setw(width)<<"EWMA"<<setfill(sep);	
		cout<<left<<setw(width)<<"Maximum"<<setfill(sep)<<endl;	
		
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
	}
	return 0;
}