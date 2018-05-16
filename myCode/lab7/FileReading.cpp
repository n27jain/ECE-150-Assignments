//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<limits.h>
#include <math.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

using namespace std;

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//
int parseLine(const char line[],int min ,int max, int lineNumber, int & grade){
	

	int i=0;
	
	bool error=false;// this bool will be true once we have successfully checked the string.
	
	int id=0;
	grade=0;
	
	while (line[i]!=',' && error!=true){
		
		if (line[i]==' '||line[i]=='	'){
			//do nothing
		}
		else if (line[i]>=48&&line[i]<=59){
			
			int current =line[i]-48;
			id=id*10+current;
			
		}
		else{
			error=true;
		}
		
		i++;
	}
	while (line[i]!='\0' && error!=true){// we look at the grade now
	
		if (line[i]==' '||line[i]=='	'){
			//do nothing
		}
		else if (line[i]>=48&&line[i]<=59){
			
			int current =line[i]-48;
			grade=grade*10+current;
		}
		else{
	
			error==true;
		}
	
		i++;
	}
	if (error){
		return -1;
		
	}
	else if ((id<min||id>max)||(grade<0||grade>100)){
		return 0;
	}

	
	
	return 1;

}




int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects) {
	
	if (minAcceptableID>maxAcceptableID||histogram==NULL){
		
		return -1;
	}			  
	rejects= new int [100];
	
	for (int q=0; q<10;q++){
		histogram[q]=0;
	}
	
	
		
	bool errorCheck=false;  // we trigger this if we get a single wrong entry
	int index=0;
	
	int min=minAcceptableID;
	int max= maxAcceptableID;
	
	const int maxLineLength=100;
	char line[maxLineLength];
	
	ifstream infile;
	
	//const char fileName[];
	
	infile.open(filename);
	
	
	if (!infile.is_open()){
		return -1;
	}
	bool done=false;
	int fileLineNumber=0;
	int counter=0;
	
	while(!done){
		++fileLineNumber;
		
		if (!infile.getline(line, maxLineLength)){
			if(infile.eof()){
				done=true;
			}
			else {
				return-1;
			}
		}
		else{
			int grade=0;
		
			int parse= parseLine(line,min, max, fileLineNumber, grade );
		
			if (parse==0){
				
				rejects[index]=fileLineNumber;
				errorCheck=true;
				index++;
			}
			else if (parse==-1){
				
				return -1;
			}
			else {
				
				int location=grade/10;
				histogram[location]++; 
			}
		}
	}

	if (errorCheck){
		
		return index;
	}
	else {
		return 0;
	}
	

	

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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else {
    for (int i = 0; i < numBuckets; ++i)
      if (i != numBuckets-1)
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
      else
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
    if (retCode > 0) {
      cout << "Number of rejected records: " << retCode << endl;
      cout << "Rejected records are:";
      for (int i = 0; i < retCode; ++i)
	cout << " " << rejectedRecords[i];
      cout << endl;
      delete[] rejectedRecords;
    }
  }

  return 0;
}

#endif
