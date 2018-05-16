# include <iostream>
# include <stdlib.h>

using namespace std;

float power (float base, int x){
	float out=1;
	int counter=x;
	
	while (counter>0){
		out= out*base;
		counter--;
	}
	
	return out;
}

int main( const int argc, const char* const argv[]){
	
	if(argc<4){
		cerr << "Error: Unable to compute Nth root because of insufficient arguments." << endl; 
		return -1;
	}
	else if (atoi(argv[2]) <2){
		cerr<<"Error: Unable to compute Nth root because the root is less than 2"<<endl;
		return -1;
	}
	else if (atof(argv[1])<0&&(atoi(argv[2])%2)==0){
		cerr<<"Error: Unable to compute Nth root because the number is less than 0 with an even root."<<endl; 
		return -1;
	}
	else if (atof(argv[3])<0){
		cerr<<"Error: Unable to compute Nth root because the precision is less than 0."<<endl; 
		return -1;
	}
	else if (argc>4){
		cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
	}
	else if (atof(argv[1])==0){
		cout << "Root(" << 0 << "," << atoi(argv[2]) << ") = " << 0 << endl;
		cout<<"(with precision "<<0<<" )"<<endl;
		return -1;
	}
		
		float s=atof(argv[1]);
		int n=atoi(argv[2]);
		float p=atof(argv[3]);
		float R=1;
		float done;
		float checker;

		
		do{
			int counter=n-1;
			float ReR= R; // This will be the R that is not modified.
			float fractionDone= power(R,counter);
	
			R=((n-1)*ReR/n);
			
			R= R+(s/(n*fractionDone));
			
			done=power(R,n);
		
			checker=((s-done)/s);
			
			if (checker<0)
				checker=checker*-1;
		
		}while (checker>p);
		
		cout << "Root(" << s << "," << n << ") = " << R << endl;
		
		cout<<"(with precision "<<checker<<" )"<<endl;
	
}


	
	


