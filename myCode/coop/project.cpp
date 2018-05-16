//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
#include <stdlib.h>
#include<limits.h>
#include <math.h>
using namespace std;
#include <iostream>
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING





#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING
struct Student{
	int studentID=0;
	int grade=0;
};

struct Dataset{
	int numStudents=0;
	Student* students;
};

struct Rejects{
	int numRejects=0;
	int* rejects;
};

struct Mode{
	int numModes=0;
	int* modes;
};

struct Statistics{
	int   minimum=0;
	float average=0;
	int   maximum=0;
	float popStdDev=0;
	float smplStdDev=0;
	Mode  mode;
	int   histogram[10]={0,0,0,0,0,0,0,0,0,0};
};
#endif
//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[],const int minAcceptableID, 
				const int maxAcceptableID,Dataset& data, 
				Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//


int parseLine(const char line[],int min ,int max, int lineNumber, int & grade, int & id){
	
	
	int i=0;
	
	bool error=false;// this bool will be true once we have successfully checked the string.
	bool present1=false;
	bool present2=false;
	id=0;
	grade=0;
	
	if (line[i]==','){
		return 0;
	
	}
	while (line[i]!=',' && error!=true){
		
		if(i==0&&(line[i]==' '||line[i]=='\t')){
			// do nothing
			
		}
		
		else if ((line[i]==' '||line[i]=='\t')&&((!(line[i-1]>=48&&line[i-1]<=59))||(!(line[i+1]>=48&&line[i+1]<=59)))){
			//do nothing
		}
		else if (line[i]>=48&&line[i]<=59){
			
			int current =line[i]-48;
			id=id*10+current;
			present1=true;
		}
		else{
			error=true;
		}
		
		i++;
	}
	int a=0;
	i++;
	while (line[i]!='\0' && error!=true){// we look at the grade now
	
		if(a==0&&(line[i]==' '||line[i]=='\t')){
			// do nothing
			
		}
		else if ((line[i]==' '||line[i]=='\t')&&((!(line[i-1]>=48&&line[i-1]<=59))||(!(line[i+1]>=48&&line[i+1]<=59)))){
			//do nothing
		}
		
		
		//
		//if((line[i]==' '|| line[i]=='\t') &&((line[i-1]>=48&&line[i-1]<=59)&&(line[i+1]>=48&&line[i+1]-1<=59))){
		//	return 0;
		//}
		else if (line[i]>=48&&line[i]<=59){
			
			present2=true;
			int current =line[i]-48;
			grade=grade*10+current;
		}
		
		else{
			return 0;
		}
		
		
		i++;
		a++;
	}
	
	if ((id<min||id>max)||(grade<0||grade>100)||error||(!present1)||(!present2)){
		
		
		return 0;
	}
	else{
	
	return 1;
	}

}


int readCSV(const char filename[],const int minAcceptableID, const int maxAcceptableID,  Dataset& data, Rejects& rejects){

		int xy=0;
		int point=0;
		int decimalLocation=0;
		char check[3];
		bool extensionMod=false;
		
		if(filename == NULL){
			return -1;
		}
		
		while (filename[xy]!='\0'){
			if(filename[xy]=='.'){
				point++;
				decimalLocation=xy;
			}
			if(point>1){
				
				return -1;
			}
			xy++;// number of stored value
		
		}
		
		int que= xy+5; // out new char array will have a null and 4 extra chars
		char newRead[que];
		int a=0;
		
		if (point==0){
			
			while (filename[a]!='\0'){
				
				newRead[a]=filename[a];
				a++;
				
			}
			newRead[que-1]='\0';
			newRead[que-2]='v';
			newRead[que-3]='s';
			newRead[que-4]='c';
			newRead[que-5]='.';
			extensionMod=true;
		}
		else if (point==1){
			int decide= xy-decimalLocation;
			
			if(decide==4){// there are 4 chars after the decimal and including the decimal
				if(filename[xy-3]=='c'&&filename[xy-2]=='v'&&filename[xy-1]=='c'){
					
				}
			}
			else{
			
				return -1;
			}
		}
		
				
					
		if (minAcceptableID>maxAcceptableID){
		
			return -1;
		}
		data.numStudents=0;
		rejects.numRejects=0;
		
		bool errorCheck=false;  // we trigger this if we get a single wrong entry
		int index=0;
		
		int min=minAcceptableID;
		int max= maxAcceptableID;
		
		const int maxLineLength=100;
		char line[maxLineLength];
		
		ifstream infile;
		
		
		if(extensionMod){
			infile.open(newRead);
		}
		
		else{
			infile.open(filename);
		}
		
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
				int id=0;
			
				int parse= parseLine(line,min, max, fileLineNumber, grade,id );
			
				if (parse==0){
					
					int file= fileLineNumber;
					
					if(rejects.numRejects==10){
							return -1;
						}
					
					if(rejects.numRejects==0){
						
						rejects.numRejects++;
						
						
						int * temp= new int [rejects.numRejects];
						temp[0]= fileLineNumber;
						delete[] rejects.rejects;
						rejects.rejects= temp;
						
					}
					else{
						int *temp= new int [rejects.numRejects+1];
						for(int i=0; i<rejects.numRejects;i++){
							temp[i]= rejects.rejects[i];
						}
						
						temp[rejects.numRejects]= file;
						delete[] rejects.rejects;
						rejects.rejects= temp;
						rejects.numRejects++;
					}
				
					errorCheck=true;
					
				}
				else if (parse==1) {
					
					Student newStudent;
					newStudent.studentID=id;
					
					newStudent.grade=grade;
					
					if (data.numStudents==0){
						data.students= new Student;
						*data.students= newStudent;
						data.numStudents++;
					}
					else{
						
						Student * temp =new Student[data.numStudents+1];
						
						for(int i=0; i<data.numStudents;i++){
							temp[i]=data.students[i];
						}
						
						temp[data.numStudents]=newStudent;
						
						delete[] data.students;
						data.students=temp;
						data.numStudents++;
					}
				}
			}
		}
		
		Statistics stats;
		Mode mode;
		
		int decide= computeStatistics(data, stats);
		
		if(errorCheck){
			return 1;
		}
		
		
				
				
	return 0;
}

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
	
float average(int dataset[], const int size) {
	
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

float popStdDev(int dataset[], const int size) {
	
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

float smplStdDev(int dataset[], const int size) {
	
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
	
}

int WorkMode(const int dataset[], Mode & mode, const int size ){


		
	int i=1;// starting index
	int last = dataset[0];// first compared value
	int numMode=0;// the number of Modes found;
	int currentCount=0;// the number of numbers found of a certain number i.e 3 when data has 7, 7, 7
	int max=0;// the mode found to contain the maximum number of reoccuring values. 
	
	int Xmode[size];
	int lastIndexOfArray=0;
	
	bool discover=false;
	int z=0;
	
	
	
	while (z<size-1){
		if(dataset[z]==dataset[z+1]){
			discover=true;
		}
		z++;
	}
	if(discover){	
		while (i<size){
			
			int current = dataset[i];
			
			if(last==current){
				
				currentCount++;
				
				
			}
			if ((i==(size-1))||(last!=current)){
				if (currentCount>max){// if our newly counted mode is greater than any in the past
					max=currentCount;// make this our new max. the old modes are erased.
					
					
					int q=0;
					
					while (Xmode[q]!=0&&q<size){ // clean the array.
						Xmode[q]=0;
						q++;
					}
					
					lastIndexOfArray=0;
					Xmode[lastIndexOfArray]=last;
					
					currentCount=0;// reset counter
					
					
				}
				else if (currentCount==max){
					numMode++;
					lastIndexOfArray++;// now our new data is added to the next index of the array because we have more than one mode. 
					Xmode[lastIndexOfArray]=last;
					currentCount=0;
				}
				else{  // when the number of items is less than another mode
					currentCount=0;
				}
			}
			
			last=current;
			i++;
		}
	
		
		int tCount=0;
		
		int * NewModes = new int[lastIndexOfArray+1];
		
		
		while(tCount<lastIndexOfArray+1){
			
			NewModes[tCount]=Xmode[tCount];
			tCount++;
		}
		mode.modes=NewModes;
		mode.numModes= lastIndexOfArray+1;
	}
	
	else {
		
		int * NewModes= new int[size];
		
		for(int q=0; q<size; q++){
			NewModes[q]=dataset[q];
		}
		
		mode.modes=NewModes;
		mode.numModes=size;
		
	}
	return numMode;
	
}

int computeStatistics(Dataset& data, Statistics& stats){
	//Your code here ...
	
	
	int copyArray[data.numStudents];
	
	if(data.numStudents<2){
		return -1;
	}
	
	
	for (int i=0; i<data.numStudents;i++){
		Student check= data.students[i];
		copyArray[i]=check.grade;
		
	}
	selection(copyArray, data.numStudents);
	
	stats.minimum= copyArray[0];
	stats.maximum= copyArray[data.numStudents-1];
	stats.average= average(copyArray,data.numStudents);
	stats.popStdDev=popStdDev(copyArray,data.numStudents);
	stats.smplStdDev=smplStdDev(copyArray,data.numStudents);
	
	
	for(int i=0; i<10;i++){
	
		stats.histogram[i]=0;
	}
	for (int i=0;i<data.numStudents;i++){
		int compute= copyArray[i];
		int location=compute/10;
		if (compute==100){
			stats.histogram[9]++; 
		}
		else{
		stats.histogram[location]++; 
		}
	}
	Mode newMode;// create a new mode struct

	stats.mode= newMode;// put it into our stats struct
	
	
	int superMode= WorkMode(copyArray, stats.mode, data.numStudents);
	
	if (data.numStudents==1){
		return 1;
	}
	
	return 0;
	
	
}

int writeCSV(const char filename[], const Statistics& stats){
	//Your code here ...
	
	if(filename == NULL){
		return -1;
	}
	ofstream outfile;
	
	int xy=0;
		int point=0;
		int decimalLocation=0;
		char check[3];
		bool extensionMod=false;
		
		while (filename[xy]!='\0'){
			if(filename[xy]=='.'){
				point++;
				decimalLocation=xy;
			}
			if(point>1){
				
				return -1;
			}
			xy++;// number of stored value
		
		}
		
		int que= xy+5; // out new char array will have a null and 4 extra chars
		char newRead[que];
		int a=0;
		
		if (point==0){
			
			while (filename[a]!='\0'){
				
				newRead[a]=filename[a];
				a++;
				
			}
			newRead[que-1]='\0';
			newRead[que-2]='v';
			newRead[que-3]='s';
			newRead[que-4]='c';
			newRead[que-5]='.';
			extensionMod=true;
		}
		else if (point==1){
			int decide= xy-decimalLocation;
			
			if(decide==4){// there are 4 chars after the decimal and including the decimal
				if(filename[xy-3]=='c'&&filename[xy-2]=='v'&&filename[xy-1]=='c'){
					
				}
			}
			else{
			
				return -1;
			}
		}
	
	if(extensionMod){
		int i=0;
	
		while(newRead[i]!='\0'){
			
			i++;
		}
		
		char out[i+2];
		
		for (int q=0; q<i-1; q++){
			
			out[q]=newRead[q];
			
		}
		out[i+1] = '\0';
		out[i]='t';
		out[i-1]='a';
		out[i-2]='t';
		out[i-3]='s';
		outfile.open(out);
			
	}
	else{
		int i=0;

		while(filename[i]!='\0'){
			
			i++;
		}

		char out[i+2];

		for (int q=0; q<i-1; q++){
			
			out[q]=filename[q];
			
		}
		out[i+1] = '\0';
		out[i]='t';
		out[i-1]='a';
		out[i-2]='t';
		out[i-3]='s';
		outfile.open(out);
	}
	
	if(!outfile.is_open())
		return -1;
	outfile<<"Minimum: ";
	outfile<<stats.minimum<<endl;
	
	outfile<<"Average: ";
	outfile<<stats.average<<endl;
	
	outfile<<"Maximum: ";
	outfile<<stats.maximum<<endl;
	
	outfile<<"Population Standard Deviation: ";
	outfile<<stats.popStdDev<<endl;
	
	outfile<<"Sample Standard Deviation: ";
	outfile<<stats.smplStdDev<<endl;
	
	
	outfile<<"Modes: ";
	
	int exit= (stats.mode.numModes);
	int z=0;
	
	while ( z < exit){
		if( z!=exit-1){
			outfile<<stats.mode.modes[z]<<", ";
		}
		else {
			outfile<<stats.mode.modes[z]<<endl;
		}
		z++;
	}
	
	
	//outfile<<"Modes: ";
	//outfile<<stats.minimum<<endl;
	
	outfile<<"Histogram:"<<endl;
	
	outfile<<"[0-9]: "<<stats.histogram[0]<<endl;
	outfile<<"[10-19]: "<<stats.histogram[1]<<endl;
	outfile<<"[20-29]: "<<stats.histogram[2]<<endl;
	outfile<<"[30-39]: "<<stats.histogram[3]<<endl;
	outfile<<"[40-49]: "<<stats.histogram[4]<<endl;
	outfile<<"[50-59]: "<<stats.histogram[5]<<endl;
	outfile<<"[60-69]: "<<stats.histogram[6]<<endl;
	outfile<<"[70-79]: "<<stats.histogram[7]<<endl;
	outfile<<"[80-89]: "<<stats.histogram[8]<<endl;
	outfile<<"[90-100]: "<<stats.histogram[9]<<endl;
	
	
	
	
	
	return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  	
	
	
	
		// Some test driver code here ....
	int minAcceptableID = 0;
	int maxAcceptableID = 2000000;

	Dataset data = {0};
	Rejects rejects = {0};
	Statistics stats = {0};

	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	if(readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) < 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}

	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}

	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;
	
	
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
	}

	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout << "Histogram bin [" << (i*10) << ", " << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}
	
	for(int i=0; i<rejects.numRejects;i++){
		cout<<rejects.rejects[i]<<endl;
	}
	
	return 0;
}

#endif
