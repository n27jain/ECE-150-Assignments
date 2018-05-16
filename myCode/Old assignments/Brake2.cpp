#include  <iostream>
#include <stdlib.h>
#include <math.h>    

using namespace std;

int main( const int argc, const char* const argv[]){

    float v1= atof(argv[1]);
	float d= atof(argv[2]);
	float max=atof(argv[3]);
	
	if(argc<4){
		cerr << "Error: Insufficient arguments; expecting more commandlines" << endl;
		return -1;
	}
	else if (argc>4){
		cerr << "Warning: Expecting three command-line arguments; received "<< argc-1 << " ; ignoring extraneous arguments." << endl;
	}
	else if(v1==0){
		cout<<"There is no possibility of collision because the car is idle."<<endl;
	}
	else if((v1<0&&d>0)||(v1>0&&d<0)){
		cout<<"There is no possibility of collision because the car is moving in the opposite direction from the object."<<endl;
	}
	else{
		float minAc=v1*v1;
		
		minAc/=2;
		minAc/=d;//minimum deceleration
		
		float time= fabs(v1/minAc);//time is positive
		
		if(fabs(max)>=fabs(minAc)){//if minimum is less than max
			cout<<"Minimum deceleration: " <<fabs(minAc)<< " m/s/s" <<endl;
			cout<<"Maximum stopping time: " <<time<< " s" <<endl;
		}
		else{
			
			float v2= sqrt(v1*v1+(2*(max)*(d)));
			float timeTillCrash= (v2-fabs(v1))/max;
			
			if (v1>0){
				cout<<"Cash will occur in "<<abs(timeTillCrash)<<" seconds at velocity "<<v2<<"; deploying airbags."<<endl;
			}
			else if (v1<0){
				cout<<"Cash will occur in "<<abs(timeTillCrash)<<" seconds at velocity "<<v2*-1<<"; deploying airbags."<<endl;
			
			}
		}
	}
    return 0;
}