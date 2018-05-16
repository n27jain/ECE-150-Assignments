//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Class declaration; modify but do not remove

bool selection(int dataset[],const int size){
		if(size <= 1)
			return true;
		int max = 0;
		for(int i = 0; i < size; i++){
			if(dataset[i] > dataset[max]){
				max = i;
			}
		}
		int tmp = dataset[max];
		dataset[max] = dataset[size-1];
		dataset[size-1] = tmp;
		return selection(dataset, size - 1);
}		
	
class StudentGrades 
{
public:
    // Supported statistics
    int   minimum();
    float average();
    int   maximum();
    float popStdDev();
    float smplStdDev();
    int   numModes();
    int   mode(const int modeNumber);
    int   histogram(const int bucketNumber);

    // Populating the data and writing out results
    int  readCSV(const char filename[]);
    int  writeStats(const char filename[]);
    
    // Some supporting functions
    bool validStudentIDs(const int minAcceptableID, const int maxAcceptableID);
    int  numRejects();
    int  reject(const int rejectNumber);

    // Constructor and Destructor
    StudentGrades();
    ~StudentGrades();

private:
  Data data;
  
};


//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

int StudentGrades::minimum(int copyArray[])
{
    return copyArray[data.numStudents-1];
}

float StudentGrades::average(int dataset[], const int size)
{
int i=0;
	float totalSum=0;
	float in =0;
	
	
	while(i<size){
			
		in= dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float out= totalSum/(size);
	
	
	return out;
}

int StudentGrades::maximum()
{
    return copyArray[data.numStudents-1];
}

float StudentGrades::popStdDev(int dataset[], const int size)
{
    int i=0;
	float totalSum=0;
	float in=0;
	
	
	while(i<size){
			
		in=dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float average= totalSum/(size);
	
	float newSum=0;//reset the total sum 
	i=0; // reset i counter
	in=0;
	while(i<size){
			
		in= dataset[i];
		
		in=in-average;
		in=in*in;
		newSum=newSum+in;
		in=0;
		i++;
	}
	
	
	float psd=sqrt(newSum/(size));
	return psd;
}

float StudentGrades::smplStdDev(int dataset[], const int size)
{
	
	int i=0;
	float totalSum=0;
	float in=0;
	
	
	while(i<size){
			
		in=dataset[i];
		
		totalSum+=in;
			
		i++;
	}
	
	float average= totalSum/(size);
	
	float newSum=0;//reset the total sum 
	i=0; // reset i counter
	in=0;
	
	while(i<size){
			
		in= dataset[i];
		
		in=in-average;
		in=in*in;
		newSum=newSum+in;
		in=0;
		i++;
	}
	float ssd=sqrt(newSum/(size-1));
	return ssd;
	
    return -1;
}

int StudentGrades::numModes()
{
    return -1;
}

int StudentGrades::mode(const int modeNumber)
{
    return -1;
}

int StudentGrades::histogram(const int bucketNumber)
{
    return -1;
}

int StudentGrades::readCSV(const char filename[])
{
    return -1;
}

int StudentGrades::writeStats(const char filename[])
{
    return -1;
}

bool StudentGrades::validStudentIDs(const int minAcceptableID, const int maxAcceptableID)
{
    return false;
}

int StudentGrades::numRejects()
{
    return -1;
}

int StudentGrades::reject(const int rejectNumber)
{
    return -1;
}

StudentGrades::StudentGrades()
{

}

StudentGrades::~StudentGrades()
{
    //Please clean up
}
		

#ifndef MARMOSET_TESTING
int main(const int argc, const char* const args[]) 
{

    StudentGrades grades;
    //formatting
    cout << endl;

    if (!grades.readCSV(args[1]))
    {
        cout << "CSV read success" << endl;

    } 
    else
    {
        cout << "CSV read fail" << endl;
    }

    cout << "Min: " << grades.minimum() << endl;
    cout << "Max: " << grades.maximum() << endl;

    if (!grades.writeStats(args[1]))
    {
        cout << "Stats write success" << endl;

    } 
    else
    {
        cout << "Stats write fail" << endl;
    }
    //formatting
    cout << endl;

    return 0;

  
}
#endif
