#include  <iostream>
#include <stdlib.h>
#include <math.h>    

using namespace std;

int main( const int argc, const char* const argv[]){
	if(argc <4){
		cerr << "Error: Insufficient arguments; expecting 3 arguements." << endl;
		return -1;
	}
	else if (argc>4){
		cerr << "Warning: Expecting three command-line arguments; received "<<argc-1<<" ; ignoring extraneous arguments." << endl;
	}
		
	float v1= atof(argv[1]);
	float d= atof(argv[2]);
	float max=atof(argv[3]);
	
	if(max<0){
		cerr<< "Error: Deceleration is negative." << endl;
		return -1;
	}
	
	if(v1==0){
		cout<<"There is no possibility of collision because the car is idle."<<endl;
	}
	else if((v1<0&&d>0)||(v1>0&&d<0)){
		cout<<"There is no possibility of collision because the car is moving away from the object."<<endl;
	}
	else {
		float minAc=v1*v1;
		minAc/=2;
		minAc/=d;//minimum deceleration--------------------------
		
		float time= fabs(v1/minAc);//time is positive------------------------------
		
		if(max>=minAc){//if minimum is less than max
			cout<<"Minimum deceleration: " <<fabs(minAc)<< " m/s/s" <<endl;
			cout<<"Maximum stopping time: " <<time<< " s" <<endl;
		}
		else{
			if (v1>0){
				float v2= sqrt(v1*v1-(2*(max)*(d)));
				float timeTillCrash= (v2-fabs(v1))/max;
				cout<<"Crash will occur in "<<abs(timeTillCrash)<<" seconds at velocity "<<v2<<" m/s; deploying airbags."<<endl;
			}
			else if (v1<0){
				float v2= sqrt(v1*v1+(2*(max)*(d)));
				float timeTillCrash= (v2-fabs(v1))/max;
				cout<<"Crash will occur in "<<abs(timeTillCrash)<<" seconds at velocity "<<v2*-1<<" m/s; deploying airbags."<<endl;
			}
		}
	}		
	return -1;
}